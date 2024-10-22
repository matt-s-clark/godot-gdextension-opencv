extends Control

@onready var video_feed = %VideoFeed
@onready var video_feed_2 = %VideoFeed2
@onready var video_feed_3 = %VideoFeed3
@onready var video_feed_4 = %VideoFeed4

@onready var thresh_value_container = $Interface/ThreshValueContainer

var cap:CVVideoCapture
var thresh := 120
var kernel_size := 5 
var kernel2_size := 5 
var use_adaptative := false

func _ready():
	cap = CVVideoCapture.new()
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)


func _process(_delta):
	if !cap.is_opened():
		return
		
	var mat = cap.read()
	if mat.cols <= 0:
		return
		
	var gray := CVImgProc.cvt_color(mat, CVConsts.ColorConversionCodes.COLOR_BGR2GRAY, {})
	gray = CVImgProc.gaussian_blur(gray, Vector2(3, 3), 0, {})
	
	var thRes = CVImgProc.threshold(gray, thresh, 255, CVConsts.ThresholdTypes.THRESH_BINARY_INV)
	var binaryImage : CVMat = thRes["dst"]
	
	var kernel = CVImgProc.get_structuring_element(CVConsts.MorphShapes.MORPH_ELLIPSE, Vector2(kernel2_size, kernel2_size), {})
	var processedBinary := CVImgProc.morphology_ex(binaryImage, CVConsts.MorphTypes.MORPH_OPEN, kernel, {})
	
	var result := CVImgProc.find_contours(processedBinary, 2, 1,{})
	var contoursDraw := mat.copy()
	var contoursColor := mat.copy()
	CVImgProc.draw_contours(contoursDraw, result["contours"], -1, CVScalar.create(Vector3(0,255,0)), {"thickness": 3})
	
	var maxArea := -1.0
	var areas := []
	for con in result["contours"]:
		var m = CVImgProc.moments(con, {})
		var area = CVImgProc.contour_area(con, {})
		var centroid = Vector2i(m.m10/m.m00, m.m01/m.m00)
		if area > maxArea and area > 0:
			maxArea = area
			areas.push_back([con, area, centroid])
	
	areas.sort_custom(func(a, b): return a[1] > b[1])
	
	if maxArea > 0:
		for i in range(areas.size()):
			var data = areas[i]
			var color := Color.from_hsv((i+0.0)/areas.size(), 1, 1)
			
			CVImgProc.draw_contours(contoursColor, [data[0]], -1, CVScalar.create(color), {"thickness": 3})
			CVImgProc.put_text(contoursColor, str(int(data[1]/1000), " Kp"), data[2], 0, 1, CVScalar.create(color), {})
	
	##print(maxArea)
	
	video_feed.texture = mat.get_texture()
	video_feed_2.texture = processedBinary.get_texture()
	video_feed_3.texture = contoursDraw.get_texture()
	video_feed_4.texture = contoursColor.get_texture()


func _on_thresh_value_value_changed(value):
	thresh = value


func _on_kernel_size_value_value_changed(value):
	kernel_size = value


func _on_kernel_size_value_2_value_changed(value):
	kernel2_size = value


func _on_use_adaptative_toggled(toggled_on):
	use_adaptative = toggled_on
	thresh_value_container.visible = !toggled_on


func _on_open_pressed():
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)


func _on_release_pressed():
	cap.release()
