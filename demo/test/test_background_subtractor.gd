extends GutTest
func before_each():
	gut.p("ran setup", 2)

func after_each():
	gut.p("ran teardown", 2)

func before_all():
	gut.p("ran run setup", 2)

func after_all():
	gut.p("ran run teardown", 2)

func test_knn_subtractor():
	var subtractorknn := CVBackgroundSubtractorKNN.create({})
	basic_subtractor(subtractorknn, "knn_subtractor_background")
	
func test_mog2_subtractor():
	var subtractormog2 := CVBackgroundSubtractorMOG2.create({})
	basic_subtractor(subtractormog2, "mog2_subtractor_background")

func basic_subtractor(subtractor, path):
	var cap = CVVideoCapture.new()
	cap.open("./test/testFiles/video.webm", CVConsts.VideoCaptureAPIs.CAP_ANY, null)
	
	var mat = cap.read()
	
	while mat.cols > 0:
		subtractor.apply(mat, {})
		mat = cap.read()
	var f := CVFileStorage.new()
	f.open("./test/testFiles/testData.xml", CVConsts.FileStorageMode.READ, {})
	
	var background:CVMat = subtractor.get_background_image()
	var file_background:CVMat = f.read(path)
	
	for i in background.rows/4:
		for j in background.cols/4:
			assert_eq(background.get_at(i, j), file_background.get_at(i, j))  # figure out deep comparisson
			
