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
	var mat := CVMat.zeros(5, 5, CVConsts.MatType.CV_8UC3)
	
	mat.set_at(0, 0, Vector3(255, 0, 0))
	
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
	var rect := CVRect.from_values(0, 0, 3, 3)
	
	CVImgProc.rectangle(mat, {"rec":rect})
	
	assert_eq(mat.get_at(0, 0), Vector3i(0,255,0))
	assert_eq(mat.get_at(1, 1), Vector3i(0,0,0))
	
func test_threshold():
	var mat := CVMat.zeros(5, 5, CVConsts.MatType.CV_8U)
	
	mat.set_at(2, 2, 200)
	
	var result := CVImgProc.threshold(mat, 128, 255, CVConsts.ThresholdTypes.THRESH_BINARY_INV)
	
	var dst = result["dst"]
	
	assert_eq(dst.cols, mat.cols)
	assert_eq(dst.rows, mat.rows)
	
	assert_eq(dst.get_at(0, 0), 255)
	assert_eq(dst.get_at(2, 2), 0)
	
func test_sobel():
	# Could be better
	var mat := CVMat.zeros(5, 5, CVConsts.MatType.CV_8U)
	
	var result := CVImgProc.sobel(mat, -1, 1, 1, {})
	
	assert_eq(result.cols, mat.cols)
	assert_eq(result.rows, mat.rows)
	
func test_laplacian():
	var mat := CVMat.zeros(5, 5, CVConsts.MatType.CV_8U)
	
	for i in mat.cols:
		mat.set_at(2, i, 255)
	
	var result := CVImgProc.laplacian(mat, -1, {})
	
	assert_eq(result.cols, mat.cols)
	assert_eq(result.rows, mat.rows)
	
	assert_eq(result.get_at(0,0), 0)
	assert_eq(result.get_at(1,0), 255)
	assert_eq(result.get_at(2,0), 0)
	assert_eq(result.get_at(3,0), 255)
	assert_eq(result.get_at(4,0), 0)
	
func test_filter_2D():
	var mat := CVMat.ones(5, 5, CVConsts.MatType.CV_8U)
	var kernel := CVImgProc.get_structuring_element(CVConsts.MorphShapes.MORPH_CROSS, Vector2(3, 3), {})
	var result := CVImgProc.filter_2d(mat, -1, kernel, {})
	
	assert_eq(result.cols, mat.cols)
	assert_eq(result.rows, mat.rows)
	
	assert_eq(result.get_at(0,0), 5)
	
func test_get_gabor_kernel():
	var mat := CVImgProc.get_gabor_kernel(Vector2(3, 3), 5.1, 1.5, 0.3, 2.6, {})
	
	assert_almost_eq(mat.get_at(0,0), 0.326, 0.001)
	assert_almost_eq(mat.get_at(0,1), -0.873, 0.001)
	assert_almost_eq(mat.get_at(0,2), -0.45, 0.001)
	
func test_get_gaussian_kernel():
	var mat := CVImgProc.get_gaussian_kernel(3, 0, {})
	
	assert_almost_eq(mat.get_at(0,0), 0.25, 0.001)
	assert_almost_eq(mat.get_at(1,0), 0.5, 0.001)
	assert_almost_eq(mat.get_at(2,0), 0.25, 0.001)

func test_box_filter():
	var mat := CVMat.eye(5, 5, CVConsts.MatType.CV_32F)
	var result := CVImgProc.box_filter(mat, -1, Vector2(3, 3), {})
	
	assert_eq(result.cols, mat.cols)
	assert_eq(result.rows, mat.rows)
	
	assert_almost_eq(result.get_at(0,0), .555, .001)

func test_get_deriv_kernels():
	var dict := CVImgProc.get_deriv_kernels(1, 2, 3, {})
	
	var kx : CVMat = dict["kx"]
	var ky : CVMat = dict["ky"]
	
	assert_eq(kx.get_at(0,0), -1.0)
	assert_eq(kx.get_at(1,0), 0.0)
	assert_eq(kx.get_at(2,0), 1.0)
	
	assert_eq(ky.get_at(0,0), 1.0)
	assert_eq(ky.get_at(1,0), -2.0)
	assert_eq(ky.get_at(2,0), 1.0)

