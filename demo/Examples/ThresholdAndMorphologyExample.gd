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
	var th : CVMat
	
	if use_adaptative:
		th = CVImgProc.adaptive_threshold(gray, 255, CVConsts.ThresholdTypes.THRESH_BINARY_INV, CVConsts.AdaptiveThresholdTypes.ADAPTIVE_THRESH_GAUSSIAN_C, 301, 2)
	else:
		var result = CVImgProc.threshold(gray, thresh, 255, CVConsts.ThresholdTypes.THRESH_BINARY_INV)
		th = result["dst"]
	
	var kernel2 = CVImgProc.get_structuring_element(CVConsts.MorphShapes.MORPH_CROSS, Vector2(kernel2_size, kernel2_size), {})
	var cl := CVImgProc.morphology_ex(th, CVConsts.MorphTypes.MORPH_CLOSE, kernel2, {})
	var kernel = CVImgProc.get_structuring_element(CVConsts.MorphShapes.MORPH_ELLIPSE, Vector2(kernel_size, kernel_size), {})
	var gr := CVImgProc.morphology_ex(cl, CVConsts.MorphTypes.MORPH_GRADIENT, kernel, {})
	video_feed.texture = mat.get_texture()
	video_feed_2.texture = th.get_texture()
	video_feed_3.texture = cl.get_texture()
	video_feed_4.texture = gr.get_texture()


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
