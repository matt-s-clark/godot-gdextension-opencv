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
	var mat1 := CVMat.eye(3, 3, CVConsts.MatType.CV_8U)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var result := CVCore.batch_distance(mat1, mat2, -1, {"K":1})
	
	var hasDist := result.has("dist")
	var hasNidx := result.has("nidx")
	
	assert_true(hasDist)
	assert_true(hasNidx)
	
	if hasDist:
		var dist : CVMat = result["dist"]
		
		for i in dist.rows:
			for j in dist.cols:
				assert_almost_eq(dist.get_at(i, j), 1.414, 0.001)
			
	if hasNidx:
		var nidx : CVMat = result["nidx"]
		
		for i in nidx.rows:
			for j in nidx.cols:
				assert_eq(nidx.get_at(i, j), 0)

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
	var mat := CVMat.zeros(3, 3, CVConsts.MatType.CV_32F)
	mat.set_at(0, 0, 42)
	
	var copy := CVCore.copy_to(mat, CVMat.new())
	mat.set_at(1, 1, 7)
	
	assert_eq(mat.get_at(0, 0), copy.get_at(0, 0))
	assert_ne(mat.get_at(1, 1), copy.get_at(1, 1))
	
func test_count_non_zero():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	var mat2 := CVMat.eye(3, 3, CVConsts.MatType.CV_32F)
	
	var result1 := CVCore.count_non_zero(mat1)
	var result2 := CVCore.count_non_zero(mat2)
	
	assert_eq(result1, 9)
	assert_eq(result2, 3)
	
func test_dct():
	var mat := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	mat.set_at(0, 0, 5)
	mat.set_at(2, 0, 12)
	
	var result := CVCore.dct(mat, {})
	
	assert_almost_eq(result.get_at(0, 0), 8.0, 0.001)
	assert_almost_eq(result.get_at(0, 1), 6.123, 0.001)
	assert_almost_eq(result.get_at(0, 2), 3.535, 0.001)
	
	var result2 := CVCore.idct(result, {})
	
	for i in 3:
		for j in 3:
			assert_almost_eq(result2.get_at(i, j), mat.get_at(i, j), 0.001)
	
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
	var mat := CVMat.eye(3, 3, CVConsts.MatType.CV_32F)
	mat.set_at(0,1,2)
	mat.set_at(2,1,5)
	
	var result := CVCore.eigen(mat)
	
	assert_true(result.has("eigenvalues"))
	assert_true(result.has("eigenvectors"))
	assert_true(result.has("defReturn"))
	
	assert_true(result["defReturn"])
	
	assert_eq(result["eigenvalues"].get_at(0, 0), 3.0)
	assert_eq(result["eigenvalues"].get_at(1, 0), 1.0)
	assert_eq(result["eigenvalues"].get_at(2, 0), -1.0)
	
	assert_almost_eq(result["eigenvectors"].get_at(0, 0), 0.707, 0.001)
	
func test_eigen_non_symmetric():
	var mat := CVMat.eye(3, 3, CVConsts.MatType.CV_32F)
	mat.set_at(0,1,2)
	mat.set_at(2,1,5)
	
	var result := CVCore.eigen_non_symmetric(mat)
	
	assert_true(result.has("eigenvalues"))
	assert_true(result.has("eigenvectors"))
	assert_false(result.has("defReturn"))
	
	assert_eq(result["eigenvalues"].get_at(0, 0), 1.0)
	assert_eq(result["eigenvalues"].get_at(1, 0), 1.0)
	assert_eq(result["eigenvalues"].get_at(2, 0), 1.0)
	
	assert_almost_eq(result["eigenvectors"].get_at(0, 0), 0.4, 0.001)
	
func test_exp():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	
	var mat2 := CVCore.exp(mat1)
	
	assert_almost_eq(mat2.get_at(0,0), 2.718, 0.001)
	
func test_extract_channel():
	var mat := CVMat.zeros(3, 3, CVConsts.MatType.CV_8UC3)
	mat.set_at(0, 0, Vector3(1, 2, 1))
	
	var result := CVCore.extract_channel(mat, 1)
	
	assert_eq(result.get_at(0,0), 2)
	
func test_find_non_zero():
	var mat := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	
	var result := CVCore.find_non_zero(mat)
	
	assert_eq(result.rows, 9)
	
	
func test_flip():
	var mat := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	
	for i in 3:
		for j in 3:
			mat.set_at(i, j, i*3 + j)
	
	var result := CVCore.flip(mat, 1)
	
	for i in 3:
		for j in 3:
			assert_eq(mat.get_at(i, j), result.get_at(i, 2-j))

