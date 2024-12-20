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

	SAFE_CALL(cv::absdiff(src1->get_pointer(), src2->get_pointer(), dst));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::add(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask, Mat());
	GET_SIMPLE_PROPERTY(int, Variant::INT, dtype, -1);

	SAFE_CALL(cv::add(src1->get_pointer(), src2->get_pointer(), dst, mask->get_pointer(), dtype));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::add_weighted(Ref<CVMat> src1, float alpha, Ref<CVMat> src2, float beta, float gamma, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, dtype, -1);

	SAFE_CALL(cv::addWeighted(src1->get_pointer(), alpha, src2->get_pointer(), beta, gamma, dst, dtype));

	output->set_pointer(dst);

	return output;
}

Dictionary CVCore::batch_distance(Ref<CVMat> src1, Ref<CVMat> src2, int dtype, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outdist;
	outdist.instantiate();
	Ref<CVMat> outnidx;
	outnidx.instantiate();
	Mat dist;
	Mat nidx;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, normType, NORM_L2);
	GET_SIMPLE_PROPERTY(int, Variant::INT, K, 0);
	GET_OBJECT_PROPERTY(Ref<CVMat>, mask, Mat());
	GET_SIMPLE_PROPERTY(int, Variant::INT, update, 0);
	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, crosscheck, false);

	SAFE_CALL(cv::batchDistance(src1->get_pointer(), src2->get_pointer(), dist, dtype, nidx, normType, K, mask->get_pointer(), update, crosscheck));

	outdist->set_pointer(dist);
	outnidx->set_pointer(nidx);

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

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask, Mat());

	SAFE_CALL(cv::bitwise_and(src1->get_pointer(), src2->get_pointer(), dst, mask->get_pointer()));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::bitwise_not(Ref<CVMat> src, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask, Mat());

	SAFE_CALL(cv::bitwise_not(src->get_pointer(), dst, mask->get_pointer()));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::bitwise_or(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask, Mat());

	SAFE_CALL(cv::bitwise_or(src1->get_pointer(), src2->get_pointer(), dst, mask->get_pointer()));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::bitwise_xor(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask, Mat());

	SAFE_CALL(cv::bitwise_xor(src1->get_pointer(), src2->get_pointer(), dst, mask->get_pointer()));

	output->set_pointer(dst);

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

	SAFE_CALL(cv::calcCovarMatrix(samples->get_pointer(), covar, mean->get_pointer(), flags, ctype));

	output->set_pointer(covar);

	return output;
}

Dictionary CVCore::cart_to_polar(Ref<CVMat> x, Ref<CVMat> y, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outmagnitude;
	outmagnitude.instantiate();
	Ref<CVMat> outangle;
	outangle.instantiate();
	Mat magnitude;
	Mat angle;

	ERR_FAIL_NULL_V_MSG(x, output, "x should not be null.");
	ERR_FAIL_NULL_V_MSG(y, output, "y should not be null.");

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, angleInDegrees, false);

	SAFE_CALL(cv::cartToPolar(x->get_pointer(), y->get_pointer(), magnitude, angle, angleInDegrees));

	outmagnitude->set_pointer(magnitude);
	outangle->set_pointer(angle);

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

	SAFE_CALL(cv::compare(src1->get_pointer(), src2->get_pointer(), dst, cmpop));

	output->set_pointer(dst);

	return output;
}

void CVCore::complete_symm(Ref<CVMat> m, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(m, , "m should not be null.");

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, lowerToUpper, false);

	SAFE_CALL(cv::completeSymm(m->get_pointer(), lowerToUpper));
}

Ref<CVMat> CVCore::convert_fp_16(Ref<CVMat> src){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::convertFp16(src->get_pointer(), dst));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::convert_scale_abs(Ref<CVMat> src, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, alpha, 1);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, beta, 0);

	SAFE_CALL(cv::convertScaleAbs(src->get_pointer(), dst, alpha, beta));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::copy_to(Ref<CVMat> src, Ref<CVMat> mask){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(mask, output, "mask should not be null.");

	SAFE_CALL(cv::copyTo(src->get_pointer(), dst, mask->get_pointer()));

	output->set_pointer(dst);

	return output;
}

