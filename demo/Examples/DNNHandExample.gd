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
	if cap.is_opened():
		var mat = cap.read()
		if mat.cols > 0:
			var rmat := CVImgProc.resize(mat, Vector2(192, 192), {})
			rmat = CVImgProc.cvt_color(rmat, CVConsts.ColorConversionCodes.COLOR_BGR2RGB,{})
			
			var blob := CVDnn.blobFromImage(rmat, {})
			palm_detector.setInput(blob, {})
			
			var a := palm_detector.forward()
			
			print(a)
			
			var tex: ImageTexture = ImageTexture.create_from_image(mat.get_image())
			video_feed.texture = tex

func _on_open_pressed():
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)

func _on_release_pressed():
	cap.release()
