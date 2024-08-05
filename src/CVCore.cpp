#include "CVCore.h"

using namespace godot;
using namespace cv;

void CVCore::_bind_methods() {
	ClassDB::bind_static_method(get_class_static(), D_METHOD("absdiff", "src1", "src2"), &CVCore::absdiff);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("add", "src1", "src2", "additional_parameters"), &CVCore::add);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("add_weighted", "src1", "alpha", "src2", "beta", "gamma", "additional_parameters"), &CVCore::add_weighted);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("batch_distance", "src1", "src2", "dtype", "additional_parameters"), &CVCore::batch_distance);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("bitwise_and", "src1", "src2", "additional_parameters"), &CVCore::bitwise_and);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("bitwise_not", "src", "additional_parameters"), &CVCore::bitwise_not);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("bitwise_or", "src1", "src2", "additional_parameters"), &CVCore::bitwise_or);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("bitwise_xor", "src1", "src2", "additional_parameters"), &CVCore::bitwise_xor);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("border_interpolate", "p", "len", "borderType"), &CVCore::border_interpolate);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("calc_covar_matrix", "samples", "mean", "flags", "additional_parameters"), &CVCore::calc_covar_matrix);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("cart_to_polar", "x", "y", "additional_parameters"), &CVCore::cart_to_polar);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("compare", "src1", "src2", "cmpop"), &CVCore::compare);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("complete_symm", "m", "additional_parameters"), &CVCore::complete_symm);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("convert_fp_16", "src"), &CVCore::convert_fp_16);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("convert_scale_abs", "src", "additional_parameters"), &CVCore::convert_scale_abs);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("copy_to", "src", "mask"), &CVCore::copy_to);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("count_non_zero", "src"), &CVCore::count_non_zero);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("dct", "src", "additional_parameters"), &CVCore::dct);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("determinant", "mtx"), &CVCore::determinant);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("dft", "src", "additional_parameters"), &CVCore::dft);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("divide", "src1", "src2", "additional_parameters"), &CVCore::divide);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("eigen", "src"), &CVCore::eigen);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("eigen_non_symmetric", "src"), &CVCore::eigen_non_symmetric);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("exp", "src"), &CVCore::exp);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("extract_channel", "src", "coi"), &CVCore::extract_channel);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("find_non_zero", "src"), &CVCore::find_non_zero);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("flip", "src", "flipCode"), &CVCore::flip);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("gemm", "src1", "src2", "alpha", "src3", "beta", "additional_parameters"), &CVCore::gemm);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("get_optimal_dft_size", "vecsize"), &CVCore::get_optimal_dft_size);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("hconcat", "src1", "src2"), &CVCore::hconcat);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("idct", "src", "additional_parameters"), &CVCore::idct);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("idft", "src", "additional_parameters"), &CVCore::idft);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("in_range", "src", "lowerb", "upperb"), &CVCore::in_range);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("insert_channel", "src", "dst", "coi"), &CVCore::insert_channel);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("invert", "src", "additional_parameters"), &CVCore::invert);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("log", "src"), &CVCore::log);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("lut", "src", "lut"), &CVCore::lut);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("magnitude", "x", "y"), &CVCore::magnitude);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("mahalanobis", "v1", "v2", "icovar"), &CVCore::mahalanobis);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("max", "src1", "src2"), &CVCore::max);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("mean", "src", "additional_parameters"), &CVCore::mean);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("mean_std_dev", "src", "additional_parameters"), &CVCore::mean_std_dev);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("min", "src1", "src2"), &CVCore::min);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("mul_spectrums", "a", "b", "flags", "additional_parameters"), &CVCore::mul_spectrums);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("multiply", "src1", "src2", "additional_parameters"), &CVCore::multiply);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("mul_transposed", "src", "aTa", "additional_parameters"), &CVCore::mul_transposed);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("norm", "src1", "additional_parameters"), &CVCore::norm);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("normalize", "src", "dst", "additional_parameters"), &CVCore::normalize);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("patch_nans", "a", "additional_parameters"), &CVCore::patch_nans);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("pca_back_project", "data", "mean", "eigenvectors"), &CVCore::pca_back_project);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("pca_compute", "data", "mean", "retainedVariance"), &CVCore::pca_compute);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("pca_project", "data", "mean", "eigenvectors"), &CVCore::pca_project);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("perspective_transform", "src", "m"), &CVCore::perspective_transform);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("phase", "x", "y", "additional_parameters"), &CVCore::phase);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("polar_to_cart", "magnitude", "angle", "additional_parameters"), &CVCore::polar_to_cart);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("pow", "src", "power"), &CVCore::pow);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("psnr", "src1", "src2", "additional_parameters"), &CVCore::psnr);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("randn", "dst", "mean", "stddev"), &CVCore::randn);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("randu", "dst", "low", "high"), &CVCore::randu);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("reduce", "src", "dim", "rtype", "additional_parameters"), &CVCore::reduce);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("repeat", "src", "ny", "nx"), &CVCore::repeat);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("rotate", "src", "rotateCode"), &CVCore::rotate);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("scale_add", "src1", "alpha", "src2"), &CVCore::scale_add);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("set_identity", "mtx", "additional_parameters"), &CVCore::set_identity);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("set_rng_seed", "seed"), &CVCore::set_rng_seed);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("solve", "src1", "src2", "additional_parameters"), &CVCore::solve);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("solve_cubic", "coeffs"), &CVCore::solve_cubic);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("solve_poly", "coeffs", "additional_parameters"), &CVCore::solve_poly);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("sort", "src", "flags"), &CVCore::sort);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("sort_idx", "src", "flags"), &CVCore::sort_idx);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("sqrt", "src"), &CVCore::sqrt);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("subtract", "src1", "src2", "additional_parameters"), &CVCore::subtract);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("sum", "src"), &CVCore::sum);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("sv_back_subst", "w", "u", "vt", "rhs"), &CVCore::sv_back_subst);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("sv_decomp", "src", "additional_parameters"), &CVCore::sv_decomp);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("trace", "mtx"), &CVCore::trace);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("transform", "src", "m"), &CVCore::transform);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("transpose", "src"), &CVCore::transpose);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("vconcat", "src1", "src2"), &CVCore::vconcat);
}