func test_gemm():
	var mat := CVMat.eye(3, 3, CVConsts.MatType.CV_32F)
	
	var result := CVCore.gemm(mat, mat, 2, mat, 3, {})
	
	for i in 3:
		for j in 3:
			assert_almost_eq(result.get_at(i, j), 0.0 if i != j else 5.0, 0.001)
	
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
	var mat := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	
	var result := CVCore.dct(mat, {})
	
	assert_almost_eq(result.get_at(0, 0), 3.0, 0.001)
	assert_almost_eq(result.get_at(0, 1), 0.0, 0.001)
	assert_almost_eq(result.get_at(0, 2), 0.0, 0.001)
	
	var result2 := CVCore.idct(result, {})
	
	for i in 3:
		for j in 3:
			assert_almost_eq(result2.get_at(i, j), mat.get_at(i, j), 0.001)
	
func test_idft():
	var mat := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	
	var result := CVCore.dft(mat, {"flags":CVConsts.DftFlags.DFT_SCALE})
	
	for i in 3:
		for j in 3:
			assert_almost_eq(result.get_at(i, j), 1.0 if i == 0 and j == 0 else 0.0, 0.001)
		
	var result2 := CVCore.idft(result, {})
	
	for i in 3:
		for j in 3:
			assert_almost_eq(result2.get_at(i, j), mat.get_at(i, j), 0.001)
	
func test_in_range():
	var mat := CVMat.eye(3, 3, CVConsts.MatType.CV_32F)
	var minIn := CVMat.ones(1, 1, CVConsts.MatType.CV_32F)
	var maxIn := CVMat.ones(1, 1, CVConsts.MatType.CV_32F)
	maxIn.set_at(0,0,2)
	
	var result := CVCore.in_range(mat, minIn, maxIn)
	
	for i in 3:
		for j in 3:
			assert_eq(result.get_at(i, j), 255 if i == j else 0)
	
func test_insert_channel():
	var mat1 := CVMat.eye(3, 3, CVConsts.MatType.CV_32F)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_32FC2)
	
	CVCore.insert_channel(mat1, mat2, 1)
	
	for i in 3:
		for j in 3:
			assert_eq(mat2.get_at(i, j), Vector2(1, 1) if i == j else Vector2(1, 0))
	
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
	var mat := CVMat.eye(3, 3, CVConsts.MatType.CV_8U)
	var lut := CVMat.zeros(16, 16, CVConsts.MatType.CV_8U)
	lut.set_at(0, 0, 3)
	lut.set_at(0, 1, 2)
	
	var result := CVCore.lut(mat, lut)
	
	for i in 3:
		for j in 3:
			assert_eq(result.get_at(i, j), 2 if i == j else 3)
	
func test_magnitude():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	var mat2 := CVMat.eye(3, 3, CVConsts.MatType.CV_32F)
	
	var result = CVCore.magnitude(mat1, mat2)
	
	for i in 3:
		for j in 3:
			assert_almost_eq(result.get_at(i, j), 1.0 if i != j else 1.414, 0.001)
	
func test_mahalanobis():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_32F)
	var mat2 := CVMat.eye(3, 3, CVConsts.MatType.CV_32F)
	var mat3 := CVMat.eye(9, 9, CVConsts.MatType.CV_32F)
	
	var result = CVCore.mahalanobis(mat1, mat2, mat3)
	
	assert_almost_eq(result, 2.449, 0.001)
	
func test_max():
	var mat1 := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var mat3 := CVCore.max(mat1, mat2)
	
	assert_eq(mat3.get_at(0,0) as int, 1)
	
func test_mean():
	var mat := CVMat.eye(3, 3, CVConsts.MatType.CV_32FC3)
	
	var result := CVCore.mean(mat, {})
	
	assert_almost_eq(result.get_vector3(), Vector3(0.333, 0, 0), Vector3.ONE * 0.001)
	
func test_mean_std_dev():
	var mat := CVMat.eye(3, 3, CVConsts.MatType.CV_32FC3)
	
	var result := CVCore.mean_std_dev(mat, {})
	
	assert_true(result.has("mean"))
	assert_true(result.has("stddev"))
	
	for i in 3:
		assert_almost_eq(result["mean"].get_at(i, 0), 0.333 if i == 0 else 0.0, 0.001)
		assert_almost_eq(result["stddev"].get_at(i, 0), 0.471 if i == 0 else 0.0, 0.001)
	
func test_min():
	var mat1 := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var mat3 := CVCore.min(mat1, mat2)
	
	assert_eq(mat3.get_at(0,0) as int, 0)
	
func test_mul_spectrums():
	pass
	
