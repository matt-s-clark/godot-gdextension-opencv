extends GutTest
func before_each():
	gut.p("ran setup", 2)

func after_each():
	gut.p("ran teardown", 2)

func before_all():
	gut.p("ran run setup", 2)

func after_all():
	gut.p("ran run teardown", 2)
	DirAccess.remove_absolute("./test/testFiles/tmp.png")

func test_imread():
	var image := CVImgCodecs.imread("./aruco-capture.png", {})
	
	assert_ne(image.cols, 0)
	assert_ne(image.rows, 0)
	assert_eq(image.channels(), 3)
	
func test_imread_gray():
	var image := CVImgCodecs.imread("./aruco-capture.png", {"flags":CVConsts.ImreadModes.IMREAD_GRAYSCALE})
	
	assert_ne(image.cols, 0)
	assert_ne(image.rows, 0)
	assert_eq(image.channels(), 1)
	
func test_imwrite():
	var rows = 5
	var cols = 5
	var mat := CVMat.ones(rows, cols, CVConsts.MatType.CV_8UC3)
	
	CVImgCodecs.imwrite("./test/testFiles/tmp.png", mat, {})
	
	var mat2 := CVImgCodecs.imread("./test/testFiles/tmp.png", {})
	
	for i in rows:
		for j in cols:
			assert_eq(mat.get_at(i, j), mat2.get_at(i, j), str(i) + " - " + str(j))
