extends GutTest
func before_each():
	gut.p("ran setup", 2)

func after_each():
	gut.p("ran teardown", 2)

func before_all():
	gut.p("ran run setup", 2)

func after_all():
	gut.p("ran run teardown", 2)

func test_adaptive_threshold():
	var mat := CVMat.zeros(5, 5, CVConsts.MatType.CV_8U)
	
	mat.set_at(2, 2, 255)
	mat.set_at(2, 3, 255)
	mat.set_at(3, 2, 255)
	mat.set_at(3, 3, 255)
	
	var result := CVImgProc.adaptive_threshold(mat, 1, CVConsts.ThresholdTypes.THRESH_BINARY, CVConsts.AdaptiveThresholdTypes.ADAPTIVE_THRESH_GAUSSIAN_C, 3, 0.5)
	
	assert_eq(result.cols, mat.cols)
	assert_eq(result.rows, mat.rows)
	
	assert_eq(result.get_at(0, 0), 1)
	assert_eq(result.get_at(2, 2), 0)
	
func test_bilateral_filter():
	var mat := CVMat.zeros(5, 5, CVConsts.MatType.CV_8U)
	var result := CVImgProc.bilateral_filter(mat, 0, 0, 0, {})
	
	assert_eq(result.cols, mat.cols)
	assert_eq(result.rows, mat.rows)
	
func test_blur():
	var mat := CVMat.zeros(5, 5, CVConsts.MatType.CV_8U)
	
	mat.set_at(3, 3, 255)
	
	var result := CVImgProc.blur(mat, Vector2(3, 3), {})
	
	assert_eq(result.cols, mat.cols)
	assert_eq(result.rows, mat.rows)
	
	assert_eq(result.get_at(2, 2), 28)
	
func test_cvt_color():
	var mat := CVMat.ones(5, 5, CVConsts.MatType.CV_8UC3)
	
	mat.set_at(0, 0, 255)
	
	var result := CVImgProc.cvt_color(mat, CVConsts.ColorConversionCodes.COLOR_BGR2GRAY, {})
	
	assert_eq(result.cols, mat.cols)
	assert_eq(result.rows, mat.rows)
	
	assert_eq(result.channels(), 1)
	assert_eq(result.get_at(0, 0), 29)
	
func test_dilate():
	var mat := CVMat.ones(5, 5, CVConsts.MatType.CV_8U)
	mat.set_at(3, 3, 1)
	
	var kernel := CVImgProc.get_structuring_element(CVConsts.MorphShapes.MORPH_CROSS, Vector2(3, 3), {})
	
	var result := CVImgProc.dilate(mat, kernel,{})
	
	assert_eq(result.cols, mat.cols)
	assert_eq(result.rows, mat.rows)
	
	assert_eq(result.get_at(2, 3), 1)
	
func test_equalize_hist():
	var mat := CVMat.ones(5, 5, CVConsts.MatType.CV_8U)
	
	mat.set_at(3, 3, 1)
	
	var result := CVImgProc.equalize_hist(mat)
	
	assert_eq(result.cols, mat.cols)
	assert_eq(result.rows, mat.rows)
	
	assert_eq(result.get_at(3, 2), 1)
	
func test_erode():
	var mat := CVMat.zeros(5, 5, CVConsts.MatType.CV_8U)
	
	mat.set_at(3, 3, 1)
	
	var kernel := CVImgProc.get_structuring_element(CVConsts.MorphShapes.MORPH_CROSS, Vector2(3, 3), {})
	
	var result := CVImgProc.erode(mat, kernel, {})
	
	assert_eq(result.cols, mat.cols)
	assert_eq(result.rows, mat.rows)
	
	assert_eq(result.get_at(3, 3), 0)
	
func test_gaussian_blur():
	var mat := CVMat.zeros(5, 5, CVConsts.MatType.CV_8U)
	
	mat.set_at(3, 3, 255)
	
	var result := CVImgProc.gaussian_blur(mat, Vector2(3, 3), 1, {})
	
	assert_eq(result.cols, mat.cols)
	assert_eq(result.rows, mat.rows)
	
	assert_eq(result.get_at(2, 2), 19)

func test_get_structuring_element():
	var result := CVImgProc.get_structuring_element(CVConsts.MorphShapes.MORPH_CROSS, Vector2(3, 3), {})
	
	assert_eq(result.get_at(0, 0), 0)
	assert_eq(result.get_at(0, 1), 1)
	assert_eq(result.get_at(0, 2), 0)
	
	assert_eq(result.get_at(1, 0), 1)
	assert_eq(result.get_at(1, 1), 1)
	assert_eq(result.get_at(1, 2), 1)
	
	assert_eq(result.get_at(2, 0), 0)
	assert_eq(result.get_at(2, 1), 1)
	assert_eq(result.get_at(2, 2), 0)

func test_median_blur():
	var mat := CVMat.zeros(15, 15, CVConsts.MatType.CV_8U)
	
	mat.set_at(6, 6, 255)
	mat.set_at(6, 7, 255)
	mat.set_at(7, 6, 255)
	mat.set_at(7, 7, 255)
	mat.set_at(5, 6, 255)
	
	var result := CVImgProc.median_blur(mat, 3)
	
	assert_eq(result.cols, mat.cols)
	assert_eq(result.rows, mat.rows)
	
	assert_eq(result.get_at(6, 6), 255)
	
func test_morphology_ex():
	var mat := CVMat.zeros(5, 5, CVConsts.MatType.CV_8U)
	
	mat.set_at(0, 0, 1)
	mat.set_at(1, 0, 1)
	mat.set_at(2, 0, 1)
	
	mat.set_at(1, 0, 1)
	mat.set_at(1, 1, 0)
	mat.set_at(1, 2, 1)
	
	mat.set_at(2, 0, 1)
	mat.set_at(2, 1, 1)
	mat.set_at(2, 2, 1)
	
	var kernel := CVImgProc.get_structuring_element(CVConsts.MorphShapes.MORPH_RECT, Vector2(3, 3), {})
	
	var result := CVImgProc.morphology_ex(mat, CVConsts.MorphTypes.MORPH_CLOSE, kernel, {})
	
	assert_eq(result.cols, mat.cols)
	assert_eq(result.rows, mat.rows)
	
	assert_eq(result.get_at(1, 1), 1)
	assert_eq(result.get_at(4, 4), 0)

func test_rectangle():
	var mat := CVMat.zeros(5, 5, CVConsts.MatType.CV_8UC3)
	var rect := CVRect.new()
	rect.set_values(0, 0, 3, 3)
	
	CVImgProc.rectangle(mat, {"rec":rect})
	
	assert_eq(mat.get_at(0, 0), 0)
	assert_eq(mat.get_at(1, 1), 255)
	
func test_threshold():
	var mat := CVMat.zeros(5, 5, CVConsts.MatType.CV_8U)
	
	mat.set_at(2, 2, 200)
	
	var result := CVImgProc.threshold(mat, 128, 255, CVConsts.ThresholdTypes.THRESH_BINARY_INV)
	
	assert_eq(result.cols, mat.cols)
	assert_eq(result.rows, mat.rows)
	
	assert_eq(result.get_at(0, 0), 255)
	assert_eq(result.get_at(2, 2), 0)
