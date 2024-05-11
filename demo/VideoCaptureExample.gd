extends Control

@onready var video_feed = %VideoFeed

var cap:CVVideoCapture

func _ready():
	cap = CVVideoCapture.new()
	cap.open(0,0)

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(_delta):
	if cap.is_opened():
		var mat = cap.read()
		var tex: ImageTexture = ImageTexture.create_from_image(mat.get_image())
		video_feed.texture = tex


func _on_open_pressed():
	cap.open(0,0)


func _on_release_pressed():
	cap.release()
