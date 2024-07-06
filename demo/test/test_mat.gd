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
	var rows = 3
	var cols = 3
	
	var mat := CVMat.zeros(rows, cols, CVConsts.MatType.CV_8U)
	
	assert_eq(mat.cols, rows)
	assert_eq(mat.rows, cols)
	assert_eq(mat.channels(), 1)
	assert_eq(mat.get_at(0,0), 0)
	
	mat.set_at(0,0,2)
	
	assert_eq(mat.get_at(0,0), 2)
	
	assert_eq(mat.type(), CVConsts.MatType.CV_8U)
	assert_eq(mat.depth(), CVConsts.MatType.CV_8U)
	
	mat.convert_to(CVConsts.MatType.CV_32F)
	
	assert_eq(mat.type(), CVConsts.MatType.CV_32F)
	assert_eq(mat.depth(), CVConsts.MatType.CV_32F)
	
	assert_eq(mat.col(0).rows, rows)
	assert_eq(mat.col(0).cols, 1)
	assert_eq(mat.row(0).rows, 1)
	assert_eq(mat.row(0).cols, cols)
	
	var mat2 = mat.copy()
	
	for i in rows:
		for j in cols:
			assert_eq(mat.get_at(i, j), mat2.get_at(i, j))
	
func test_static_methods():
	var rows = 3
	var cols = 3
	
	var zeros = CVMat.zeros(rows, cols, CVConsts.MatType.CV_8U)
	var ones = CVMat.ones(rows, cols, CVConsts.MatType.CV_8U)
	var eye = CVMat.eye(rows, cols, CVConsts.MatType.CV_8U)
	
	for i in rows:
		for j in cols:
			assert_eq(zeros.get_at(i, j), 0)
			assert_eq(ones.get_at(i, j), 1)
			assert_eq(eye.get_at(i, j), 1 if i == j else 0)

func test_helper_methods():
	var texture : Texture2D = load("res://icon.svg")
	var mat1 := CVMat.from_image(texture.get_image())
	var mat2 := CVMat.new()
	mat2.set_image(texture.get_image())
	var mat3 := CVMat.from_texture(texture)
	var mat4 := CVMat.new()
	mat4.set_texture(texture)
	
	for i in mat1.rows/4:
		for j in mat1.cols/4:
			assert_eq(mat1.get_at(i, j), mat2.get_at(i, j))
			assert_eq(mat1.get_at(i, j), mat3.get_at(i, j))
			assert_eq(mat1.get_at(i, j), mat4.get_at(i, j)) # figure out deep comparisson