func test_morphology_default_border_value():
	var m := CVImgProc.morphology_default_border_value()
	
	assert_eq(m.get_vector4(), Vector4.INF)
	assert_eq(m.get_int(), -2147483648)

func test_pyr_down():
	var mat := CVMat.eye(20, 20, CVConsts.MatType.CV_32F)
	var result := CVImgProc.pyr_down(mat, {})
	
	assert_eq(result.cols, mat.cols/2)
	assert_eq(result.rows, mat.rows/2)
	
	assert_almost_eq(result.get_at(0,0), 0.406, 0.001)

func test_pyr_up():
	var mat := CVMat.eye(20, 20, CVConsts.MatType.CV_32F)
	var result := CVImgProc.pyr_up(mat, {})
	
	assert_eq(result.cols, mat.cols*2)
	assert_eq(result.rows, mat.rows*2)
	
	assert_almost_eq(result.get_at(0,0), 0.625, 0.001)

func test_scharr():
	var mat := CVMat.eye(10, 10, CVConsts.MatType.CV_32F)
	var result := CVImgProc.scharr(mat, -1, 0, 1, {})
	
	for i in result.rows:
		for j in result.cols:
			var val := 0.0
			if (i == 0 and j == 1) or (i == 0 and j == 2) or (i == 9 and j == 7) or (i == 9 and j == 8):
				pass
			else:
				if i == 2 and j == 0:
					val = -6
				elif i == 7 and j == 9:
					val = 6
				elif i == j+1:
					val = -10
				elif i+1 == j:
					val = 10
				elif i == j+2:
					val = -3
				elif i+2 == j:
					val = 3
			assert_eq(result.get_at(i, j), val, str(i, " - ", j))

func test_sep_filter_2d():
	var mat := CVMat.ones(5, 5, CVConsts.MatType.CV_8U)
	var kernel := CVImgProc.get_structuring_element(CVConsts.MorphShapes.MORPH_CROSS, Vector2(1, 3), {})
	var result := CVImgProc.sep_filter_2d(mat, -1, kernel, kernel, {})
	
	assert_eq(result.cols, mat.cols)
	assert_eq(result.rows, mat.rows)
	
	assert_eq(result.get_at(0,0), 9)

func test_spatial_gradient():
	var mat := CVMat.eye(5, 5, CVConsts.MatType.CV_8U)
	
	var result := CVImgProc.spatial_gradient(mat, {})
	
	assert_eq(result["dx"].cols, mat.cols)
	assert_eq(result["dx"].rows, mat.rows)
	
	assert_eq(result["dy"].cols, mat.cols)
	assert_eq(result["dy"].rows, mat.rows)
	
	assert_eq(result["dx"].get_at(0,1), -2)
	assert_eq(result["dy"].get_at(1,0), -2)

func test_convert_maps():
	pass

func test_get_affine_transform():
	pass

func test_get_perspective_transform():
	pass

func test_get_rect_sub_pix():
	pass

func test_get_rotation_matrix_2d():
	pass

func test_invert_affine_transform():
	pass

func test_linear_polar():
	pass

func test_log_polar():
	pass

func test_remap():
	pass

func test_resize():
	var mat := CVMat.eye(3, 3, CVConsts.MatType.CV_8U)
	var result := CVImgProc.resize(mat, Vector2(7, 7), {})
	
	assert_eq(result.rows, 7)
	assert_eq(result.cols, 7)

func test_warp_affine():
	pass

func test_warp_perspective():
	pass

func test_warp_polar():
	pass

func test_blend_linear():
	var mat1 := CVMat.eye(3, 3, CVConsts.MatType.CV_32F)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	
	var result := CVImgProc.blend_linear(mat1, mat1, mat2, mat2)
	
	for i in 3:
		for j in 3:
			assert_almost_eq(result.get_at(i,j), 1.0 if i == j else 0.0, 0.001)

func test_distance_transform():
	var mat := CVMat.ones(7, 7, CVConsts.MatType.CV_8U)
	mat.set_at(3, 3, 0)
	
	var result := CVImgProc.distance_transform(mat, 1, 3, {})
	
	assert_eq(result["dst"].get_at(0,0), 6.0)
	assert_eq(result["dst"].get_at(3,3), 0.0)
	assert_eq(result["dst"].get_at(5,6), 5.0)
	
	assert_eq(result["labels"].rows, 7)
	assert_eq(result["labels"].cols, 7)

