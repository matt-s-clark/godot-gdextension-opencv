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
	
func test_batch_distance():
	pass
	
func test_bitwise_and():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var mat3 := CVCore.bitwise_and(mat1, mat2, {})
	
	assert_eq(mat3.get_at(0,0) as int, 1)
	
func test_bitwise_not():
	var mat1 := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	
	var mat2 := CVCore.bitwise_not(mat1, {})
	
	assert_eq(mat2.get_at(0,0) as int, 255)
	
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
	
func test_border_interpolate():
	pass
	
func test_calc_covar_matrix():
	pass
	
func test_cart_to_polar():
	pass
	
func test_compare():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	var mat2 := CVMat.eye(3, 3, CVConsts.MatType.CV_8U)
	
	var result = CVCore.compare(mat1, mat2, CVConsts.CmpTypes.CMP_EQ)
	
	for i in result.rows:
		for j in result.cols:
			if i == j:
				assert_eq(result.get_at(i,j), 255)
			else:
				assert_eq(result.get_at(i,j), 0)
	
func test_complete_symm():
	var mat := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	mat.set_at(0,2, 1)
	
	CVCore.complete_symm(mat, {})
	
	assert_eq(mat.get_at(2,0), 1)
	
func test_convert_fp_16():
	var mat := CVMat.zeros(3, 3, CVConsts.MatType.CV_32F)
	
	assert_eq(mat.type(), 5)
	
	var result = CVCore.convert_fp_16(mat)
	
	assert_eq(result.type(), 3)
	
func test_convert_scale_abs():
	pass
	
func test_copy_to():
	pass
	
func test_count_non_zero():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	var mat2 := CVMat.eye(3, 3, CVConsts.MatType.CV_32F)
	
	var result1 := CVCore.count_non_zero(mat1)
	var result2 := CVCore.count_non_zero(mat2)
	
	assert_eq(result1, 9)
	assert_eq(result2, 3)
	
func test_dct():
	pass
	
func test_determinant():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	mat1.set_at(0,2, 2)
	mat1.set_at(2,1, 3)
	mat1.set_at(1,1, -1)
	var mat2 := CVMat.eye(3, 3, CVConsts.MatType.CV_32F)
	
	var result1 := CVCore.determinant(mat1)
	var result2 := CVCore.determinant(mat2)
	
	assert_almost_eq(result1, 4.0, 0.001)
	assert_almost_eq(result2, 1.0, 0.001)
	
func test_dft():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	
	var mat2 := CVCore.dft(mat1, {})
	
	assert_almost_eq(mat2.get_at(0,0), 9.0, 0.001)
	
func test_divide():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	var mat2 := CVMat.eye(3, 3, CVConsts.MatType.CV_32F)
	mat2.set_at(0,2, 2)
	mat2.set_at(2,1, 3)
	mat2.set_at(1,1, -1)
	
	var result := CVCore.divide(mat1, mat2, {})
	
	assert_almost_eq(result.get_at(0,0), 1.0, 0.001)
	assert_almost_eq(result.get_at(0,2), 0.5, 0.001)
	assert_almost_eq(result.get_at(1,1), -1.0, 0.001)
	assert_almost_eq(result.get_at(2,1), 0.333, 0.001)
	
func test_eigen():
	pass
	
func test_eigen_non_symmetric():
	pass
	
func test_exp():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	
	var mat2 := CVCore.exp(mat1)
	
	assert_almost_eq(mat2.get_at(0,0), 2.718, 0.001)
	
func test_extract_channel():
	pass
	
func test_find_non_zero():
	var mat := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	
	var result := CVCore.find_non_zero(mat)
	
	assert_eq(result.rows, 9)
	
	
func test_flip():
	pass
	
func test_gemm():
	pass
	
func test_get_optimal_dft_size():
	var n := CVCore.get_optimal_dft_size(16)
	
	assert_eq(n, 16)