int CVCore::count_non_zero(Ref<CVMat> src){
	int output;
	int defReturn;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(output = cv::countNonZero(src->get_pointer()));

	return output;
}

Ref<CVMat> CVCore::dct(Ref<CVMat> src, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, 0);

	SAFE_CALL(cv::dct(src->get_pointer(), dst, flags));

	output->set_pointer(dst);

	return output;
}

float CVCore::determinant(Ref<CVMat> mtx){
	float output;
	double defReturn;

	ERR_FAIL_NULL_V_MSG(mtx, output, "mtx should not be null.");

	SAFE_CALL(output = cv::determinant(mtx->get_pointer()));

	return output;
}

Ref<CVMat> CVCore::dft(Ref<CVMat> src, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, 0);
	GET_SIMPLE_PROPERTY(int, Variant::INT, nonzeroRows, 0);

	SAFE_CALL(cv::dft(src->get_pointer(), dst, flags, nonzeroRows));

	output->set_pointer(dst);

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

	SAFE_CALL(cv::divide(src1->get_pointer(), src2->get_pointer(), dst, scale, dtype));

	output->set_pointer(dst);

	return output;
}

Dictionary CVCore::eigen(Ref<CVMat> src){
	Dictionary output;
	Ref<CVMat> outeigenvalues;
	outeigenvalues.instantiate();
	Ref<CVMat> outeigenvectors;
	outeigenvectors.instantiate();
	bool defReturn;
	Mat eigenvalues;
	Mat eigenvectors = Mat();

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(defReturn = cv::eigen(src->get_pointer(), eigenvalues, eigenvectors));

	outeigenvalues->set_pointer(eigenvalues);
	outeigenvectors->set_pointer(eigenvectors);

	output["defReturn"] = defReturn;
	output["eigenvalues"] = outeigenvalues;
	output["eigenvectors"] = outeigenvectors;

	return output;
}

Dictionary CVCore::eigen_non_symmetric(Ref<CVMat> src){
	Dictionary output;
	Ref<CVMat> outeigenvalues;
	outeigenvalues.instantiate();
	Ref<CVMat> outeigenvectors;
	outeigenvectors.instantiate();
	Mat eigenvalues;
	Mat eigenvectors;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::eigenNonSymmetric(src->get_pointer(), eigenvalues, eigenvectors));

	outeigenvalues->set_pointer(eigenvalues);
	outeigenvectors->set_pointer(eigenvectors);

	output["eigenvalues"] = outeigenvalues;
	output["eigenvectors"] = outeigenvectors;

	return output;
}

Ref<CVMat> CVCore::exp(Ref<CVMat> src){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::exp(src->get_pointer(), dst));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::extract_channel(Ref<CVMat> src, int coi){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::extractChannel(src->get_pointer(), dst, coi));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::find_non_zero(Ref<CVMat> src){
	Ref<CVMat> output;
	output.instantiate();
	Mat idx;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::findNonZero(src->get_pointer(), idx));

	output->set_pointer(idx);

	return output;
}

Ref<CVMat> CVCore::flip(Ref<CVMat> src, int flipCode){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::flip(src->get_pointer(), dst, flipCode));

	output->set_pointer(dst);

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

	SAFE_CALL(cv::gemm(src1->get_pointer(), src2->get_pointer(), alpha, src3->get_pointer(), beta, dst, flags));

	output->set_pointer(dst);

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

	SAFE_CALL(cv::hconcat(src1->get_pointer(), src2->get_pointer(), dst));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::idct(Ref<CVMat> src, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, 0);

	SAFE_CALL(cv::idct(src->get_pointer(), dst, flags));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::idft(Ref<CVMat> src, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, 0);
	GET_SIMPLE_PROPERTY(int, Variant::INT, nonzeroRows, 0);

	SAFE_CALL(cv::idft(src->get_pointer(), dst, flags, nonzeroRows));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::in_range(Ref<CVMat> src, Ref<CVMat> lowerb, Ref<CVMat> upperb){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(lowerb, output, "lowerb should not be null.");
	ERR_FAIL_NULL_V_MSG(upperb, output, "upperb should not be null.");

	SAFE_CALL(cv::inRange(src->get_pointer(), lowerb->get_pointer(), upperb->get_pointer(), dst));

	output->set_pointer(dst);

	return output;
}