CVCore::CVCore() {
}

CVCore::~CVCore() {
}

Ref<CVMat> CVCore::absdiff(Ref<CVMat> src1, Ref<CVMat> src2){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	SAFE_CALL(cv::absdiff(src1->get_mat(), src2->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::add(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);
	GET_SIMPLE_PROPERTY(int, Variant::INT, dtype, -1);

	SAFE_CALL(cv::add(src1->get_mat(), src2->get_mat(), dst, mask->get_mat(), dtype));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::add_weighted(Ref<CVMat> src1, float alpha, Ref<CVMat> src2, float beta, float gamma, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, dtype, -1);

	SAFE_CALL(cv::addWeighted(src1->get_mat(), alpha, src2->get_mat(), beta, gamma, dst, dtype));

	output->set_mat(dst);

	return output;
}

Dictionary CVCore::batch_distance(Ref<CVMat> src1, Ref<CVMat> src2, int dtype, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outdist;
	Ref<CVMat> outnidx;
	Mat dist;
	Mat nidx;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, normType, NORM_L2);
	GET_SIMPLE_PROPERTY(int, Variant::INT, K, 0);
	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);
	GET_SIMPLE_PROPERTY(int, Variant::INT, update, 0);
	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, crosscheck, false);

	SAFE_CALL(cv::batchDistance(src1->get_mat(), src2->get_mat(), dist, dtype, nidx, normType, K, mask->get_mat(), update, crosscheck));

	outdist->set_mat(dist);
	outnidx->set_mat(nidx);

	output["dist"] = outdist;
	output["nidx"] = outnidx;

	return output;
}

Ref<CVMat> CVCore::bitwise_and(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);

	SAFE_CALL(cv::bitwise_and(src1->get_mat(), src2->get_mat(), dst, mask->get_mat()));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::bitwise_not(Ref<CVMat> src, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);

	SAFE_CALL(cv::bitwise_not(src->get_mat(), dst, mask->get_mat()));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::bitwise_or(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);

	SAFE_CALL(cv::bitwise_or(src1->get_mat(), src2->get_mat(), dst, mask->get_mat()));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::bitwise_xor(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);

	SAFE_CALL(cv::bitwise_xor(src1->get_mat(), src2->get_mat(), dst, mask->get_mat()));

	output->set_mat(dst);

	return output;
}

int CVCore::border_interpolate(int p, int len, int borderType){
	int output;
	int defReturn;

	SAFE_CALL(output = cv::borderInterpolate(p, len, borderType));

	return output;
}

