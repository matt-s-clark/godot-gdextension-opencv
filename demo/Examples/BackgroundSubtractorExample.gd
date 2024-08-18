extends Control

@onready var video_feed = %VideoFeed

var cap:CVVideoCapture
var subtractorknn:CVBackgroundSubtractorKNN
var subtractormog2:CVBackgroundSubtractorMOG2

var calculate_background := false
var use_knn := false
var see_background := false

func _ready():
	cap = CVVideoCapture.new()
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)
	
	subtractorknn = CVBackgroundSubtractorKNN.create({})
	subtractormog2 = CVBackgroundSubtractorMOG2.create({})
	
	if !cap.is_opened():
		return
	
	var mat = cap.read()
	
	if mat.cols == 0:
		return
	
	subtractorknn.apply(mat, {})
	subtractormog2.apply(mat, {})

func _process(_delta):
	if !cap.is_opened():
		return
		
	var mat = cap.read()
	if mat.cols <= 0:
		return
	
	var subtractor
	var out : CVMat
	
	if use_knn:
		subtractor = subtractorknn
	else:
		subtractor = subtractormog2
	
	if calculate_background:
		var a = subtractor.apply(mat, {})
	
	if see_background:
		out = subtractor.get_background_image()
	else:
		var sub := CVCore.subtract(mat, subtractor.get_background_image(), {})
		var mask := CVImgProc.threshold(sub, 20, 255, CVConsts.ThresholdTypes.THRESH_BINARY_INV)
		var kernel:CVMat = CVImgProc.get_structuring_element(CVConsts.MorphShapes.MORPH_ELLIPSE, Vector2(15, 15), {})
		
		CVImgProc.morphology_ex(mask["dst"], CVConsts.MorphTypes.MORPH_GRADIENT, kernel, {"interactions":5})
		out = CVCore.bitwise_and(mat, mask["dst"], {})
		
	video_feed.texture = out.get_texture()

func _on_open_pressed():
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)

func _on_release_pressed():
	cap.release()


func _on_use_knn_toggled(toggled_on):
	use_knn = toggled_on


func _on_see_background_toggled(toggled_on):
	see_background = toggled_on


func _on_calculate_background_toggled(toggled_on):
	calculate_background = toggled_on
