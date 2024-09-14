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
	
	print(mat.type())
	
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
	
func test_gaussian_kernel():
	var mat := CVImgProc.get_gaussian_kernel(3, 0, {})
	
	assert_almost_eq(mat.get_at(0,0), 0.25, 0.001)
	assert_almost_eq(mat.get_at(1,0), 0.5, 0.001)
	assert_almost_eq(mat.get_at(2,0), 0.25, 0.001)

func test_box_filter():
	pass

func test_filter_2d():
	pass

func test_get_deriv_kernels():
	pass

func test_get_gaussian_kernel():
	pass

func test_morphology_default_border_value():
	pass

func test_pyr_down():
	pass

func test_pyr_up():
	pass

func test_scharr():
	pass

func test_sep_filter_2d():
	pass

func test_spatial_gradient():
	pass

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
	pass

func test_distance_transform():
	pass

func test_integral():
	pass

func test_arrowed_line():
	pass

func test_circle():
	pass

func test_draw_marker():
	pass

func test_ellipse():
	var mat := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	CVImgProc.ellipse(mat, Vector2.ZERO, Vector2.ONE, 0, 0, 360, CVScalar.create(5), {})
	
	assert_eq(mat.get_at(0, 1), 5)
	assert_eq(mat.get_at(1, 0), 5)

func test_fill_convex_poly():
	pass

func test_get_font_scale_from_height():
	pass

func test_line():
	var mat := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	CVImgProc.line(mat, Vector2.ZERO, Vector2.ONE, CVScalar.create(5), {})
	
	assert_eq(mat.get_at(0, 0), 5)
	assert_eq(mat.get_at(1, 1), 5)

func test_demosaicing():
	pass

func test_apply_color_map():
	pass

func test_compare_hist():
	pass

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
	
	for i in result.rows:
		for j in result.cols:
			print(result.get_at(i, j))
		print()
	
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
	pass

func test_corner_eigen_vals_and_vecs():
	pass

func test_corner_harris():
	pass

func test_corner_min_eigen_val():
	pass

func test_good_features_to_track():
	pass

func test_hough_circles():
	pass

func test_hough_lines():
	pass

func test_hough_lines_p():
	pass

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