func test_hconcat():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var mat3 := CVCore.hconcat(mat1, mat2)
	
	assert_eq(mat1.cols + mat2.cols, mat3.cols)
	assert_eq(mat1.rows, mat3.rows)
	
func test_idct():
	pass
	
func test_idft():
	pass
	
func test_in_range():
	pass
	
func test_insert_channel():
	pass
	
func test_invert():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	var mat2 := CVMat.zeros(3, 3, CVConsts.MatType.CV_32F)
	var mat3 := CVMat.eye(3, 3, CVConsts.MatType.CV_32F)
	
	var result1 = CVCore.invert(mat1, {})
	var result2 = CVCore.invert(mat2, {})
	var result3 = CVCore.invert(mat3, {})
	
	assert_eq(result1["defReturn"], 0.0)
	assert_eq(result2["defReturn"], 0.0)
	assert_eq(result3["defReturn"], 1.0)
	
func test_log():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	
	var mat2 := CVCore.log(mat1)
	
	assert_almost_eq(mat2.get_at(0,0), 0.0, 0.001)
	
func test_lut():
	pass
	
func test_magnitude():
	pass
	
func test_mahalanobis():
	pass
	
func test_max():
	var mat1 := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var mat3 := CVCore.max(mat1, mat2)
	
	assert_eq(mat3.get_at(0,0) as int, 1)
	
func test_mean():
	pass
	
func test_mean_std_dev():
	pass
	
func test_min():
	var mat1 := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var mat3 := CVCore.min(mat1, mat2)
	
	assert_eq(mat3.get_at(0,0) as int, 0)
	
func test_mul_spectrums():
	pass
	
func test_multiply():
	pass
	
func test_mul_transposed():
	pass
	
func test_norm():
	pass
	
func test_normalize():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	var mat2 := CVMat.zeros(3, 3, CVConsts.MatType.CV_32F)
	
	CVCore.normalize(mat1, mat2, {})
	
	assert_almost_eq(mat2.get_at(0,0), 0.333, 0.001)
	
func test_patch_nans():
	pass
	
func test_pca_back_project():
	pass
	
func test_pca_compute():
	pass
	
func test_pca_project():
	pass
	
func test_perspective_transform():
	pass
	
func test_phase():
	pass
	
func test_polar_to_cart():
	pass
	
func test_pow():
	pass
	
func test_psnr():
	pass
	
func test_randn():
	pass
	
func test_randu():
	pass
	
func test_reduce():
	pass
	
func test_repeat():
	pass
	
func test_rotate():
	pass
	
func test_scale_add():
	pass
	
func test_set_identity():
	pass
	
func test_set_rng_seed():
	pass
	
func test_solve():
	pass
	
func test_solve_cubic():
	pass
	
func test_solve_poly():
	pass
	
func test_sort():
	pass
	
func test_sort_idx():
	pass
	
func test_sqrt():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	
	var mat2 := CVCore.sqrt(mat1)
	
	assert_almost_eq(mat2.get_at(0,0), 1.0, 0.001)
	
func test_subtract():
	var mat1 := CVMat.zeros(3, 3, CVConsts.MatType.CV_8S)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_8S)
	
	var mat3 := CVCore.subtract(mat1, mat2, {})
	
	assert_eq(mat3.get_at(0,0) as int, -1)

func test_sum():
	pass
	
func test_sv_back_subst():
	pass
	
func test_sv_decomp():
	pass
	
func test_trace():
	pass
	
func test_transpose():
	var mat1 := CVMat.ones(3, 4, CVConsts.MatType.CV_32F)
	
	var mat2 := CVCore.transpose(mat1)
	
	assert_eq(mat1.rows, mat2.cols)
	assert_eq(mat1.cols, mat2.rows)
	
func test_vconcat():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var mat3 := CVCore.vconcat(mat1, mat2)
	
	assert_eq(mat1.rows + mat2.rows, mat3.rows)
	assert_eq(mat1.cols, mat3.cols)
