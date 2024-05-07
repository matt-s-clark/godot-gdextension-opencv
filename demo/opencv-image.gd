extends TextureRect


# Called when the node enters the scene tree for the first time.
func _ready():
	print("READY NOW!")
	var matLoad = CVImgCodecs.imread("aruco-capture.png", 1);
	print(matLoad);
	
	var gdExample = CVMat.new();
	var tiltFiveIRCameraImage = gdExample.get_godot_image();
	print(tiltFiveIRCameraImage);
#
	texture = ImageTexture.create_from_image(tiltFiveIRCameraImage);


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(_delta):
	pass
