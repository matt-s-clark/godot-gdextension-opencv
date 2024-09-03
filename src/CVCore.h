#ifndef CVCORE_H
#define CVCORE_H

#include "CVMat.h"
#include "Macros.h"
#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include "CVRect.h"
#include "CVScalar.h"
#include "HelperFunctions.h"

namespace godot {

class CVCore : public Object {
	GDCLASS(CVCore, Object)

private:

protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVCore();
	~CVCore();

	static Ref<CVMat> absdiff(Ref<CVMat> src1, Ref<CVMat> src2);
	static Ref<CVMat> add(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	static Ref<CVMat> add_weighted(Ref<CVMat> src1, float alpha, Ref<CVMat> src2, float beta, float gamma, Dictionary additional_parameters);
	static Dictionary batch_distance(Ref<CVMat> src1, Ref<CVMat> src2, int dtype, Dictionary additional_parameters);
	static Ref<CVMat> bitwise_and(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	static Ref<CVMat> bitwise_not(Ref<CVMat> src, Dictionary additional_parameters);
	static Ref<CVMat> bitwise_or(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	static Ref<CVMat> bitwise_xor(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	static int border_interpolate(int p, int len, int borderType);
	static Ref<CVMat> calc_covar_matrix(Ref<CVMat> samples, Ref<CVMat> mean, int flags, Dictionary additional_parameters);
	static Dictionary cart_to_polar(Ref<CVMat> x, Ref<CVMat> y, Dictionary additional_parameters);
	static Ref<CVMat> compare(Ref<CVMat> src1, Ref<CVMat> src2, int cmpop);
	static void complete_symm(Ref<CVMat> m, Dictionary additional_parameters);
	static Ref<CVMat> convert_fp_16(Ref<CVMat> src);
	static Ref<CVMat> convert_scale_abs(Ref<CVMat> src, Dictionary additional_parameters);
	static Ref<CVMat> copy_to(Ref<CVMat> src, Ref<CVMat> mask);
	static int count_non_zero(Ref<CVMat> src);
	static Ref<CVMat> dct(Ref<CVMat> src, Dictionary additional_parameters);
	static float determinant(Ref<CVMat> mtx);
	static Ref<CVMat> dft(Ref<CVMat> src, Dictionary additional_parameters);
	static Ref<CVMat> divide(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	static Dictionary eigen(Ref<CVMat> src);
	static Dictionary eigen_non_symmetric(Ref<CVMat> src);
	static Ref<CVMat> exp(Ref<CVMat> src);
	static Ref<CVMat> extract_channel(Ref<CVMat> src, int coi);
	static Ref<CVMat> find_non_zero(Ref<CVMat> src);
	static Ref<CVMat> flip(Ref<CVMat> src, int flipCode);
	static Ref<CVMat> gemm(Ref<CVMat> src1, Ref<CVMat> src2, float alpha, Ref<CVMat> src3, float beta, Dictionary additional_parameters);
	static int get_optimal_dft_size(int vecsize);
	static Ref<CVMat> hconcat(Ref<CVMat> src1, Ref<CVMat> src2);
	static Ref<CVMat> idct(Ref<CVMat> src, Dictionary additional_parameters);
	static Ref<CVMat> idft(Ref<CVMat> src, Dictionary additional_parameters);
	static Ref<CVMat> in_range(Ref<CVMat> src, Ref<CVMat> lowerb, Ref<CVMat> upperb);
	static void insert_channel(Ref<CVMat> src, Ref<CVMat> dst, int coi);
	static Dictionary invert(Ref<CVMat> src, Dictionary additional_parameters);
	static Ref<CVMat> log(Ref<CVMat> src);
	static Ref<CVMat> lut(Ref<CVMat> src, Ref<CVMat> lut);
	static Ref<CVMat> magnitude(Ref<CVMat> x, Ref<CVMat> y);
	static float mahalanobis(Ref<CVMat> v1, Ref<CVMat> v2, Ref<CVMat> icovar);
	static Ref<CVMat> max(Ref<CVMat> src1, Ref<CVMat> src2);
	static Ref<CVScalar> mean(Ref<CVMat> src, Dictionary additional_parameters);
	static Dictionary mean_std_dev(Ref<CVMat> src, Dictionary additional_parameters);
	static Ref<CVMat> min(Ref<CVMat> src1, Ref<CVMat> src2);
	static Ref<CVMat> mul_spectrums(Ref<CVMat> a, Ref<CVMat> b, int flags, Dictionary additional_parameters);
	static Ref<CVMat> multiply(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	static Ref<CVMat> mul_transposed(Ref<CVMat> src, bool aTa, Dictionary additional_parameters);
	static float norm(Ref<CVMat> src1, Dictionary additional_parameters);
	static void normalize(Ref<CVMat> src, Ref<CVMat> dst, Dictionary additional_parameters);
	static void patch_nans(Ref<CVMat> a, Dictionary additional_parameters);
	static Ref<CVMat> pca_back_project(Ref<CVMat> data, Ref<CVMat> mean, Ref<CVMat> eigenvectors);
	static Ref<CVMat> pca_compute(Ref<CVMat> data, Ref<CVMat> mean, float retainedVariance);
	static Ref<CVMat> pca_project(Ref<CVMat> data, Ref<CVMat> mean, Ref<CVMat> eigenvectors);
	static Ref<CVMat> perspective_transform(Ref<CVMat> src, Ref<CVMat> m);
	static Ref<CVMat> phase(Ref<CVMat> x, Ref<CVMat> y, Dictionary additional_parameters);
	static Dictionary polar_to_cart(Ref<CVMat> magnitude, Ref<CVMat> angle, Dictionary additional_parameters);
	static Ref<CVMat> pow(Ref<CVMat> src, float power);
	static float psnr(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	static void randn(Ref<CVMat> dst, Ref<CVMat> mean, Ref<CVMat> stddev);
	static void randu(Ref<CVMat> dst, Ref<CVMat> low, Ref<CVMat> high);
	static Ref<CVMat> reduce(Ref<CVMat> src, int dim, int rtype, Dictionary additional_parameters);
	static Ref<CVMat> repeat(Ref<CVMat> src, int ny, int nx);
	static Ref<CVMat> rotate(Ref<CVMat> src, int rotateCode);
	static Ref<CVMat> scale_add(Ref<CVMat> src1, float alpha, Ref<CVMat> src2);
	static void set_identity(Ref<CVMat> mtx, Dictionary additional_parameters);
	static void set_rng_seed(int seed);
	static Dictionary solve(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	static Dictionary solve_cubic(Ref<CVMat> coeffs);
	static Dictionary solve_poly(Ref<CVMat> coeffs, Dictionary additional_parameters);
	static Ref<CVMat> sort(Ref<CVMat> src, int flags);
	static Ref<CVMat> sort_idx(Ref<CVMat> src, int flags);
	static Ref<CVMat> sqrt(Ref<CVMat> src);
	static Ref<CVMat> subtract(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	static Ref<CVScalar> sum(Ref<CVMat> src);
	static Ref<CVMat> sv_back_subst(Ref<CVMat> w, Ref<CVMat> u, Ref<CVMat> vt, Ref<CVMat> rhs);
	static Dictionary sv_decomp(Ref<CVMat> src, Dictionary additional_parameters);
	static Ref<CVScalar> trace(Ref<CVMat> mtx);
	static Ref<CVMat> transform(Ref<CVMat> src, Ref<CVMat> m);
	static Ref<CVMat> transpose(Ref<CVMat> src);
	static Ref<CVMat> vconcat(Ref<CVMat> src1, Ref<CVMat> src2);
};

} //namespace godot

#endif