func test_integral():
	var mat := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var result := CVImgProc.integral(mat, {})
	
	assert_eq(result["sum"].get_at(0,0), 0)
	assert_eq(result["sum"].get_at(2,2), 4)
	assert_eq(result["sum"].get_at(3,3), 9)
	
	assert_eq(result["sqsum"].get_at(0,0), 0.0)
	assert_eq(result["sqsum"].get_at(2,2), 4.0)
	assert_eq(result["sqsum"].get_at(3,3), 9.0)
	
	assert_eq(result["tilted"].get_at(0,0), 0)
	assert_eq(result["tilted"].get_at(2,2), 4)
	assert_eq(result["tilted"].get_at(3,3), 6)

func test_arrowed_line():
	var mat := CVMat.zeros(9, 9, CVConsts.MatType.CV_8U)
	CVImgProc.arrowed_line(mat, Vector2(0, 0), Vector2(5, 5), CVScalar.create(255), {})
	
	var array := [0, 10, 20, 30, 40, 41, 49, 50]
	
	for i in 9:
		for j in 9:
			assert_eq(mat.get_at(i, j), 0 if j+9*i not in array else 255, str(" ", i, " - ", j))

func test_circle():
	var mat := CVMat.zeros(9, 9, CVConsts.MatType.CV_8U)
	CVImgProc.circle(mat, Vector2(4, 4), 3, CVScalar.create(255), {})
	
	var array := [13, 20, 21, 23, 24, 29, 33, 37, 43, 47, 51, 56, 57, 59, 60, 67]
	
	for i in 9:
		for j in 9:
			assert_eq(mat.get_at(i, j), 0 if j+9*i not in array else 255, str(" ", i, " - ", j))

func test_draw_marker():
	var mat := CVMat.zeros(9, 9, CVConsts.MatType.CV_8U)
	CVImgProc.draw_marker(mat, Vector2(4, 4), CVScalar.create(255), {})
	
	var array := [4, 13, 22, 31, 36, 37, 38, 39, 40, 41, 42, 43, 44, 49, 58, 67, 76]
	
	for i in 9:
		for j in 9:
			assert_eq(mat.get_at(i, j), 0 if j+9*i not in array else 255, str(" ", i, " - ", j))

func test_ellipse():
	var mat := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	CVImgProc.ellipse(mat, Vector2.ZERO, Vector2.ONE, 0, 0, 360, CVScalar.create(5), {})
	
	assert_eq(mat.get_at(0, 1), 5)
	assert_eq(mat.get_at(1, 0), 5)

func test_fill_convex_poly():
	var mat := CVMat.zeros(7, 7, CVConsts.MatType.CV_8U)
	var poly := CVMat.from_array([0, 0, 0, 4, 4, 4, 4, 0], 1, CVConsts.MatType.CV_32SC2)
	# ??? I really need to look into array conversion
	poly.convert_to(CVConsts.MatType.CV_8UC2)
	poly.convert_to(CVConsts.MatType.CV_32SC2)
	CVImgProc.fill_convex_poly(mat, poly, CVScalar.create(255), {})
	
	for i in 7:
		for j in 7:
			assert_eq(mat.get_at(i, j), 0 if i>4 or j>4 else 255, str(" ", i, " - ", j))

func test_get_font_scale_from_height():
	var result := CVImgProc.get_font_scale_from_height(CVConsts.HersheyFonts.FONT_HERSHEY_SIMPLEX, 10, {})
	assert_almost_eq(result, 0.428, 0.001)

func test_line():
	var mat := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	CVImgProc.line(mat, Vector2.ZERO, Vector2.ONE, CVScalar.create(5), {})
	
	assert_eq(mat.get_at(0, 0), 5)
	assert_eq(mat.get_at(1, 1), 5)

func test_demosaicing():
	pass

func test_apply_color_map():
	pass
	# Weird error
	#var mat := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	#var colorMap := CVMat.zeros(16, 16, CVConsts.MatType.CV_8U)
	#
	#var result := CVImgProc.apply_color_map(mat, colorMap)
	#
	#print(result.dump())

