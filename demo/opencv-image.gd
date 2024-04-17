extends Node2D


# Called when the node enters the scene tree for the first time.
func _ready():
	var img = Image.create(16, 16, false, Image.FORMAT_RGBA8)
	img.set_pixel(8, 8, Color.RED)
	$TextureRect.texture = ImageTexture.create_from_image(img)


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
