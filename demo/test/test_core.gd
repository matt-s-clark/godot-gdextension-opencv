extends GutTest
func before_each():
	gut.p("ran setup", 2)

func after_each():
	gut.p("ran teardown", 2)

func before_all():
	gut.p("ran run setup", 2)

func after_all():
	gut.p("ran run teardown", 2)

func test_absdiff():
	var mat1 := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var mat3 := CVCore.absdiff(mat1, mat2)
	
	assert_eq(mat3.get_at(0,0), 1)

func test_add():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var mat3 := CVCore.add(mat1, mat2, {})
	
	assert_eq(mat3.get_at(0,0), 2)
	
func test_add_weighted():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	
	var mat3 := CVCore.add_weighted(mat1, 0.5, mat2, 0.7, 0, {})
	
	assert_almost_eq(mat3.get_at(0,0), 1.2, 0.001)
	
func test_bitwise_and():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var mat3 := CVCore.bitwise_and(mat1, mat2, {})
	
	assert_eq(mat3.get_at(0,0) as int, 1)
	
func test_bitwise_or():
	var mat1 := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var mat3 := CVCore.bitwise_or(mat1, mat2, {})
	
	assert_eq(mat3.get_at(0,0) as int, 1)
	
func test_bitwise_xor():
	var mat1 := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var mat3 := CVCore.bitwise_xor(mat1, mat2, {})
	
	assert_eq(mat3.get_at(0,0) as int, 1)
	
func test_bitwise_not():
	var mat1 := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	
	var mat2 := CVCore.bitwise_not(mat1, {})
	
	assert_eq(mat2.get_at(0,0) as int, 255)
	
func test_dft():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	
	var mat2 := CVCore.dft(mat1, {})
	
	assert_almost_eq(mat2.get_at(0,0), 9.0, 0.001)
	
func test_exp():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	
	var mat2 := CVCore.exp(mat1)
	
	assert_almost_eq(mat2.get_at(0,0), 2.718, 0.001)
	
func test_get_optimal_dft_size():
	var n := CVCore.get_optimal_dft_size(16)
	
	assert_eq(n, 16)

func test_hconcat():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var mat3 := CVCore.hconcat(mat1, mat2)
	
	assert_eq(mat1.cols + mat2.cols, mat3.cols)
	assert_eq(mat1.rows, mat3.rows)
	
func test_vconcat():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var mat3 := CVCore.vconcat(mat1, mat2)
	
	assert_eq(mat1.rows + mat2.rows, mat3.rows)
	assert_eq(mat1.cols, mat3.cols)
	
func test_log():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	
	var mat2 := CVCore.log(mat1)
	
	assert_almost_eq(mat2.get_at(0,0), 0.0, 0.001)
	
func test_max():
	var mat1 := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var mat3 := CVCore.max(mat1, mat2)
	
	assert_eq(mat3.get_at(0,0) as int, 1)
	
func test_min():
	var mat1 := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var mat3 := CVCore.min(mat1, mat2)
	
	assert_eq(mat3.get_at(0,0) as int, 0)
	
func test_normalize():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	var mat2 := CVMat.zeros(3, 3, CVConsts.MatType.CV_32F)
	
	CVCore.normalize(mat1, mat2, {})
	
	assert_almost_eq(mat2.get_at(0,0), 0.333, 0.001)
	
func test_sqrt():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	
	var mat2 := CVCore.sqrt(mat1)
	
	assert_almost_eq(mat2.get_at(0,0), 1.0, 0.001)
	
func test_subtract():
	var mat1 := CVMat.zeros(3, 3, CVConsts.MatType.CV_8S)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_8S)
	
	var mat3 := CVCore.subtract(mat1, mat2, {})
	
	assert_eq(mat3.get_at(0,0) as int, -1)

func test_transpose():
	var mat1 := CVMat.ones(3, 4, CVConsts.MatType.CV_32F)
	
	var mat2 := CVCore.transpose(mat1)
	
	assert_eq(mat1.rows, mat2.cols)
	assert_eq(mat1.cols, mat2.rows)