func test_multiply():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var result := CVCore.multiply(mat1, mat1, {"scale":2.0})
	
	for i in 3:
		for j in 3:
			assert_eq(result.get_at(i, j), 2)
	
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
	var mat := CVMat.eye(3, 3, CVConsts.MatType.CV_32F)
	mat = CVCore.divide(mat, mat, {})
	
	CVCore.patch_nans(mat, {"val":2.0})
	
	for i in 3:
		for j in 3:
			assert_eq(mat.get_at(i, j), 1.0 if i == j else 2.0)
	
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
	var mat := CVMat.eye(3, 3, CVConsts.MatType.CV_8U)
	mat = CVCore.multiply(mat, mat, {"scale":3.0})
	
	var result := CVCore.pow(mat, 2)
	
	for i in 3:
		for j in 3:
			assert_eq(result.get_at(i, j), 9 if i == j else 0)
	
func test_psnr():
	pass
	
func test_randn():
	var mat := CVMat.eye(3, 3, CVConsts.MatType.CV_8U)
	var mean := CVMat.ones(1, 1, CVConsts.MatType.CV_8U)
	var stddev := CVMat.ones(1, 1, CVConsts.MatType.CV_8U)
	
	CVCore.set_rng_seed(999)
	CVCore.randn(mat, mean, stddev)
	assert_eq(mat.get_at(0,0), 1)
	assert_eq(mat.get_at(0,1), 1)
	assert_eq(mat.get_at(0,2), 1)
	
	assert_eq(mat.get_at(1,0), 1)
	assert_eq(mat.get_at(1,1), 1)
	assert_eq(mat.get_at(1,2), 0)
	
	assert_eq(mat.get_at(2,0), 0)
	assert_eq(mat.get_at(2,1), 0)
	assert_eq(mat.get_at(2,2), 1)
	
func test_randu():
	var mat := CVMat.eye(3, 3, CVConsts.MatType.CV_8U)
	var minIn := CVMat.zeros(1, 1, CVConsts.MatType.CV_8U)
	var maxIn := CVMat.zeros(1, 1, CVConsts.MatType.CV_8U)
	maxIn.set_at(0, 0, 255)
	
	CVCore.set_rng_seed(999)
	CVCore.randu(mat, minIn, maxIn)
	assert_eq(mat.get_at(0,0), 157)
	assert_eq(mat.get_at(0,1), 101)
	assert_eq(mat.get_at(0,2), 177)
	
	assert_eq(mat.get_at(1,0), 36)
	assert_eq(mat.get_at(1,1), 219)
	assert_eq(mat.get_at(1,2), 1)
	
	assert_eq(mat.get_at(2,0), 147)
	assert_eq(mat.get_at(2,1), 48)
	assert_eq(mat.get_at(2,2), 60)
	
func test_reduce():
	var mat := CVMat.eye(3, 3, CVConsts.MatType.CV_32F)
	
	var result := CVCore.reduce(mat, 0, CVConsts.ReduceTypes.REDUCE_AVG, {})
	
	for i in result.rows:
		for j in result.cols:
			assert_almost_eq(result.get_at(i, j), 0.333, 0.001)
		
func test_repeat():
	var mat := CVMat.eye(3, 3, CVConsts.MatType.CV_32F)
	
	var result := CVCore.repeat(mat, 2, 2)
	
	assert_eq(result.cols, 6)
	assert_eq(result.rows, 6)
	
func test_rotate():
	var mat := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	mat.set_at(0, 0, 42)
	
	var result := CVCore.rotate(mat, CVConsts.RotateFlags.ROTATE_90_CLOCKWISE)
	
	assert_eq(result.get_at(0, 2), 42)
	
func test_scale_add():
	var mat1 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	var mat2 := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var mat3 := CVCore.scale_add(mat1, 5, mat2)
	
	assert_eq(mat3.get_at(0,0), 6)
	
func test_set_identity():
	var mat := CVMat.zeros(3, 3, CVConsts.MatType.CV_8U)
	
	CVCore.set_identity(mat, {})
	
	assert_eq(mat.get_at(0, 0), 1)
	
func test_set_rng_seed():
	var mat := CVMat.eye(3, 3, CVConsts.MatType.CV_8U)
	var mean := CVMat.ones(1, 1, CVConsts.MatType.CV_8U)
	var stddev := CVMat.ones(1, 1, CVConsts.MatType.CV_8U)
	
	CVCore.set_rng_seed(1)
	CVCore.randn(mat, mean, stddev)
	assert_eq(mat.get_at(0,0), 1)
	assert_eq(mat.get_at(0,1), 2)
	assert_eq(mat.get_at(0,2), 3)
	
	assert_eq(mat.get_at(1,0), 1)
	assert_eq(mat.get_at(1,1), 1)
	assert_eq(mat.get_at(1,2), 1)
	
	assert_eq(mat.get_at(2,0), 2)
	assert_eq(mat.get_at(2,1), 0)
	assert_eq(mat.get_at(2,2), 1)
	
