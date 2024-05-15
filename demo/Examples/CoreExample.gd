extends Control

@onready var video_feed = %VideoFeed
@onready var video_feed_2 = %VideoFeed2
@onready var video_feed_3 = %VideoFeed3
@onready var video_feed_4 = %VideoFeed4

var cap:CVVideoCapture
var firstFrame:CVMat

func _ready():
	cap = CVVideoCapture.new()
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)
	
	firstFrame = cap.read()

func _process(_delta):
	if cap.is_opened():
		var mat = cap.read()
		if mat.cols > 0:
			var transMat := CVCore.transpose(mat)
			var andMat := CVCore.bitwise_and(mat, firstFrame, null)
			var subMat := CVCore.subtract(mat, firstFrame, null, 0)
			var maxMat := CVCore.max(mat, firstFrame)
			
			video_feed.texture = ImageTexture.create_from_image(transMat.get_image())
			video_feed_2.texture = ImageTexture.create_from_image(andMat.get_image())
			video_feed_3.texture = ImageTexture.create_from_image(subMat.get_image())
			video_feed_4.texture = ImageTexture.create_from_image(maxMat.get_image())

func _on_open_pressed():
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)
	firstFrame = cap.read()

func _on_release_pressed():
	cap.release()
