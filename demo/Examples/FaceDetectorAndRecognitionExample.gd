extends Control

@onready var video_feed = %VideoFeed

var name_card := load("res://Examples/name_card.tscn")

var cap:CVVideoCapture
var detector:CVFaceDetectorYN
var recognizer:CVFaceRecognizerSF
var feature_list := []

var should_draw_face: bool = false

func _ready():
	cap = CVVideoCapture.new()
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)
	var mat := cap.read()
	
	detector = CVFaceDetectorYN.create("./face_detection_yunet_2023mar.onnx", "", Vector2(mat.cols,mat.rows), {})
	recognizer = CVFaceRecognizerSF.create("./face_recognition_sface_2021dec.onnx", "", {})

func _process(_delta):
	if cap.is_opened():
		var mat := cap.read()
		if mat.cols > 0:
			var result := detector.detect_simplified(mat)
			
			recognize_face(result, mat)
				
			var tex: ImageTexture = ImageTexture.create_from_image(mat.get_image())
			video_feed.texture = tex

func draw_face(mat, face):
	CVImgProc.rectangle(mat, {"rec": face["rect"]})
	CVImgProc.ellipse(mat, face["right_eye"], Vector2(3, 3), 0, 0, 360, {"color":Color.REBECCA_PURPLE, "thickness":3})
	CVImgProc.ellipse(mat, face["left_eye"], Vector2(3, 3), 0, 0, 360, {"color":Color.REBECCA_PURPLE, "thickness":3})
	CVImgProc.ellipse(mat, face["nose_tip"], Vector2(3, 3), 0, 0, 360, {"color":Color.REBECCA_PURPLE, "thickness":3})
	CVImgProc.line(mat, face["right_mouth"], face["left_mouth"], {"color":Color.REBECCA_PURPLE, "thickness":3})

func recognize_face(result, mat):
	for i in result:
		
		if should_draw_face:
			draw_face(mat, i)
		
		var croped:= recognizer.align_crop(mat, i["face_mat"])
		var feature = recognizer.feature(croped)
		
		var max_resem := 0.0
		for f in feature_list:
			if f["current"]: continue
			var resemblance := recognizer.match(feature, f["feature"], {})
			max_resem = max(max_resem, resemblance)
			if resemblance > 0.7:
				f["current"] = i
			
		if max_resem < 0.3 or feature_list.size() == 0:
			var instance:Control = name_card.instantiate()
			
			feature_list.append({"feature":feature.copy(), "object":instance, "current":null})
			add_child(instance)
			
			print("size feature list ", feature_list.size())
			
	for f in feature_list:
		f["object"].visible = f["current"] != null
		if f["object"].visible: f["object"].position = f["current"]["right_eye"]
		f["current"] = null

func _on_open_pressed():
	cap.open(0, CVConsts.VideoCaptureAPIs.CAP_ANY, null)

func _on_release_pressed():
	cap.release()


func _on_draw_face_toggled(toggled_on):
	should_draw_face = toggled_on