extends Control

@onready var video_feed = %VideoFeed

var cap:CVVideoCapture
var detector:CVFaceDetectorYN

func _ready():
	cap = CVVideoCapture.new()
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)
	var mat := cap.read()
	
	detector = CVFaceDetectorYN.create("./face_detection_yunet_2023mar.onnx", "", Vector2(mat.cols,mat.rows), {})


func _process(_delta):
	if cap.is_opened():
		var mat := cap.read()
		if mat.cols > 0:
			var result := detector.detect_simplified(mat)
			
			print(result)
			for i in result:
				CVImgProc.rectangle(mat, {"rec": i["rect"]})
				CVImgProc.rectangle(mat, {"pt1": i["right_eye"], "pt2": i["left_eye"], "color":Color.CRIMSON})
				CVImgProc.rectangle(mat, {"pt1": i["right_mouth"], "pt2": i["left_mouth"], "color":Color.REBECCA_PURPLE})
				
			var tex: ImageTexture = ImageTexture.create_from_image(mat.get_image())
			video_feed.texture = tex

func _on_open_pressed():
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)

func _on_release_pressed():
	cap.release()