Ref<CVMat> CVCore::calc_covar_matrix(Ref<CVMat> samples, Ref<CVMat> mean, int flags, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat covar;

	ERR_FAIL_NULL_V_MSG(samples, output, "samples should not be null.");
	ERR_FAIL_NULL_V_MSG(mean, output, "mean should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, ctype, CV_64F);

	SAFE_CALL(cv::calcCovarMatrix(samples->get_mat(), covar, mean->get_mat(), flags, ctype));

	output->set_mat(covar);

	return output;
}

Dictionary CVCore::cart_to_polar(Ref<CVMat> x, Ref<CVMat> y, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outmagnitude;
	Ref<CVMat> outangle;
	Mat magnitude;
	Mat angle;

	ERR_FAIL_NULL_V_MSG(x, output, "x should not be null.");
	ERR_FAIL_NULL_V_MSG(y, output, "y should not be null.");

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, angleInDegrees, false);

	SAFE_CALL(cv::cartToPolar(x->get_mat(), y->get_mat(), magnitude, angle, angleInDegrees));

	outmagnitude->set_mat(magnitude);
	outangle->set_mat(angle);

	output["magnitude"] = outmagnitude;
	output["angle"] = outangle;

	return output;
}

Ref<CVMat> CVCore::compare(Ref<CVMat> src1, Ref<CVMat> src2, int cmpop){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	SAFE_CALL(cv::compare(src1->get_mat(), src2->get_mat(), dst, cmpop));

	output->set_mat(dst);

	return output;
}

void CVCore::complete_symm(Ref<CVMat> m, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(m, , "m should not be null.");

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, lowerToUpper, false);

	SAFE_CALL(cv::completeSymm(m->get_mat(), lowerToUpper));
}

Ref<CVMat> CVCore::convert_fp_16(Ref<CVMat> src){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::convertFp16(src->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::convert_scale_abs(Ref<CVMat> src, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, alpha, 1);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, beta, 0);

	SAFE_CALL(cv::convertScaleAbs(src->get_mat(), dst, alpha, beta));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::copy_to(Ref<CVMat> src, Ref<CVMat> mask){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(mask, output, "mask should not be null.");

	SAFE_CALL(cv::copyTo(src->get_mat(), dst, mask->get_mat()));

	output->set_mat(dst);

	return output;
}

int CVCore::count_non_zero(Ref<CVMat> src){
	int output;
	int defReturn;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(output = cv::countNonZero(src->get_mat()));

	return output;
}

Ref<CVMat> CVCore::dct(Ref<CVMat> src, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, 0);

	SAFE_CALL(cv::dct(src->get_mat(), dst, flags));

	output->set_mat(dst);

	return output;
}

float CVCore::determinant(Ref<CVMat> mtx){
	float output;
	double defReturn;

	ERR_FAIL_NULL_V_MSG(mtx, output, "mtx should not be null.");

	SAFE_CALL(output = cv::determinant(mtx->get_mat()));

	return output;
}

Ref<CVMat> CVCore::dft(Ref<CVMat> src, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, 0);
	GET_SIMPLE_PROPERTY(int, Variant::INT, nonzeroRows, 0);

	SAFE_CALL(cv::dft(src->get_mat(), dst, flags, nonzeroRows));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::divide(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, scale, 1);
	GET_SIMPLE_PROPERTY(int, Variant::INT, dtype, -1);

	SAFE_CALL(cv::divide(src1->get_mat(), src2->get_mat(), dst, scale, dtype));

	output->set_mat(dst);

	return output;
}

Dictionary CVCore::eigen(Ref<CVMat> src){
	Dictionary output;
	Ref<CVMat> outeigenvalues;
	Ref<CVMat> outeigenvectors;
	bool defReturn;
	Mat eigenvalues;
	Mat eigenvectors = Mat();

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(defReturn = cv::eigen(src->get_mat(), eigenvalues, eigenvectors));

	outeigenvalues->set_mat(eigenvalues);
	outeigenvectors->set_mat(eigenvectors);

	output["defReturn"] = defReturn;
	output["eigenvalues"] = outeigenvalues;
	output["eigenvectors"] = outeigenvectors;

	return output;
}

