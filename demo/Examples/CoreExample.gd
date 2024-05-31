extends Control

@onready var video_feed = %VideoFeed
@onready var video_feed_2 = %VideoFeed2
@onready var video_feed_3 = %VideoFeed3
@onready var video_feed_4 = %VideoFeed4

var cap:CVVideoCapture
var comparison_frame:CVMat

func _ready():
	cap = CVVideoCapture.new()
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)
	
	comparison_frame = cap.read()

func _process(_delta):
	if cap.is_opened():
		var mat = cap.read()
		if mat.cols > 0:
			var transMat := CVCore.transpose(mat)
			var andMat := CVCore.bitwise_and(mat, comparison_frame, {})
			var subMat := CVCore.subtract(mat, comparison_frame, {})
			var maxMat := CVCore.max(mat, comparison_frame)
			
			video_feed.texture = ImageTexture.create_from_image(transMat.get_image())
			video_feed_2.texture = ImageTexture.create_from_image(andMat.get_image())
			video_feed_3.texture = ImageTexture.create_from_image(subMat.get_image())
			video_feed_4.texture = ImageTexture.create_from_image(maxMat.get_image())

func _on_open_pressed():
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)

func _on_release_pressed():
	cap.release()

func _on_update_pressed():
	comparison_frame = cap.read()
