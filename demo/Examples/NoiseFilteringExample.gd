extends Control

@onready var video_feed = %VideoFeed
@onready var video_feed_2 = %VideoFeed2
@onready var video_feed_3 = %VideoFeed3
@onready var video_feed_4 = %VideoFeed4

var thread : Thread
var mat : CVMat

var cap:CVVideoCapture
var median_blur:= 11
var gaussian_blur:= 11
var bilateral:= 10

func _ready():
	cap = CVVideoCapture.new()
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)
	
	thread = Thread.new()
	thread.start(_thread_function.bind())

func _process(_delta):
	if !cap.is_opened():
		return
		
	mat = cap.read()
	if mat.cols <= 0:
		return
		
	var mb := CVImgProc.median_blur(mat, median_blur)
	var gb := CVImgProc.gaussian_blur(mat, Vector2(gaussian_blur, gaussian_blur), 0, {})
	
	video_feed.texture = mat.get_texture()
	video_feed_2.texture = mb.get_texture()
	video_feed_3.texture = gb.get_texture()
	
	if thread.is_alive():
		return
	
	var bi = thread.wait_to_finish()
	thread.start(_thread_function.bind())
	
	if bi != null:
		video_feed_4.texture = bi.get_texture()

func _thread_function():
	if mat == null:
		return

	var bi = CVImgProc.bilateral_filter(mat, -1, bilateral, bilateral, {})
	return bi

func _on_open_pressed():
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)


func _on_release_pressed():
	cap.release()

func _on_bilateral_filter_value_value_changed(value):
	bilateral = value


func _on_gaussian_blur_value_value_changed(value):
	gaussian_blur = value


func _on_median_blur_value_value_changed(value):
	median_blur = value