void CVCore::insert_channel(Ref<CVMat> src, Ref<CVMat> dst, int coi){

	ERR_FAIL_NULL_V_MSG(src, , "src should not be null.");
	ERR_FAIL_NULL_V_MSG(dst, , "dst should not be null.");

	SAFE_CALL(cv::insertChannel(src->get_pointer(), dst->get_pointer(), coi));
}

Dictionary CVCore::invert(Ref<CVMat> src, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outdst;
	outdst.instantiate();
	double defReturn;
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, DECOMP_LU);

	SAFE_CALL(defReturn = cv::invert(src->get_pointer(), dst, flags));

	outdst->set_pointer(dst);

	output["defReturn"] = defReturn;
	output["dst"] = outdst;

	return output;
}

Ref<CVMat> CVCore::log(Ref<CVMat> src){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::log(src->get_pointer(), dst));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::lut(Ref<CVMat> src, Ref<CVMat> lut){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(lut, output, "lut should not be null.");

	SAFE_CALL(cv::LUT(src->get_pointer(), lut->get_pointer(), dst));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::magnitude(Ref<CVMat> x, Ref<CVMat> y){
	Ref<CVMat> output;
	output.instantiate();
	Mat magnitude;

	ERR_FAIL_NULL_V_MSG(x, output, "x should not be null.");
	ERR_FAIL_NULL_V_MSG(y, output, "y should not be null.");

	SAFE_CALL(cv::magnitude(x->get_pointer(), y->get_pointer(), magnitude));

	output->set_pointer(magnitude);

	return output;
}

float CVCore::mahalanobis(Ref<CVMat> v1, Ref<CVMat> v2, Ref<CVMat> icovar){
	float output;
	double defReturn;

	ERR_FAIL_NULL_V_MSG(v1, output, "v1 should not be null.");
	ERR_FAIL_NULL_V_MSG(v2, output, "v2 should not be null.");
	ERR_FAIL_NULL_V_MSG(icovar, output, "icovar should not be null.");

	SAFE_CALL(output = cv::Mahalanobis(v1->get_pointer(), v2->get_pointer(), icovar->get_pointer()));

	return output;
}

Ref<CVMat> CVCore::max(Ref<CVMat> src1, Ref<CVMat> src2){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	SAFE_CALL(cv::max(src1->get_pointer(), src2->get_pointer(), dst));

	output->set_pointer(dst);

	return output;
}

Ref<CVScalar> CVCore::mean(Ref<CVMat> src, Dictionary additional_parameters){
	Ref<CVScalar> output;
	output.instantiate();
	Scalar defReturn;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask, Mat());

	SAFE_CALL(defReturn = cv::mean(src->get_pointer(), mask->get_pointer()));

	output->set_pointer(defReturn);

	return output;
}

Dictionary CVCore::mean_std_dev(Ref<CVMat> src, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outmean;
	outmean.instantiate();
	Ref<CVMat> outstddev;
	outstddev.instantiate();
	Mat mean;
	Mat stddev;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask, Mat());

	SAFE_CALL(cv::meanStdDev(src->get_pointer(), mean, stddev, mask->get_pointer()));

	outmean->set_pointer(mean);
	outstddev->set_pointer(stddev);

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

	SAFE_CALL(cv::min(src1->get_pointer(), src2->get_pointer(), dst));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::mul_spectrums(Ref<CVMat> a, Ref<CVMat> b, int flags, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat c;

	ERR_FAIL_NULL_V_MSG(a, output, "a should not be null.");
	ERR_FAIL_NULL_V_MSG(b, output, "b should not be null.");

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, conjB, false);

	SAFE_CALL(cv::mulSpectrums(a->get_pointer(), b->get_pointer(), c, flags, conjB));

	output->set_pointer(c);

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

	SAFE_CALL(cv::multiply(src1->get_pointer(), src2->get_pointer(), dst, scale, dtype));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::mul_transposed(Ref<CVMat> src, bool aTa, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, delta, Mat());
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, scale, 1);
	GET_SIMPLE_PROPERTY(int, Variant::INT, dtype, -1);

	SAFE_CALL(cv::mulTransposed(src->get_pointer(), dst, aTa, delta->get_pointer(), scale, dtype));

	output->set_pointer(dst);

	return output;
}

