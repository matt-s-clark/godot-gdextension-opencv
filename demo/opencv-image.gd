extends TextureRect


# Called when the node enters the scene tree for the first time.
func _ready():
	print("READY NOW!")
	var matLoad = CVImgCodecs.imread("aruco-capture.png", 1)
	
	print(matLoad)
	print('=========')
	print(matLoad.get_image())
	
	var gdExample = CVMat.new()
	var tiltFiveIRCameraImage:Image = matLoad.get_image()
	print(tiltFiveIRCameraImage)
	
	if not tiltFiveIRCameraImage.is_empty():
		texture = ImageTexture.create_from_image(tiltFiveIRCameraImage)

	var arucoPos:Array = CVArucoHelper.getMarkerPosition()
	for aPos in arucoPos:
		print("ARUCO: ",aPos.x, ", ", aPos.y)
	
	$MarkerHighlight.set_position(arucoPos[0])
	
# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(_delta):
	pass
