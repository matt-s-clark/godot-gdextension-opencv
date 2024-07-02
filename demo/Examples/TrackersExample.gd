extends Control

@onready var video_feed = %VideoFeed

var cap:CVVideoCapture
var trackerCSRT:CVTrackerCSRT
var trackerKCF:CVTrackerKCF
var mat:CVMat

var initial_position: Vector2
var position_offset := Vector2(0, 0)
var frame_scale : float= 1.3
var dragging := false
var tracker_initiated := false
var use_csrt := true
var use_kcf := true

func _ready():
	cap = CVVideoCapture.new()
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)
	
	mat = cap.read()
	
	_calc_variables()

func _process(_delta):
	if !cap.is_opened():
		return
		
	mat = cap.read()
	if mat.cols <= 0:
		return
		
	if dragging:
		var rec = _calc_rect(get_viewport().get_mouse_position())
		
		CVImgProc.rectangle(mat, {"rec":rec})
	elif tracker_initiated:
		if use_csrt:
			var rectCSRT := trackerCSRT.update(mat)
			CVImgProc.rectangle(mat, {"rec":rectCSRT, "color":Color.BLUE})
		
		if use_kcf:
			var rectKCF := trackerKCF.update(mat)
			CVImgProc.rectangle(mat, {"rec":rectKCF, "color":Color.RED})
	
	video_feed.texture = mat.get_texture()

func _input(event):
	var mouse = event as InputEventMouseButton
	if mouse and mouse.is_pressed():
		initial_position = mouse.position
		dragging = true
		
	if mouse and not mouse.is_pressed():
		var rec = _calc_rect(mouse.position)
		dragging = false
		
		if rec.area() > 20 and rec.width > 1 and rec.height > 1:
			trackerCSRT = CVTrackerCSRT.create({})
			trackerCSRT.init(mat, rec)
			
			trackerKCF = CVTrackerKCF.create({})
			trackerKCF.init(mat, rec)
			tracker_initiated = true

func _calc_rect(mouse_position):
	var tl = Vector2(min(initial_position.x, mouse_position.x), min(initial_position.y, mouse_position.y))
	var br = Vector2(max(initial_position.x, mouse_position.x), max(initial_position.y, mouse_position.y))
	var x = (tl.x - position_offset.x) * frame_scale
	var y = (tl.y - position_offset.y) * frame_scale
	var w = (br.x - tl.x) * frame_scale
	var h = (br.y - tl.y) * frame_scale
	
	var rec := CVRect.new()
	rec.set_values(x, y, w, h)
	
	return rec
	
func _calc_variables():
	if video_feed:
		var a = mat.cols/video_feed.size.x
		var b = mat.rows/video_feed.size.y
		
		if a < b:
			frame_scale = b
			var f = (video_feed.size.x - (video_feed.size.y * (float(mat.cols)/mat.rows)))/2
			position_offset = Vector2(f, 0)
		else:
			frame_scale = a
			var f = (video_feed.size.y - (video_feed.size.x * (float(mat.rows)/mat.cols)))/2
			position_offset = Vector2(0, f)

func _on_open_pressed():
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)

func _on_release_pressed():
	cap.release()

func _on_video_feed_resized():
	_calc_variables()


func _on_use_csrt_toggled(toggled_on):
	use_csrt = toggled_on

func _on_use_kcf_toggled(toggled_on):
	use_kcf = toggled_on