func test_solve():
	var sis := CVMat.eye(3, 3, CVConsts.MatType.CV_32F)
	var out := CVMat.ones(3, 1, CVConsts.MatType.CV_32F)
	sis.set_at(1, 0, 2)
	sis.set_at(0, 1, 5)
	
	var result := CVCore.solve(sis, out, {})
	
	assert_true(result.has("defReturn"))
	assert_true(result.has("dst"))
	
	if result.has("defReturn"):
		var ok : bool = result["defReturn"]
		assert_true(ok)
	
	if result.has("dst"):
		var dst : CVMat = result["dst"]
		
		assert_almost_eq(dst.get_at(0,0), 0.444, 0.001)
		assert_almost_eq(dst.get_at(1,0), 0.111, 0.001)
		assert_almost_eq(dst.get_at(2,0), 1.0, 0.001)
	
func test_solve_cubic():
	var mat := CVMat.zeros(3, 1, CVConsts.MatType.CV_32F)
	mat.set_at(2, 0, -27)
	
	var result := CVCore.solve_cubic(mat)
	
	assert_true(result.has("defReturn"))
	assert_true(result.has("roots"))
	
	if result.has("roots"):
		assert_eq(result["defReturn"], 1)
	
	if result.has("roots"):
		var roots : CVMat = result["roots"]
		
		assert_almost_eq(roots.get_at(0, 0), 3.0, 0.001)
		assert_almost_eq(roots.get_at(1, 0), 0.0, 0.001)
		assert_almost_eq(roots.get_at(2, 0), 0.0, 0.001)
	
func test_solve_poly():
	var mat := CVMat.ones(2, 1, CVConsts.MatType.CV_32F)
	
	var result := CVCore.solve_poly(mat, {})
	
	assert_true(result.has("defReturn"))
	assert_true(result.has("roots"))
	
	if result.has("defReturn"):
		assert_eq(result["defReturn"], 0.0)
	
	if result.has("roots"):
		var roots : CVMat = result["roots"]
		
		assert_eq(roots.get_at(0, 0), Vector2(-1, 0))
	
func test_sort():
	var mat := CVMat.eye(3, 3, CVConsts.MatType.CV_32F)
	
	var result := CVCore.sort(mat, CVConsts.SortFlags.SORT_EVERY_COLUMN | CVConsts.SortFlags.SORT_DESCENDING)
	
	assert_eq(result.get_at(0,0), 1.0)
	assert_eq(result.get_at(0,1), 1.0)
	assert_eq(result.get_at(0,2), 1.0)
	
func test_sort_idx():
	var mat := CVMat.eye(2, 2, CVConsts.MatType.CV_32F)
	
	var result := CVCore.sort_idx(mat, CVConsts.SortFlags.SORT_EVERY_COLUMN | CVConsts.SortFlags.SORT_DESCENDING)
	
	assert_eq(result.get_at(0,0), 0)
	assert_eq(result.get_at(0,1), 1)
	assert_eq(result.get_at(1,0), 1)
	assert_eq(result.get_at(1,1), 0)
	
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
	var mat := CVMat.ones(3, 3, CVConsts.MatType.CV_8U)
	
	var result := CVCore.sum(mat)
	
	assert_eq(int(result.get_int()), 9)
	
func test_sv_back_subst():
	pass
	
func test_sv_decomp():
	var mat := CVMat.eye(3, 4, CVConsts.MatType.CV_32F)
	mat.set_at(0, 1, 2)
	mat.set_at(2, 0, 5)
	
	var result := CVCore.sv_decomp(mat, {})
	
	var w : CVMat = result["w"]
	var u : CVMat = result["u"]
	var vt : CVMat = result["vt"]
	
	assert_almost_eq(w.get_at(0,0), 5.209, 0.001)
	assert_almost_eq(w.get_at(1,0), 2.203, 0.001)
	assert_almost_eq(w.get_at(2,0), 0.087, 0.001)
	
	assert_eq(u.rows, 3)
	assert_eq(u.cols, 3)
	
	assert_eq(vt.rows, 3)
	assert_eq(vt.cols, 4)
	
func test_trace():
	var mat := CVMat.eye(3, 4, CVConsts.MatType.CV_32F)
	
	var result := CVCore.trace(mat)
	
	assert_eq(result.get_float(), 3.0)
	
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