float CVCore::norm(Ref<CVMat> src1, Dictionary additional_parameters){
	float output;
	double defReturn;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, normType, NORM_L2);
	GET_OBJECT_PROPERTY(Ref<CVMat>, mask, Mat());

	SAFE_CALL(output = cv::norm(src1->get_pointer(), normType, mask->get_pointer()));

	return output;
}

void CVCore::normalize(Ref<CVMat> src, Ref<CVMat> dst, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(src, , "src should not be null.");
	ERR_FAIL_NULL_V_MSG(dst, , "dst should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, alpha, 1);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, beta, 0);
	GET_SIMPLE_PROPERTY(int, Variant::INT, norm_type, NORM_L2);
	GET_SIMPLE_PROPERTY(int, Variant::INT, dtype, -1);
	GET_OBJECT_PROPERTY(Ref<CVMat>, mask, Mat());

	SAFE_CALL(cv::normalize(src->get_pointer(), dst->get_pointer(), alpha, beta, norm_type, dtype, mask->get_pointer()));
}

void CVCore::patch_nans(Ref<CVMat> a, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(a, , "a should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, val, 0);

	SAFE_CALL(cv::patchNaNs(a->get_pointer(), val));
}

Ref<CVMat> CVCore::pca_back_project(Ref<CVMat> data, Ref<CVMat> mean, Ref<CVMat> eigenvectors){
	Ref<CVMat> output;
	output.instantiate();
	Mat result;

	ERR_FAIL_NULL_V_MSG(data, output, "data should not be null.");
	ERR_FAIL_NULL_V_MSG(mean, output, "mean should not be null.");
	ERR_FAIL_NULL_V_MSG(eigenvectors, output, "eigenvectors should not be null.");

	SAFE_CALL(cv::PCABackProject(data->get_pointer(), mean->get_pointer(), eigenvectors->get_pointer(), result));

	output->set_pointer(result);

	return output;
}

Ref<CVMat> CVCore::pca_compute(Ref<CVMat> data, Ref<CVMat> mean, float retainedVariance){
	Ref<CVMat> output;
	output.instantiate();
	Mat eigenvectors;

	ERR_FAIL_NULL_V_MSG(data, output, "data should not be null.");
	ERR_FAIL_NULL_V_MSG(mean, output, "mean should not be null.");

	SAFE_CALL(cv::PCACompute(data->get_pointer(), mean->get_pointer(), eigenvectors, retainedVariance));

	output->set_pointer(eigenvectors);

	return output;
}

Ref<CVMat> CVCore::pca_project(Ref<CVMat> data, Ref<CVMat> mean, Ref<CVMat> eigenvectors){
	Ref<CVMat> output;
	output.instantiate();
	Mat result;

	ERR_FAIL_NULL_V_MSG(data, output, "data should not be null.");
	ERR_FAIL_NULL_V_MSG(mean, output, "mean should not be null.");
	ERR_FAIL_NULL_V_MSG(eigenvectors, output, "eigenvectors should not be null.");

	SAFE_CALL(cv::PCAProject(data->get_pointer(), mean->get_pointer(), eigenvectors->get_pointer(), result));

	output->set_pointer(result);

	return output;
}

Ref<CVMat> CVCore::perspective_transform(Ref<CVMat> src, Ref<CVMat> m){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(m, output, "m should not be null.");

	SAFE_CALL(cv::perspectiveTransform(src->get_pointer(), dst, m->get_pointer()));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::phase(Ref<CVMat> x, Ref<CVMat> y, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat angle;

	ERR_FAIL_NULL_V_MSG(x, output, "x should not be null.");
	ERR_FAIL_NULL_V_MSG(y, output, "y should not be null.");

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, angleInDegrees, false);

	SAFE_CALL(cv::phase(x->get_pointer(), y->get_pointer(), angle, angleInDegrees));

	output->set_pointer(angle);

	return output;
}

Dictionary CVCore::polar_to_cart(Ref<CVMat> magnitude, Ref<CVMat> angle, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outx;
	outx.instantiate();
	Ref<CVMat> outy;
	outy.instantiate();
	Mat x;
	Mat y;

	ERR_FAIL_NULL_V_MSG(magnitude, output, "magnitude should not be null.");
	ERR_FAIL_NULL_V_MSG(angle, output, "angle should not be null.");

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, angleInDegrees, false);

	SAFE_CALL(cv::polarToCart(magnitude->get_pointer(), angle->get_pointer(), x, y, angleInDegrees));

	outx->set_pointer(x);
	outy->set_pointer(y);

	output["x"] = outx;
	output["y"] = outy;

	return output;
}

Ref<CVMat> CVCore::pow(Ref<CVMat> src, float power){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::pow(src->get_pointer(), power, dst));

	output->set_pointer(dst);

	return output;
}

