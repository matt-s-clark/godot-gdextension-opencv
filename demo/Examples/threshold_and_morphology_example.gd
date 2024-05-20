extends Control

@onready var video_feed = %VideoFeed
@onready var video_feed_2 = %VideoFeed2
@onready var video_feed_3 = %VideoFeed3
@onready var video_feed_4 = %VideoFeed4

var cap:CVVideoCapture

func _ready():
	cap = CVVideoCapture.new()
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	if cap.is_opened():
		var mat = cap.read()
		if mat.cols > 0:
			var gray := CVImgProc.cvt_color(mat, CVConsts.ColorConversionCodes.COLOR_BGR2GRAY, 0)
			var th := CVImgProc.threshold(gray, 120, 255, CVConsts.ThresholdTypes.THRESH_BINARY_INV)
			var kernel = CVImgProc.get_structuring_element(CVConsts.MorphShapes.MORPH_ELLIPSE, Vector2(20, 20), Vector2(-1, -1))
			var gr := CVImgProc.morphology_ex(th, CVConsts.MorphTypes.MORPH_GRADIENT, kernel, {})
			var kernel2 = CVImgProc.get_structuring_element(CVConsts.MorphShapes.MORPH_CROSS, Vector2(50, 50), Vector2(-1, -1))
			var hm := CVImgProc.morphology_ex(gr, CVConsts.MorphTypes.MORPH_DILATE, kernel2, {"interactions":10})
			video_feed.texture = ImageTexture.create_from_image(mat.get_image())
			video_feed_2.texture = ImageTexture.create_from_image(th.get_image())
			video_feed_3.texture = ImageTexture.create_from_image(gr.get_image())
			video_feed_4.texture = ImageTexture.create_from_image(hm.get_image())

