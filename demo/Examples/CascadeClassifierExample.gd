extends Control

@onready var video_feed = %VideoFeed

var cap:CVVideoCapture
var haar: CVCascadeClassifier

func _ready():
	cap = CVVideoCapture.new()
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)
	haar = CVCascadeClassifier.new()
	print(haar.load("res://hand.xml"))

func _process(_delta):
	if cap.is_opened():
		var mat = cap.read()
		if mat.cols > 0:
			if not haar.empty():
				var result := haar.detect_multi_scale(mat, {})
				for i in result["objects"]:
					print(i)
			var tex: ImageTexture = ImageTexture.create_from_image(mat.get_image())
			video_feed.texture = tex

func _on_open_pressed():
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)

func _on_release_pressed():
	cap.release()