float CVCore::psnr(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
	float output;
	double defReturn;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, R, 255.);

	SAFE_CALL(output = cv::PSNR(src1->get_pointer(), src2->get_pointer(), R));

	return output;
}

void CVCore::randn(Ref<CVMat> dst, Ref<CVMat> mean, Ref<CVMat> stddev){

	ERR_FAIL_NULL_V_MSG(dst, , "dst should not be null.");
	ERR_FAIL_NULL_V_MSG(mean, , "mean should not be null.");
	ERR_FAIL_NULL_V_MSG(stddev, , "stddev should not be null.");

	SAFE_CALL(cv::randn(dst->get_pointer(), mean->get_pointer(), stddev->get_pointer()));
}

void CVCore::randu(Ref<CVMat> dst, Ref<CVMat> low, Ref<CVMat> high){

	ERR_FAIL_NULL_V_MSG(dst, , "dst should not be null.");
	ERR_FAIL_NULL_V_MSG(low, , "low should not be null.");
	ERR_FAIL_NULL_V_MSG(high, , "high should not be null.");

	SAFE_CALL(cv::randu(dst->get_pointer(), low->get_pointer(), high->get_pointer()));
}

Ref<CVMat> CVCore::reduce(Ref<CVMat> src, int dim, int rtype, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, dtype, -1);

	SAFE_CALL(cv::reduce(src->get_pointer(), dst, dim, rtype, dtype));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::repeat(Ref<CVMat> src, int ny, int nx){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::repeat(src->get_pointer(), ny, nx, dst));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::rotate(Ref<CVMat> src, int rotateCode){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::rotate(src->get_pointer(), dst, rotateCode));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::scale_add(Ref<CVMat> src1, float alpha, Ref<CVMat> src2){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	SAFE_CALL(cv::scaleAdd(src1->get_pointer(), alpha, src2->get_pointer(), dst));

	output->set_pointer(dst);

	return output;
}

void CVCore::set_identity(Ref<CVMat> mtx, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(mtx, , "mtx should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVScalar>, s, Scalar(1));

	SAFE_CALL(cv::setIdentity(mtx->get_pointer(), s->get_pointer()));
}

void CVCore::set_rng_seed(int seed){

	SAFE_CALL(cv::setRNGSeed(seed));
}

Dictionary CVCore::solve(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outdst;
	outdst.instantiate();
	bool defReturn;
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, DECOMP_LU);

	SAFE_CALL(defReturn = cv::solve(src1->get_pointer(), src2->get_pointer(), dst, flags));

	outdst->set_pointer(dst);

	output["defReturn"] = defReturn;
	output["dst"] = outdst;

	return output;
}

