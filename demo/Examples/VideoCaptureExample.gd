extends Control

@onready var video_feed = %VideoFeed

var cap:CVVideoCapture

func _ready():
	cap = CVVideoCapture.new()
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)
	
	print(cap)
	print(cap.get_backend_name())
	print(cap.get(0))
	print(cap.get_exception_mode())

func _process(_delta):
	if cap.is_opened():
		var mat = cap.read()
		if mat.cols > 0:
			var tex: ImageTexture = ImageTexture.create_from_image(mat.get_image())
			video_feed.texture = tex

func _on_open_pressed():
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)

func _on_release_pressed():
	cap.release()
