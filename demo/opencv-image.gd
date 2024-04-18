extends GDExample


# Called when the node enters the scene tree for the first time.
func _ready():
	print("READY!")
	print(get_godot_image());

	texture = ImageTexture.create_from_image(get_godot_image());


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(_delta):
	pass