func test_compare_hist():
	var mat1 := CVMat.eye(300, 300, CVConsts.MatType.CV_32F)
	var mat2 := CVMat.ones(300, 300, CVConsts.MatType.CV_32F)
	
	var result := CVImgProc.compare_hist(mat1, mat2, CVConsts.HistCompMethods.HISTCMP_CORREL)
	
	assert_almost_eq(result, 1.0, 0.001)

func test_arc_length():
	var mat := CVMat.zeros(2, 2, CVConsts.MatType.CV_32F)
	mat.set_at(1, 0, 1)
	mat.set_at(1, 1, 1)
	
	var result := CVImgProc.arc_length(mat, false)
	
	assert_almost_eq(result, 1.414, 0.001)

func test_bounding_rect():
	var mat := CVMat.zeros(4, 2, CVConsts.MatType.CV_32F)
	mat.set_at(1, 0, 3)
	mat.set_at(1, 1, 5)
	mat.set_at(2, 0, 2)
	mat.set_at(2, 1, 3)
	mat.set_at(3, 0, 4)
	mat.set_at(3, 1, 1)
	
	var result := CVImgProc.bounding_rect(mat)
	
	assert_eq(result.br(), Vector2(5,6))
	assert_eq(result.tl(), Vector2.ZERO)

func test_connected_components():
	pass

func test_connected_components_with_stats():
	pass

func test_contour_area():
	var mat := CVMat.zeros(4, 2, CVConsts.MatType.CV_32F)
	mat.set_at(1, 0, 3)
	mat.set_at(1, 1, 5)
	mat.set_at(2, 0, 2)
	mat.set_at(2, 1, 3)
	mat.set_at(3, 0, 4)
	mat.set_at(3, 1, 1)
	
	var result := CVImgProc.contour_area(mat, {})
	
	assert_almost_eq(result, 5.5, .001)

func test_convex_hull():
	var mat := CVMat.zeros(4, 2, CVConsts.MatType.CV_32F)
	mat.set_at(1, 0, 3)
	mat.set_at(1, 1, 5)
	mat.set_at(2, 0, 2)
	mat.set_at(2, 1, 3)
	mat.set_at(3, 0, 4)
	mat.set_at(3, 1, 1)
	
	var result := CVImgProc.convex_hull(mat, {})
	
	assert_eq(result.get_at(0,0), Vector2(4,1))
	assert_eq(result.get_at(1,0), Vector2(3,5))
	assert_eq(result.get_at(2,0), Vector2.ZERO)

func test_convexity_defects():
	pass

func test_fit_line():
	pass

func test_intersect_convex_convex():
	pass

func test_is_contour_convex():
	pass

func test_match_shapes():
	pass

func test_min_enclosing_triangle():
	pass

func test_point_polygon_test():
	pass

func test_accumulate():
	pass

func test_accumulate_product():
	pass

func test_accumulate_square():
	pass

func test_accumulate_weighted():
	pass

func test_create_hanning_window():
	pass

func test_canny():
	var mat0 := CVMat.zeros(1, 3, CVConsts.MatType.CV_8U)
	var mat1 := CVMat.ones(1, 3, CVConsts.MatType.CV_8U)
	var mat := CVCore.vconcat(mat0, mat1)
	mat = CVCore.vconcat(mat, mat0)
	
	var result := CVImgProc.canny(mat, 0, 1, {})
	
	for i in mat.rows:
		for j in mat.cols:
			assert_eq(result.get_at(i, j), 255 if i%2 == 0 else 0, str(i, " - ", j))
	
func test_corner_eigen_vals_and_vecs():
	pass

func test_corner_harris():
	var mat := CVMat.from_array([0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0,0,0, 0, 0, 0,0,0, 0, 0, 0,0,0], 5, CVConsts.MatType.CV_32F)
	mat.convert_to(CVConsts.MatType.CV_8U)
	var result := CVImgProc.corner_harris(mat, 3, 3, 0, {})
	
	for i in mat.rows:
		for j in mat.cols:
			assert_lt(result.get_at(i, j), 0.062 if i%2 == 0 else 0.034, str(i, " - ", j))

func test_corner_min_eigen_val():
	pass

func test_good_features_to_track():
	pass

