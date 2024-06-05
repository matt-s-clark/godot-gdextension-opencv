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
			var result := detector.detect(mat)
			
			print(result)
			for i in result.rows:
				var rect = CVRect.new()
				var x = result.get_at(i, 0)
				var y = result.get_at(i, 1)
				var w = result.get_at(i, 2)
				var h = result.get_at(i, 3)
				rect.set_values(x, y, w, h)
				
				CVImgProc.rectangle(mat, {"rec": rect})
				
			var tex: ImageTexture = ImageTexture.create_from_image(mat.get_image())
			video_feed.texture = tex

func _on_open_pressed():
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)

func _on_release_pressed():
	cap.release()
