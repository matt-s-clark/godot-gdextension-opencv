extends Control

@onready var video_feed = %VideoFeed

var cap:CVVideoCapture
var palm_detector: CVNet
var pose_estimator: CVNet

func _ready():
	cap = CVVideoCapture.new()
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)
	
	palm_detector = CVDnn.readNet("./Models/palm_detection_mediapipe_2023feb.onnx", {})
	pose_estimator = CVDnn.readNet("./Models/handpose_estimation_mediapipe_2023feb.onnx", {})

func _process(_delta):
	if !cap.is_opened():
		return
		
	var mat = cap.read()
	if mat.cols <= 0:
		return
		
	var rmat := CVImgProc.resize(mat, Vector2(192, 192), {})
	rmat = CVImgProc.cvt_color(rmat, CVConsts.ColorConversionCodes.COLOR_BGR2RGB,{})
	
	var blob := CVDnn.blobFromImage(rmat, {})
	palm_detector.setInput(blob, {})
	
	var a := palm_detector.forward()
	
	print(a)
	
	video_feed.texture = mat.get_texture()

func _on_open_pressed():
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)

func _on_release_pressed():
	cap.release()
