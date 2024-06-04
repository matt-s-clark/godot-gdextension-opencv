extends GutTest
func before_each():
	gut.p("ran setup", 2)

func after_each():
	gut.p("ran teardown", 2)

func before_all():
	gut.p("ran run setup", 2)

func after_all():
	gut.p("ran run teardown", 2)

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
