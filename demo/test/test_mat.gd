extends GutTest
func before_each():
	gut.p("ran setup", 2)

func after_each():
	gut.p("ran teardown", 2)

func before_all():
	gut.p("ran run setup", 2)

func after_all():
	gut.p("ran run teardown", 2)

func test_general():
	var mat := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	
	assert_eq(mat.cols, 3)
	assert_eq(mat.rows, 3)
	assert_eq(mat.channels(), 1)
	assert_eq(mat.get_at(0,0), 0)
	
	mat.set_at(0,0,2)
	
	assert_eq(mat.get_at(0,0), 2)
	assert_eq(mat.type(), CVConsts.MatType.CV_8U)
	
	mat.convert_to(CVConsts.MatType.CV_32F)
	
	assert_eq(mat.type(), CVConsts.MatType.CV_32F)
	