Dictionary CVCore::eigen_non_symmetric(Ref<CVMat> src){
	Dictionary output;
	Ref<CVMat> outeigenvalues;
	Ref<CVMat> outeigenvectors;
	Mat eigenvalues;
	Mat eigenvectors;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::eigenNonSymmetric(src->get_mat(), eigenvalues, eigenvectors));

	outeigenvalues->set_mat(eigenvalues);
	outeigenvectors->set_mat(eigenvectors);

	output["eigenvalues"] = outeigenvalues;
	output["eigenvectors"] = outeigenvectors;

	return output;
}

Ref<CVMat> CVCore::exp(Ref<CVMat> src){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::exp(src->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::extract_channel(Ref<CVMat> src, int coi){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::extractChannel(src->get_mat(), dst, coi));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::find_non_zero(Ref<CVMat> src){
	Ref<CVMat> output;
	output.instantiate();
	Mat idx;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::findNonZero(src->get_mat(), idx));

	output->set_mat(idx);

	return output;
}

Ref<CVMat> CVCore::flip(Ref<CVMat> src, int flipCode){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::flip(src->get_mat(), dst, flipCode));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::gemm(Ref<CVMat> src1, Ref<CVMat> src2, float alpha, Ref<CVMat> src3, float beta, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");
	ERR_FAIL_NULL_V_MSG(src3, output, "src3 should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, 0);

	SAFE_CALL(cv::gemm(src1->get_mat(), src2->get_mat(), alpha, src3->get_mat(), beta, dst, flags));

	output->set_mat(dst);

	return output;
}

int CVCore::get_optimal_dft_size(int vecsize){
	int output;
	int defReturn;

	SAFE_CALL(output = cv::getOptimalDFTSize(vecsize));

	return output;
}

Ref<CVMat> CVCore::hconcat(Ref<CVMat> src1, Ref<CVMat> src2){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	SAFE_CALL(cv::hconcat(src1->get_mat(), src2->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::idct(Ref<CVMat> src, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, 0);

	SAFE_CALL(cv::idct(src->get_mat(), dst, flags));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::idft(Ref<CVMat> src, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, 0);
	GET_SIMPLE_PROPERTY(int, Variant::INT, nonzeroRows, 0);

	SAFE_CALL(cv::idft(src->get_mat(), dst, flags, nonzeroRows));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::in_range(Ref<CVMat> src, Ref<CVMat> lowerb, Ref<CVMat> upperb){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(lowerb, output, "lowerb should not be null.");
	ERR_FAIL_NULL_V_MSG(upperb, output, "upperb should not be null.");

	SAFE_CALL(cv::inRange(src->get_mat(), lowerb->get_mat(), upperb->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

void CVCore::insert_channel(Ref<CVMat> src, Ref<CVMat> dst, int coi){

	ERR_FAIL_NULL_V_MSG(src, , "src should not be null.");
	ERR_FAIL_NULL_V_MSG(dst, , "dst should not be null.");

	SAFE_CALL(cv::insertChannel(src->get_mat(), dst->get_mat(), coi));
}

Dictionary CVCore::invert(Ref<CVMat> src, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outdst;
	double defReturn;
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, DECOMP_LU);

	SAFE_CALL(defReturn = cv::invert(src->get_mat(), dst, flags));

	outdst->set_mat(dst);

	output["defReturn"] = defReturn;
	output["dst"] = outdst;

	return output;
}

Ref<CVMat> CVCore::log(Ref<CVMat> src){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::log(src->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::lut(Ref<CVMat> src, Ref<CVMat> lut){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(lut, output, "lut should not be null.");

	SAFE_CALL(cv::LUT(src->get_mat(), lut->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::magnitude(Ref<CVMat> x, Ref<CVMat> y){
	Ref<CVMat> output;
	output.instantiate();
	Mat magnitude;

	ERR_FAIL_NULL_V_MSG(x, output, "x should not be null.");
	ERR_FAIL_NULL_V_MSG(y, output, "y should not be null.");

	SAFE_CALL(cv::magnitude(x->get_mat(), y->get_mat(), magnitude));

	output->set_mat(magnitude);

	return output;
}

float CVCore::mahalanobis(Ref<CVMat> v1, Ref<CVMat> v2, Ref<CVMat> icovar){
	float output;
	double defReturn;

	ERR_FAIL_NULL_V_MSG(v1, output, "v1 should not be null.");
	ERR_FAIL_NULL_V_MSG(v2, output, "v2 should not be null.");
	ERR_FAIL_NULL_V_MSG(icovar, output, "icovar should not be null.");

	SAFE_CALL(output = cv::Mahalanobis(v1->get_mat(), v2->get_mat(), icovar->get_mat()));

	return output;
}

Ref<CVMat> CVCore::max(Ref<CVMat> src1, Ref<CVMat> src2){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	SAFE_CALL(cv::max(src1->get_mat(), src2->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Color CVCore::mean(Ref<CVMat> src, Dictionary additional_parameters){
	Color output;
	Scalar defReturn;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);

	SAFE_CALL(defReturn = cv::mean(src->get_mat(), mask->get_mat()));

	output = Color(defReturn[0], defReturn[1], defReturn[2]);

	return output;
}

Dictionary CVCore::mean_std_dev(Ref<CVMat> src, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outmean;
	Ref<CVMat> outstddev;
	Mat mean;
	Mat stddev;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);

	SAFE_CALL(cv::meanStdDev(src->get_mat(), mean, stddev, mask->get_mat()));

	outmean->set_mat(mean);
	outstddev->set_mat(stddev);

	output["mean"] = outmean;
	output["stddev"] = outstddev;

	return output;
}

Ref<CVMat> CVCore::min(Ref<CVMat> src1, Ref<CVMat> src2){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	SAFE_CALL(cv::min(src1->get_mat(), src2->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::mul_spectrums(Ref<CVMat> a, Ref<CVMat> b, int flags, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat c;

	ERR_FAIL_NULL_V_MSG(a, output, "a should not be null.");
	ERR_FAIL_NULL_V_MSG(b, output, "b should not be null.");

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, conjB, false);

	SAFE_CALL(cv::mulSpectrums(a->get_mat(), b->get_mat(), c, flags, conjB));

	output->set_mat(c);

	return output;
}

Ref<CVMat> CVCore::multiply(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, scale, 1);
	GET_SIMPLE_PROPERTY(int, Variant::INT, dtype, -1);

	SAFE_CALL(cv::multiply(src1->get_mat(), src2->get_mat(), dst, scale, dtype));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::mul_transposed(Ref<CVMat> src, bool aTa, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, delta);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, scale, 1);
	GET_SIMPLE_PROPERTY(int, Variant::INT, dtype, -1);

	SAFE_CALL(cv::mulTransposed(src->get_mat(), dst, aTa, delta->get_mat(), scale, dtype));

	output->set_mat(dst);

	return output;
}

float CVCore::norm(Ref<CVMat> src1, Dictionary additional_parameters){
	float output;
	double defReturn;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, normType, NORM_L2);
	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);

	SAFE_CALL(output = cv::norm(src1->get_mat(), normType, mask->get_mat()));

	return output;
}

void CVCore::normalize(Ref<CVMat> src, Ref<CVMat> dst, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(src, , "src should not be null.");
	ERR_FAIL_NULL_V_MSG(dst, , "dst should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, alpha, 1);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, beta, 0);
	GET_SIMPLE_PROPERTY(int, Variant::INT, norm_type, NORM_L2);
	GET_SIMPLE_PROPERTY(int, Variant::INT, dtype, -1);
	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);

	SAFE_CALL(cv::normalize(src->get_mat(), dst->get_mat(), alpha, beta, norm_type, dtype, mask->get_mat()));
}

void CVCore::patch_nans(Ref<CVMat> a, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(a, , "a should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, val, 0);

	SAFE_CALL(cv::patchNaNs(a->get_mat(), val));
}

Ref<CVMat> CVCore::pca_back_project(Ref<CVMat> data, Ref<CVMat> mean, Ref<CVMat> eigenvectors){
	Ref<CVMat> output;
	output.instantiate();
	Mat result;

	ERR_FAIL_NULL_V_MSG(data, output, "data should not be null.");
	ERR_FAIL_NULL_V_MSG(mean, output, "mean should not be null.");
	ERR_FAIL_NULL_V_MSG(eigenvectors, output, "eigenvectors should not be null.");

	SAFE_CALL(cv::PCABackProject(data->get_mat(), mean->get_mat(), eigenvectors->get_mat(), result));

	output->set_mat(result);

	return output;
}

Ref<CVMat> CVCore::pca_compute(Ref<CVMat> data, Ref<CVMat> mean, float retainedVariance){
	Ref<CVMat> output;
	output.instantiate();
	Mat eigenvectors;

	ERR_FAIL_NULL_V_MSG(data, output, "data should not be null.");
	ERR_FAIL_NULL_V_MSG(mean, output, "mean should not be null.");

	SAFE_CALL(cv::PCACompute(data->get_mat(), mean->get_mat(), eigenvectors, retainedVariance));

	output->set_mat(eigenvectors);

	return output;
}

Ref<CVMat> CVCore::pca_project(Ref<CVMat> data, Ref<CVMat> mean, Ref<CVMat> eigenvectors){
	Ref<CVMat> output;
	output.instantiate();
	Mat result;

	ERR_FAIL_NULL_V_MSG(data, output, "data should not be null.");
	ERR_FAIL_NULL_V_MSG(mean, output, "mean should not be null.");
	ERR_FAIL_NULL_V_MSG(eigenvectors, output, "eigenvectors should not be null.");

	SAFE_CALL(cv::PCAProject(data->get_mat(), mean->get_mat(), eigenvectors->get_mat(), result));

	output->set_mat(result);

	return output;
}

Ref<CVMat> CVCore::perspective_transform(Ref<CVMat> src, Ref<CVMat> m){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(m, output, "m should not be null.");

	SAFE_CALL(cv::perspectiveTransform(src->get_mat(), dst, m->get_mat()));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::phase(Ref<CVMat> x, Ref<CVMat> y, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat angle;

	ERR_FAIL_NULL_V_MSG(x, output, "x should not be null.");
	ERR_FAIL_NULL_V_MSG(y, output, "y should not be null.");

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, angleInDegrees, false);

	SAFE_CALL(cv::phase(x->get_mat(), y->get_mat(), angle, angleInDegrees));

	output->set_mat(angle);

	return output;
}

Dictionary CVCore::polar_to_cart(Ref<CVMat> magnitude, Ref<CVMat> angle, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outx;
	Ref<CVMat> outy;
	Mat x;
	Mat y;

	ERR_FAIL_NULL_V_MSG(magnitude, output, "magnitude should not be null.");
	ERR_FAIL_NULL_V_MSG(angle, output, "angle should not be null.");

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, angleInDegrees, false);

	SAFE_CALL(cv::polarToCart(magnitude->get_mat(), angle->get_mat(), x, y, angleInDegrees));

	outx->set_mat(x);
	outy->set_mat(y);

	output["x"] = outx;
	output["y"] = outy;

	return output;
}

Ref<CVMat> CVCore::pow(Ref<CVMat> src, float power){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::pow(src->get_mat(), power, dst));

	output->set_mat(dst);

	return output;
}

float CVCore::psnr(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
	float output;
	double defReturn;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, R, 255.);

	SAFE_CALL(output = cv::PSNR(src1->get_mat(), src2->get_mat(), R));

	return output;
}

void CVCore::randn(Ref<CVMat> dst, Ref<CVMat> mean, Ref<CVMat> stddev){

	ERR_FAIL_NULL_V_MSG(dst, , "dst should not be null.");
	ERR_FAIL_NULL_V_MSG(mean, , "mean should not be null.");
	ERR_FAIL_NULL_V_MSG(stddev, , "stddev should not be null.");

	SAFE_CALL(cv::randn(dst->get_mat(), mean->get_mat(), stddev->get_mat()));
}

void CVCore::randu(Ref<CVMat> dst, Ref<CVMat> low, Ref<CVMat> high){

	ERR_FAIL_NULL_V_MSG(dst, , "dst should not be null.");
	ERR_FAIL_NULL_V_MSG(low, , "low should not be null.");
	ERR_FAIL_NULL_V_MSG(high, , "high should not be null.");

	SAFE_CALL(cv::randu(dst->get_mat(), low->get_mat(), high->get_mat()));
}

Ref<CVMat> CVCore::reduce(Ref<CVMat> src, int dim, int rtype, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, dtype, -1);

	SAFE_CALL(cv::reduce(src->get_mat(), dst, dim, rtype, dtype));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::repeat(Ref<CVMat> src, int ny, int nx){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::repeat(src->get_mat(), ny, nx, dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::rotate(Ref<CVMat> src, int rotateCode){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::rotate(src->get_mat(), dst, rotateCode));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::scale_add(Ref<CVMat> src1, float alpha, Ref<CVMat> src2){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	SAFE_CALL(cv::scaleAdd(src1->get_mat(), alpha, src2->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

void CVCore::set_identity(Ref<CVMat> mtx, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(mtx, , "mtx should not be null.");

	GET_SIMPLE_PROPERTY(Color, Variant::COLOR, s, Color());

	SAFE_CALL(cv::setIdentity(mtx->get_mat(), Scalar(s.b, s.g, s.r) * 255));
}

void CVCore::set_rng_seed(int seed){

	SAFE_CALL(cv::setRNGSeed(seed));
}

Dictionary CVCore::solve(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outdst;
	bool defReturn;
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, DECOMP_LU);

	SAFE_CALL(defReturn = cv::solve(src1->get_mat(), src2->get_mat(), dst, flags));

	outdst->set_mat(dst);

	output["defReturn"] = defReturn;
	output["dst"] = outdst;

	return output;
}

Dictionary CVCore::solve_cubic(Ref<CVMat> coeffs){
	Dictionary output;
	Ref<CVMat> outroots;
	int defReturn;
	Mat roots;

	ERR_FAIL_NULL_V_MSG(coeffs, output, "coeffs should not be null.");

	SAFE_CALL(defReturn = cv::solveCubic(coeffs->get_mat(), roots));

	outroots->set_mat(roots);

	output["defReturn"] = defReturn;
	output["roots"] = outroots;

	return output;
}

Dictionary CVCore::solve_poly(Ref<CVMat> coeffs, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outroots;
	double defReturn;
	Mat roots;

	ERR_FAIL_NULL_V_MSG(coeffs, output, "coeffs should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, maxIters, 300);

	SAFE_CALL(defReturn = cv::solvePoly(coeffs->get_mat(), roots, maxIters));

	outroots->set_mat(roots);

	output["defReturn"] = defReturn;
	output["roots"] = outroots;

	return output;
}

Ref<CVMat> CVCore::sort(Ref<CVMat> src, int flags){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::sort(src->get_mat(), dst, flags));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::sort_idx(Ref<CVMat> src, int flags){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::sortIdx(src->get_mat(), dst, flags));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::sqrt(Ref<CVMat> src){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::sqrt(src->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::subtract(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);
	GET_SIMPLE_PROPERTY(int, Variant::INT, dtype, -1);

	SAFE_CALL(cv::subtract(src1->get_mat(), src2->get_mat(), dst, mask->get_mat(), dtype));

	output->set_mat(dst);

	return output;
}

Color CVCore::sum(Ref<CVMat> src){
	Color output;
	Scalar defReturn;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(defReturn = cv::sum(src->get_mat()));

	output = Color(defReturn[0], defReturn[1], defReturn[2]);

	return output;
}

Ref<CVMat> CVCore::sv_back_subst(Ref<CVMat> w, Ref<CVMat> u, Ref<CVMat> vt, Ref<CVMat> rhs){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(w, output, "w should not be null.");
	ERR_FAIL_NULL_V_MSG(u, output, "u should not be null.");
	ERR_FAIL_NULL_V_MSG(vt, output, "vt should not be null.");
	ERR_FAIL_NULL_V_MSG(rhs, output, "rhs should not be null.");

	SAFE_CALL(cv::SVBackSubst(w->get_mat(), u->get_mat(), vt->get_mat(), rhs->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Dictionary CVCore::sv_decomp(Ref<CVMat> src, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outw;
	Ref<CVMat> outu;
	Ref<CVMat> outvt;
	Mat w;
	Mat u;
	Mat vt;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, 0);

	SAFE_CALL(cv::SVDecomp(src->get_mat(), w, u, vt, flags));

	outw->set_mat(w);
	outu->set_mat(u);
	outvt->set_mat(vt);

	output["w"] = outw;
	output["u"] = outu;
	output["vt"] = outvt;

	return output;
}

Color CVCore::trace(Ref<CVMat> mtx){
	Color output;
	Scalar defReturn;

	ERR_FAIL_NULL_V_MSG(mtx, output, "mtx should not be null.");

	SAFE_CALL(defReturn = cv::trace(mtx->get_mat()));

	output = Color(defReturn[0], defReturn[1], defReturn[2]);

	return output;
}

Ref<CVMat> CVCore::transform(Ref<CVMat> src, Ref<CVMat> m){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(m, output, "m should not be null.");

	SAFE_CALL(cv::transform(src->get_mat(), dst, m->get_mat()));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::transpose(Ref<CVMat> src){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::transpose(src->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::vconcat(Ref<CVMat> src1, Ref<CVMat> src2){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	SAFE_CALL(cv::vconcat(src1->get_mat(), src2->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

godot::String CVCore::_to_string() const {
	return "[ CVCore Module ]";
}
