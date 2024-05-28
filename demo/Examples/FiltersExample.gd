extends Control

@onready var video_feed = %VideoFeed
@onready var video_feed_2 = %VideoFeed2
@onready var video_feed_3 = %VideoFeed3
@onready var video_feed_4 = %VideoFeed4

var thread : Thread
var mat : CVMat

var cap:CVVideoCapture
var blur:= 11
var bilateral:= 10

func _ready():
	cap = CVVideoCapture.new()
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)
	
	thread = Thread.new()
	thread.start(_thread_function.bind())

func _process(_delta):
	if cap.is_opened():
		mat = cap.read()
		if mat.cols > 0:
			var bl := CVImgProc.gaussian_blur(mat, Vector2(blur, blur), 0, {})
			var so := CVImgProc.sobel(mat, -1, 1, 1, {})
			
			video_feed.texture = ImageTexture.create_from_image(mat.get_image())
			video_feed_2.texture = ImageTexture.create_from_image(bl.get_image())
			video_feed_3.texture = ImageTexture.create_from_image(so.get_image())

func _thread_function():
	while mat == null:
		pass
	while mat != null:
		call_deferred("_update_bilateral", CVImgProc.bilateral_filter(mat, -1, bilateral, bilateral, {}))

func _update_bilateral(bi):
	if bi != null:
		video_feed_4.texture = ImageTexture.create_from_image(bi.get_image())

func _on_open_pressed():
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)


func _on_release_pressed():
	cap.release()


func _on_blur_value_value_changed(value):
	blur = value

func _on_bilateral_filter_value_value_changed(value):
	bilateral = value