func test_hough_circles():
	pass
	#var mat := CVMat.zeros(250, 250, CVConsts.MatType.CV_8U)
	#CVImgProc.circle(mat, Vector2(50, 50), 40, CVScalar.create(255), {"thickness":3})
	#CVImgProc.circle(mat, Vector2(100, 100), 80, CVScalar.create(255), {"thickness":30})
	#mat = CVCore.bitwise_not(mat, {})
	#
	#var result := CVImgProc.hough_circles(mat, CVConsts.HoughModes.HOUGH_GRADIENT, 1, 1, {})
	#CVImgCodecs.imwrite("teste.png", mat, {})
	#print(result)
	#
	#for i in result.rows:
		#for j in result.cols:
			#print(result.get_at(i, j))
		#print()
	#fail_test("Not Finished")
	
func test_hough_lines():
	var mat := CVMat.eye(10, 10, CVConsts.MatType.CV_8U)
	var line := CVMat.ones(1, 10, CVConsts.MatType.CV_8U)
	mat = CVCore.vconcat(mat, line)
	
	var result := CVImgProc.hough_lines(mat, 2, 5*PI/180, 10, {})
	
	assert_eq(Vector2i(result.get_at(0, 0)), Vector2i(9, 1))
	assert_eq(Vector2i(result.get_at(1, 0)), Vector2i(-1, 2))
	
func test_hough_lines_p():
	var mat := CVMat.eye(10, 10, CVConsts.MatType.CV_8U)
	var line := CVMat.ones(1, 10, CVConsts.MatType.CV_8U)
	mat = CVCore.vconcat(mat, line)
	
	var result := CVImgProc.hough_lines_p(mat, 1, PI/180, 5, {})
	
	assert_eq(result.get_at(0, 0), Vector4i(0,0,8,8))
	assert_eq(result.get_at(1, 0), Vector4i(0,10,9,10))
	
func test_hough_lines_point_set():
	pass

func test_pre_corner_detect():
	pass

func test_match_template():
	pass

func test_grab_cut():
	pass

func test_watershed():
	pass

func test_find_contours():
	var mat1 := CVMat.zeros(3, 5, CVConsts.MatType.CV_8U)
	var mat2 := CVMat.ones(2, 5, CVConsts.MatType.CV_8U)
	
	var mat = CVCore.vconcat(mat1, mat2)
	
	var result := CVImgProc.find_contours(mat, CVConsts.RetrievalModes.RETR_EXTERNAL, CVConsts.ContourApproximationModes.CHAIN_APPROX_SIMPLE, {})

	assert_eq_deep(result["contours"], [PackedVector2Array([Vector2(0, 3), Vector2(0, 4), Vector2(4, 4), Vector2(4, 3)])])

func test_draw_contours():
	var mat := CVMat.zeros(5, 5, CVConsts.MatType.CV_8U)
	
	CVImgProc.draw_contours(mat, [PackedVector2Array([Vector2(0,0), Vector2(4,4)]), PackedVector2Array([Vector2(2,0), Vector2(2,4)])], -1, CVScalar.create(7), {})
	
	for i in 5:
		for j in 5:
			assert_eq(mat.get_at(i, j), 7 if i==j or j == 2 else 0)
	
func test_put_text():
	var mat := CVMat.zeros(5, 5, CVConsts.MatType.CV_8U)
	
	CVImgProc.put_text(mat, "A", Vector2(0, 5), CVConsts.HersheyFonts.FONT_HERSHEY_SIMPLEX, .25, CVScalar.create(255), {})
	
	assert_almost_eq(CVCore.mean(mat, {}).get_float(), 112.2, 0.001)

func test_moments():
	var contour := PackedVector2Array([Vector2(0, 3), Vector2(0, 4), Vector2(4, 4), Vector2(4, 3)])
	
	var result = CVImgProc.moments(contour, {})
	
	print(result)
	assert_eq(result.m00, 4.0)
	assert_eq(result.m10, 8.0)
	assert_eq(result.m01, 14.0)
	
func test_get_text_size():
	var size = CVImgProc.get_text_size("Rice", 0, 1, 1)
	
	assert_eq(size["defReturn"], Vector2(66, 22))
	assert_eq(size["baseLine"], 10)
