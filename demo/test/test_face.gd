extends GutTest
func before_each():
	gut.p("ran setup", 2)

func after_each():
	gut.p("ran teardown", 2)

func before_all():
	gut.p("ran run setup", 2)

func after_all():
	gut.p("ran run teardown", 2)

func test_face_YN_SF():
	var cap = CVVideoCapture.new()
	cap.open("./test/testFiles/video.webm", 0, null)
	
	assert_true(cap.is_opened(), "File opens")
	
	var frame := cap.read()
	
	var detector := CVFaceDetectorYN.create("./Models/face_detection_yunet_2023mar.onnx", "", Vector2(frame.cols,frame.rows), {})
	var recognizer := CVFaceRecognizerSF.create("./Models/face_recognition_sface_2021dec.onnx", "", {})
	
	var result := detector.detect_simplified(frame)
	
	var croped:= recognizer.align_crop(frame, result[0]["face_mat"])
	assert_eq(croped.rows, 112)
	assert_eq(croped.cols, 112)
	
	var feature = recognizer.feature(croped)
	assert_eq(feature.rows, 1)
	assert_eq(feature.cols, 128)
	
	var feature_file := CVFileStorage.new()
	feature_file.open("./test/testFiles/testData.xml", CVConsts.FileStorageMode.READ, {})
	assert_true(feature_file.isOpened(), "File opens correctly")
	
	var saved_feature : CVMat = feature_file.read("test_face_feature")
	
	if saved_feature:
		assert_almost_eq(recognizer.match(feature, saved_feature, {}), 1.0, 0.001, "Recognizes face from file")
	else:
		fail_test("saved_feature is null")
		
	assert_eq(detector.get_input_size(), Vector2(640, 480))
	assert_almost_eq(detector.get_nms_threshold(), .3, .0001)
	assert_almost_eq(detector.get_score_threshold(), .9, .0001)
	assert_eq(detector.get_top_k(), 5000)
	
	detector.set_input_size(Vector2(100,100))
	detector.set_nms_threshold(.9)
	detector.set_score_threshold(.3)
	detector.set_top_k(1000)
	
	assert_eq(detector.get_input_size(), Vector2(100, 100))
	assert_almost_eq(detector.get_nms_threshold(), .9, .0001)
	assert_almost_eq(detector.get_score_threshold(), .3, .0001)
	assert_eq(detector.get_top_k(), 1000)