Dictionary CVCore::solve_cubic(Ref<CVMat> coeffs){
	Dictionary output;
	Ref<CVMat> outroots;
	outroots.instantiate();
	int defReturn;
	Mat roots;

	ERR_FAIL_NULL_V_MSG(coeffs, output, "coeffs should not be null.");

	SAFE_CALL(defReturn = cv::solveCubic(coeffs->get_pointer(), roots));

	outroots->set_pointer(roots);

	output["defReturn"] = defReturn;
	output["roots"] = outroots;

	return output;
}

Dictionary CVCore::solve_poly(Ref<CVMat> coeffs, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outroots;
	outroots.instantiate();
	double defReturn;
	Mat roots;

	ERR_FAIL_NULL_V_MSG(coeffs, output, "coeffs should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, maxIters, 300);

	SAFE_CALL(defReturn = cv::solvePoly(coeffs->get_pointer(), roots, maxIters));

	outroots->set_pointer(roots);

	output["defReturn"] = defReturn;
	output["roots"] = outroots;

	return output;
}

Ref<CVMat> CVCore::sort(Ref<CVMat> src, int flags){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::sort(src->get_pointer(), dst, flags));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::sort_idx(Ref<CVMat> src, int flags){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::sortIdx(src->get_pointer(), dst, flags));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::sqrt(Ref<CVMat> src){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::sqrt(src->get_pointer(), dst));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::subtract(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask, Mat());
	GET_SIMPLE_PROPERTY(int, Variant::INT, dtype, -1);

	SAFE_CALL(cv::subtract(src1->get_pointer(), src2->get_pointer(), dst, mask->get_pointer(), dtype));

	output->set_pointer(dst);

	return output;
}

Ref<CVScalar> CVCore::sum(Ref<CVMat> src){
	Ref<CVScalar> output;
	output.instantiate();
	Scalar defReturn;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(defReturn = cv::sum(src->get_pointer()));

	output->set_pointer(defReturn);

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

	SAFE_CALL(cv::SVBackSubst(w->get_pointer(), u->get_pointer(), vt->get_pointer(), rhs->get_pointer(), dst));

	output->set_pointer(dst);

	return output;
}

Dictionary CVCore::sv_decomp(Ref<CVMat> src, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outw;
	outw.instantiate();
	Ref<CVMat> outu;
	outu.instantiate();
	Ref<CVMat> outvt;
	outvt.instantiate();
	Mat w;
	Mat u;
	Mat vt;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, 0);

	SAFE_CALL(cv::SVDecomp(src->get_pointer(), w, u, vt, flags));

	outw->set_pointer(w);
	outu->set_pointer(u);
	outvt->set_pointer(vt);

	output["w"] = outw;
	output["u"] = outu;
	output["vt"] = outvt;

	return output;
}

Ref<CVScalar> CVCore::trace(Ref<CVMat> mtx){
	Ref<CVScalar> output;
	output.instantiate();
	Scalar defReturn;

	ERR_FAIL_NULL_V_MSG(mtx, output, "mtx should not be null.");

	SAFE_CALL(defReturn = cv::trace(mtx->get_pointer()));

	output->set_pointer(defReturn);

	return output;
}

Ref<CVMat> CVCore::transform(Ref<CVMat> src, Ref<CVMat> m){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(m, output, "m should not be null.");

	SAFE_CALL(cv::transform(src->get_pointer(), dst, m->get_pointer()));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::transpose(Ref<CVMat> src){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::transpose(src->get_pointer(), dst));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVCore::vconcat(Ref<CVMat> src1, Ref<CVMat> src2){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	SAFE_CALL(cv::vconcat(src1->get_pointer(), src2->get_pointer(), dst));

	output->set_pointer(dst);

	return output;
}

godot::String CVCore::_to_string() const {
	return "[ CVCore Module ]";
}
