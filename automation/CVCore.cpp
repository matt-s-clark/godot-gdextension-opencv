#include "CVCore.h"

using namespace godot;

void CVCore::_bind_methods() {
	ClassDB::bind_static_method(get_class_static(), D_METHOD("absdiff", "src1", "src2"), &CVCore::absdiff);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("add", "src1", "src2", "additional_parameters"), &CVCore::add);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("addWeighted", "src1", "alpha", "src2", "beta", "gamma", "additional_parameters"), &CVCore::addWeighted);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("batchDistance", "src1", "src2", "dtype", "additional_parameters"), &CVCore::batchDistance);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("bitwise_and", "src1", "src2", "additional_parameters"), &CVCore::bitwise_and);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("bitwise_not", "src", "additional_parameters"), &CVCore::bitwise_not);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("bitwise_or", "src1", "src2", "additional_parameters"), &CVCore::bitwise_or);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("bitwise_xor", "src1", "src2", "additional_parameters"), &CVCore::bitwise_xor);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("borderInterpolate", "p", "len", "borderType"), &CVCore::borderInterpolate);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("calcCovarMatrix", "samples", "mean", "flags", "additional_parameters"), &CVCore::calcCovarMatrix);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("cartToPolar", "x", "y", "additional_parameters"), &CVCore::cartToPolar);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("checkRange", "a", "additional_parameters"), &CVCore::checkRange);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("compare", "src1", "src2", "cmpop"), &CVCore::compare);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("completeSymm", "m", "additional_parameters"), &CVCore::completeSymm);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("convertFp16", "src"), &CVCore::convertFp16);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("convertScaleAbs", "src", "additional_parameters"), &CVCore::convertScaleAbs);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("copyMakeBorder", "src", "top", "bottom", "left", "right", "borderType", "additional_parameters"), &CVCore::copyMakeBorder);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("copyTo", "src", "mask"), &CVCore::copyTo);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("countNonZero", "src"), &CVCore::countNonZero);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("dct", "src", "additional_parameters"), &CVCore::dct);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("determinant", "mtx"), &CVCore::determinant);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("dft", "src", "additional_parameters"), &CVCore::dft);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("divide", "src1", "src2", "additional_parameters"), &CVCore::divide);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("eigen", "src"), &CVCore::eigen);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("eigenNonSymmetric", "src"), &CVCore::eigenNonSymmetric);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("exp", "src"), &CVCore::exp);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("extractChannel", "src", "coi"), &CVCore::extractChannel);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("findNonZero", "src"), &CVCore::findNonZero);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("flip", "src", "flipCode"), &CVCore::flip);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("flipND", "src", "axis"), &CVCore::flipND);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("gemm", "src1", "src2", "alpha", "src3", "beta", "additional_parameters"), &CVCore::gemm);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("getOptimalDFTSize", "vecsize"), &CVCore::getOptimalDFTSize);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("hasNonZero", "src"), &CVCore::hasNonZero);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("hconcat", "src1", "src2"), &CVCore::hconcat);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("idct", "src", "additional_parameters"), &CVCore::idct);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("idft", "src", "additional_parameters"), &CVCore::idft);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("inRange", "src", "lowerb", "upperb"), &CVCore::inRange);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("insertChannel", "src", "dst", "coi"), &CVCore::insertChannel);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("invert", "src", "additional_parameters"), &CVCore::invert);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("log", "src"), &CVCore::log);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("LUT", "src", "lut"), &CVCore::LUT);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("magnitude", "x", "y"), &CVCore::magnitude);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("Mahalanobis", "v1", "v2", "icovar"), &CVCore::Mahalanobis);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("max", "src1", "src2"), &CVCore::max);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("mean", "src", "additional_parameters"), &CVCore::mean);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("meanStdDev", "src", "additional_parameters"), &CVCore::meanStdDev);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("merge", "mv"), &CVCore::merge);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("min", "src1", "src2"), &CVCore::min);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("minMaxIdx", "src", "*minVal", "additional_parameters"), &CVCore::minMaxIdx);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("minMaxLoc", "src", "*minVal", "additional_parameters"), &CVCore::minMaxLoc);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("mixChannels", "*src", "nsrcs", "*dst", "ndsts", "*fromTo", "npairs"), &CVCore::mixChannels);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("mulSpectrums", "a", "b", "flags", "additional_parameters"), &CVCore::mulSpectrums);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("multiply", "src1", "src2", "additional_parameters"), &CVCore::multiply);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("mulTransposed", "src", "aTa", "additional_parameters"), &CVCore::mulTransposed);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("norm", "src1", "additional_parameters"), &CVCore::norm);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("normalize", "src", "dst", "additional_parameters"), &CVCore::normalize);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("patchNaNs", "a", "additional_parameters"), &CVCore::patchNaNs);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("PCABackProject", "data", "mean", "eigenvectors"), &CVCore::PCABackProject);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("PCACompute", "data", "mean", "retainedVariance"), &CVCore::PCACompute);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("PCAProject", "data", "mean", "eigenvectors"), &CVCore::PCAProject);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("perspectiveTransform", "src", "m"), &CVCore::perspectiveTransform);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("phase", "x", "y", "additional_parameters"), &CVCore::phase);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("polarToCart", "magnitude", "angle", "additional_parameters"), &CVCore::polarToCart);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("pow", "src", "power"), &CVCore::pow);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("PSNR", "src1", "src2", "additional_parameters"), &CVCore::PSNR);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("randn", "dst", "mean", "stddev"), &CVCore::randn);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("randShuffle", "dst", "additional_parameters"), &CVCore::randShuffle);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("randu", "dst", "low", "high"), &CVCore::randu);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("reduce", "src", "dim", "rtype", "additional_parameters"), &CVCore::reduce);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("reduceArgMax", "src", "axis", "additional_parameters"), &CVCore::reduceArgMax);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("reduceArgMin", "src", "axis", "additional_parameters"), &CVCore::reduceArgMin);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("repeat", "src", "ny", "nx"), &CVCore::repeat);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("rotate", "src", "rotateCode"), &CVCore::rotate);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("scaleAdd", "src1", "alpha", "src2"), &CVCore::scaleAdd);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("setIdentity", "mtx", "additional_parameters"), &CVCore::setIdentity);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("setRNGSeed", "seed"), &CVCore::setRNGSeed);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("solve", "src1", "src2", "additional_parameters"), &CVCore::solve);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("solveCubic", "coeffs"), &CVCore::solveCubic);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("solvePoly", "coeffs", "additional_parameters"), &CVCore::solvePoly);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("sort", "src", "flags"), &CVCore::sort);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("sortIdx", "src", "flags"), &CVCore::sortIdx);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("split", "m"), &CVCore::split);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("sqrt", "src"), &CVCore::sqrt);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("subtract", "src1", "src2", "additional_parameters"), &CVCore::subtract);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("sum", "src"), &CVCore::sum);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("SVBackSubst", "w", "u", "vt", "rhs"), &CVCore::SVBackSubst);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("SVDecomp", "src", "additional_parameters"), &CVCore::SVDecomp);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("trace", "mtx"), &CVCore::trace);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("transform", "src", "m"), &CVCore::transform);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("transpose", "src"), &CVCore::transpose);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("transposeND", "src", "additional_parameters"), &CVCore::transposeND);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("vconcat", "src1", "src2"), &CVCore::vconcat);
}

CVCore::CVCore() {
}

CVCore::~CVCore() {
}

Ref<CVMat> CVCore::absdiff(Ref<CVMat> src1, Ref<CVMat> src2){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	SAFE_CALL(cv::absdiff(src1->get_mat(), src2->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::add(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);
	GET_SIMPLE_PROPERTY(int, Variant::INT, dtype, -1);

	SAFE_CALL(cv::add(src1->get_mat(), src2->get_mat(), dst, mask->get_mat(), dtype));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::addWeighted(Ref<CVMat> src1, float alpha, Ref<CVMat> src2, float beta, float gamma, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, dtype, -1);

	SAFE_CALL(cv::addWeighted(src1->get_mat(), alpha, src2->get_mat(), beta, gamma, dst, dtype));

	output->set_mat(dst);

	return output;
}

Dictionary CVCore::batchDistance(Ref<CVMat> src1, Ref<CVMat> src2, int dtype, Dictionary additional_parameters){
	Dictionary output;
	cv::Mat dist;
	cv::Mat nidx;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, normType, cv::NORM_L2);
	GET_SIMPLE_PROPERTY(int, Variant::INT, K, 0);
	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);
	GET_SIMPLE_PROPERTY(int, Variant::INT, update, 0);
	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, crosscheck, false);

	SAFE_CALL(cv::batchDistance(src1->get_mat(), src2->get_mat(), dist, dtype, nidx, normType, K, mask->get_mat(), update, crosscheck));

	return output;
}

Ref<CVMat> CVCore::bitwise_and(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

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
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);

	SAFE_CALL(cv::bitwise_not(src->get_mat(), dst, mask->get_mat()));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::bitwise_or(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

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
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);

	SAFE_CALL(cv::bitwise_xor(src1->get_mat(), src2->get_mat(), dst, mask->get_mat()));

	output->set_mat(dst);

	return output;
}

int CVCore::borderInterpolate(int p, int len, int borderType){
	int output;
	int defReturn;

	SAFE_CALL(output = cv::borderInterpolate(p, len, borderType));

	return output;
}

Ref<CVMat> CVCore::calcCovarMatrix(Ref<CVMat> samples, Ref<CVMat> mean, int flags, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat covar;

	ERR_FAIL_NULL_V_MSG(samples, output, "samples should not be null.");
	ERR_FAIL_NULL_V_MSG(mean, output, "mean should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, ctype, cv::CV_64F);

	SAFE_CALL(cv::calcCovarMatrix(samples->get_mat(), covar, mean->get_mat(), flags, ctype));

	output->set_mat(covar);

	return output;
}

Dictionary CVCore::cartToPolar(Ref<CVMat> x, Ref<CVMat> y, Dictionary additional_parameters){
	Dictionary output;
	cv::Mat magnitude;
	cv::Mat angle;

	ERR_FAIL_NULL_V_MSG(x, output, "x should not be null.");
	ERR_FAIL_NULL_V_MSG(y, output, "y should not be null.");

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, angleInDegrees, false);

	SAFE_CALL(cv::cartToPolar(x->get_mat(), y->get_mat(), magnitude, angle, angleInDegrees));

	return output;
}

bool CVCore::checkRange(Ref<CVMat> a, Dictionary additional_parameters){
	bool output;
	bool defReturn;

	ERR_FAIL_NULL_V_MSG(a, output, "a should not be null.");

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, quiet, true);
	GET_SIMPLE_PROPERTY(Point, Variant::POINT, *pos, 0);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, minVal, cv::-DBL_MAX);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, maxVal, cv::DBL_MAX);

	SAFE_CALL(output = cv::checkRange(a->get_mat(), quiet, *pos, minVal, maxVal));

	return output;
}

Ref<CVMat> CVCore::compare(Ref<CVMat> src1, Ref<CVMat> src2, int cmpop){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	SAFE_CALL(cv::compare(src1->get_mat(), src2->get_mat(), dst, cmpop));

	output->set_mat(dst);

	return output;
}

void CVCore::completeSymm(Ref<CVMat> m, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(m, , "m should not be null.");

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, lowerToUpper, false);

	SAFE_CALL(cv::completeSymm(m->get_mat(), lowerToUpper));
}

Ref<CVMat> CVCore::convertFp16(Ref<CVMat> src){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::convertFp16(src->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::convertScaleAbs(Ref<CVMat> src, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, alpha, 1);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, beta, 0);

	SAFE_CALL(cv::convertScaleAbs(src->get_mat(), dst, alpha, beta));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::copyMakeBorder(Ref<CVMat> src, int top, int bottom, int left, int right, int borderType, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(Color, Variant::COLOR, value, cv::Scalar());

	SAFE_CALL(cv::copyMakeBorder(src->get_mat(), dst, top, bottom, left, right, borderType, valuecv::Scalar(color.b, color.g, color.r) * 255));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::copyTo(Ref<CVMat> src, Ref<CVMat> mask){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(mask, output, "mask should not be null.");

	SAFE_CALL(cv::copyTo(src->get_mat(), dst, mask->get_mat()));

	output->set_mat(dst);

	return output;
}

int CVCore::countNonZero(Ref<CVMat> src){
	int output;
	int defReturn;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(output = cv::countNonZero(src->get_mat()));

	return output;
}

Ref<CVMat> CVCore::dct(Ref<CVMat> src, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

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
	cv::Mat dst;

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
	cv::Mat dst;

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
	bool defReturn;
	cv::Mat eigenvalues;
	cv::Mat eigenvectors= noArray();

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(defReturn = cv::eigen(src->get_mat(), eigenvalues, eigenvectors));

	return output;
}

Dictionary CVCore::eigenNonSymmetric(Ref<CVMat> src){
	Dictionary output;
	cv::Mat eigenvalues;
	cv::Mat eigenvectors;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::eigenNonSymmetric(src->get_mat(), eigenvalues, eigenvectors));

	return output;
}

Ref<CVMat> CVCore::exp(Ref<CVMat> src){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::exp(src->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::extractChannel(Ref<CVMat> src, int coi){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::extractChannel(src->get_mat(), dst, coi));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::findNonZero(Ref<CVMat> src){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat idx;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::findNonZero(src->get_mat(), idx));

	output->set_mat(idx);

	return output;
}

Ref<CVMat> CVCore::flip(Ref<CVMat> src, int flipCode){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::flip(src->get_mat(), dst, flipCode));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::flipND(Ref<CVMat> src, int axis){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::flipND(src->get_mat(), dst, axis));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::gemm(Ref<CVMat> src1, Ref<CVMat> src2, float alpha, Ref<CVMat> src3, float beta, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");
	ERR_FAIL_NULL_V_MSG(src3, output, "src3 should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, 0);

	SAFE_CALL(cv::gemm(src1->get_mat(), src2->get_mat(), alpha, src3->get_mat(), beta, dst, flags));

	output->set_mat(dst);

	return output;
}

int CVCore::getOptimalDFTSize(int vecsize){
	int output;
	int defReturn;

	SAFE_CALL(output = cv::getOptimalDFTSize(vecsize));

	return output;
}

bool CVCore::hasNonZero(Ref<CVMat> src){
	bool output;
	bool defReturn;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(output = cv::hasNonZero(src->get_mat()));

	return output;
}

Ref<CVMat> CVCore::hconcat(Ref<CVMat> src1, Ref<CVMat> src2){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	SAFE_CALL(cv::hconcat(src1->get_mat(), src2->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::idct(Ref<CVMat> src, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, 0);

	SAFE_CALL(cv::idct(src->get_mat(), dst, flags));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::idft(Ref<CVMat> src, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, 0);
	GET_SIMPLE_PROPERTY(int, Variant::INT, nonzeroRows, 0);

	SAFE_CALL(cv::idft(src->get_mat(), dst, flags, nonzeroRows));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::inRange(Ref<CVMat> src, Ref<CVMat> lowerb, Ref<CVMat> upperb){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(lowerb, output, "lowerb should not be null.");
	ERR_FAIL_NULL_V_MSG(upperb, output, "upperb should not be null.");

	SAFE_CALL(cv::inRange(src->get_mat(), lowerb->get_mat(), upperb->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

void CVCore::insertChannel(Ref<CVMat> src, Ref<CVMat> dst, int coi){

	ERR_FAIL_NULL_V_MSG(src, , "src should not be null.");
	ERR_FAIL_NULL_V_MSG(dst, , "dst should not be null.");

	SAFE_CALL(cv::insertChannel(src->get_mat(), dst->get_mat(), coi));
}

Dictionary CVCore::invert(Ref<CVMat> src, Dictionary additional_parameters){
	Dictionary output;
	double defReturn;
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, cv::DECOMP_LU);

	SAFE_CALL(defReturn = cv::invert(src->get_mat(), dst, flags));

	return output;
}

Ref<CVMat> CVCore::log(Ref<CVMat> src){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::log(src->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::LUT(Ref<CVMat> src, Ref<CVMat> lut){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(lut, output, "lut should not be null.");

	SAFE_CALL(cv::LUT(src->get_mat(), lut->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::magnitude(Ref<CVMat> x, Ref<CVMat> y){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat magnitude;

	ERR_FAIL_NULL_V_MSG(x, output, "x should not be null.");
	ERR_FAIL_NULL_V_MSG(y, output, "y should not be null.");

	SAFE_CALL(cv::magnitude(x->get_mat(), y->get_mat(), magnitude));

	output->set_mat(magnitude);

	return output;
}

float CVCore::Mahalanobis(Ref<CVMat> v1, Ref<CVMat> v2, Ref<CVMat> icovar){
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
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	SAFE_CALL(cv::max(src1->get_mat(), src2->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Color CVCore::mean(Ref<CVMat> src, Dictionary additional_parameters){
	Color output;
	cv::Scalar defReturn;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);

	SAFE_CALL(defReturn = cv::mean(src->get_mat(), mask->get_mat()));

	output = Color(defReturn[0], defReturn[1], defReturn[2]);

	return output;
}

Dictionary CVCore::meanStdDev(Ref<CVMat> src, Dictionary additional_parameters){
	Dictionary output;
	cv::Mat mean;
	cv::Mat stddev;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);

	SAFE_CALL(cv::meanStdDev(src->get_mat(), mean, stddev, mask->get_mat()));

	return output;
}

Ref<CVMat> CVCore::merge(Array mv){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::merge(mv, dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::min(Ref<CVMat> src1, Ref<CVMat> src2){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	SAFE_CALL(cv::min(src1->get_mat(), src2->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

void CVCore::minMaxIdx(Ref<CVMat> src, float *minVal, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(src, , "src should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, *maxVal, 0);
	GET_SIMPLE_PROPERTY(int, Variant::INT, *minIdx, 0);
	GET_SIMPLE_PROPERTY(int, Variant::INT, *maxIdx, 0);
	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);

	SAFE_CALL(cv::minMaxIdx(src->get_mat(), *minVal, *maxVal, *minIdx, *maxIdx, mask->get_mat()));
}

void CVCore::minMaxLoc(Ref<CVMat> src, float *minVal, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(src, , "src should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, *maxVal, 0);
	GET_SIMPLE_PROPERTY(Point, Variant::POINT, *minLoc, 0);
	GET_SIMPLE_PROPERTY(Point, Variant::POINT, *maxLoc, 0);
	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);

	SAFE_CALL(cv::minMaxLoc(src->get_mat(), *minVal, *maxVal, *minLoc, *maxLoc, mask->get_mat()));
}

void CVCore::mixChannels(Ref<CVMat> *src, int nsrcs, Ref<CVMat> *dst, int ndsts, int *fromTo, int npairs){

	ERR_FAIL_NULL_V_MSG(*src, , "*src should not be null.");
	ERR_FAIL_NULL_V_MSG(*dst, , "*dst should not be null.");

	SAFE_CALL(cv::mixChannels(*src->get_mat(), nsrcs, *dst->get_mat(), ndsts, *fromTo, npairs));
}

Ref<CVMat> CVCore::mulSpectrums(Ref<CVMat> a, Ref<CVMat> b, int flags, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat c;

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
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, scale, 1);
	GET_SIMPLE_PROPERTY(int, Variant::INT, dtype, -1);

	SAFE_CALL(cv::multiply(src1->get_mat(), src2->get_mat(), dst, scale, dtype));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::mulTransposed(Ref<CVMat> src, bool aTa, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

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

	GET_SIMPLE_PROPERTY(int, Variant::INT, normType, cv::NORM_L2);
	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);

	SAFE_CALL(output = cv::norm(src1->get_mat(), normType, mask->get_mat()));

	return output;
}

void CVCore::normalize(Ref<CVMat> src, Ref<CVMat> dst, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(src, , "src should not be null.");
	ERR_FAIL_NULL_V_MSG(dst, , "dst should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, alpha, 1);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, beta, 0);
	GET_SIMPLE_PROPERTY(int, Variant::INT, norm_type, cv::NORM_L2);
	GET_SIMPLE_PROPERTY(int, Variant::INT, dtype, -1);
	GET_OBJECT_PROPERTY(Ref<CVMat>, mask);

	SAFE_CALL(cv::normalize(src->get_mat(), dst->get_mat(), alpha, beta, norm_type, dtype, mask->get_mat()));
}

void CVCore::patchNaNs(Ref<CVMat> a, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(a, , "a should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, val, 0);

	SAFE_CALL(cv::patchNaNs(a->get_mat(), val));
}

Ref<CVMat> CVCore::PCABackProject(Ref<CVMat> data, Ref<CVMat> mean, Ref<CVMat> eigenvectors){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat result;

	ERR_FAIL_NULL_V_MSG(data, output, "data should not be null.");
	ERR_FAIL_NULL_V_MSG(mean, output, "mean should not be null.");
	ERR_FAIL_NULL_V_MSG(eigenvectors, output, "eigenvectors should not be null.");

	SAFE_CALL(cv::PCABackProject(data->get_mat(), mean->get_mat(), eigenvectors->get_mat(), result));

	output->set_mat(result);

	return output;
}

Ref<CVMat> CVCore::PCACompute(Ref<CVMat> data, Ref<CVMat> mean, float retainedVariance){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat eigenvectors;

	ERR_FAIL_NULL_V_MSG(data, output, "data should not be null.");
	ERR_FAIL_NULL_V_MSG(mean, output, "mean should not be null.");

	SAFE_CALL(cv::PCACompute(data->get_mat(), mean->get_mat(), eigenvectors, retainedVariance));

	output->set_mat(eigenvectors);

	return output;
}

Ref<CVMat> CVCore::PCAProject(Ref<CVMat> data, Ref<CVMat> mean, Ref<CVMat> eigenvectors){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat result;

	ERR_FAIL_NULL_V_MSG(data, output, "data should not be null.");
	ERR_FAIL_NULL_V_MSG(mean, output, "mean should not be null.");
	ERR_FAIL_NULL_V_MSG(eigenvectors, output, "eigenvectors should not be null.");

	SAFE_CALL(cv::PCAProject(data->get_mat(), mean->get_mat(), eigenvectors->get_mat(), result));

	output->set_mat(result);

	return output;
}

Ref<CVMat> CVCore::perspectiveTransform(Ref<CVMat> src, Ref<CVMat> m){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(m, output, "m should not be null.");

	SAFE_CALL(cv::perspectiveTransform(src->get_mat(), dst, m->get_mat()));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::phase(Ref<CVMat> x, Ref<CVMat> y, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat angle;

	ERR_FAIL_NULL_V_MSG(x, output, "x should not be null.");
	ERR_FAIL_NULL_V_MSG(y, output, "y should not be null.");

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, angleInDegrees, false);

	SAFE_CALL(cv::phase(x->get_mat(), y->get_mat(), angle, angleInDegrees));

	output->set_mat(angle);

	return output;
}

Dictionary CVCore::polarToCart(Ref<CVMat> magnitude, Ref<CVMat> angle, Dictionary additional_parameters){
	Dictionary output;
	cv::Mat x;
	cv::Mat y;

	ERR_FAIL_NULL_V_MSG(magnitude, output, "magnitude should not be null.");
	ERR_FAIL_NULL_V_MSG(angle, output, "angle should not be null.");

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, angleInDegrees, false);

	SAFE_CALL(cv::polarToCart(magnitude->get_mat(), angle->get_mat(), x, y, angleInDegrees));

	return output;
}

Ref<CVMat> CVCore::pow(Ref<CVMat> src, float power){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::pow(src->get_mat(), power, dst));

	output->set_mat(dst);

	return output;
}

float CVCore::PSNR(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
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

void CVCore::randShuffle(Ref<CVMat> dst, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(dst, , "dst should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, iterFactor, 1.);
	GET_SIMPLE_PROPERTY(RNG, Variant::RNG, *rng, 0);

	SAFE_CALL(cv::randShuffle(dst->get_mat(), iterFactor, *rng));
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
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, dtype, -1);

	SAFE_CALL(cv::reduce(src->get_mat(), dst, dim, rtype, dtype));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::reduceArgMax(Ref<CVMat> src, int axis, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, lastIndex, false);

	SAFE_CALL(cv::reduceArgMax(src->get_mat(), dst, axis, lastIndex));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::reduceArgMin(Ref<CVMat> src, int axis, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, lastIndex, false);

	SAFE_CALL(cv::reduceArgMin(src->get_mat(), dst, axis, lastIndex));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::repeat(Ref<CVMat> src, int ny, int nx){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::repeat(src->get_mat(), ny, nx, dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::rotate(Ref<CVMat> src, int rotateCode){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::rotate(src->get_mat(), dst, rotateCode));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::scaleAdd(Ref<CVMat> src1, float alpha, Ref<CVMat> src2){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	SAFE_CALL(cv::scaleAdd(src1->get_mat(), alpha, src2->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

void CVCore::setIdentity(Ref<CVMat> mtx, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(mtx, , "mtx should not be null.");

	GET_SIMPLE_PROPERTY(Color, Variant::COLOR, s, cv::Scalar(1));

	SAFE_CALL(cv::setIdentity(mtx->get_mat(), scv::Scalar(color.b, color.g, color.r) * 255));
}

void CVCore::setRNGSeed(int seed){

	SAFE_CALL(cv::setRNGSeed(seed));
}

Dictionary CVCore::solve(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
	Dictionary output;
	bool defReturn;
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, cv::DECOMP_LU);

	SAFE_CALL(defReturn = cv::solve(src1->get_mat(), src2->get_mat(), dst, flags));

	return output;
}

Dictionary CVCore::solveCubic(Ref<CVMat> coeffs){
	Dictionary output;
	int defReturn;
	cv::Mat roots;

	ERR_FAIL_NULL_V_MSG(coeffs, output, "coeffs should not be null.");

	SAFE_CALL(defReturn = cv::solveCubic(coeffs->get_mat(), roots));

	return output;
}

Dictionary CVCore::solvePoly(Ref<CVMat> coeffs, Dictionary additional_parameters){
	Dictionary output;
	double defReturn;
	cv::Mat roots;

	ERR_FAIL_NULL_V_MSG(coeffs, output, "coeffs should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, maxIters, 300);

	SAFE_CALL(defReturn = cv::solvePoly(coeffs->get_mat(), roots, maxIters));

	return output;
}

Ref<CVMat> CVCore::sort(Ref<CVMat> src, int flags){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::sort(src->get_mat(), dst, flags));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::sortIdx(Ref<CVMat> src, int flags){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::sortIdx(src->get_mat(), dst, flags));

	output->set_mat(dst);

	return output;
}

Array CVCore::split(Ref<CVMat> m){
	Array output;
	Array mv;

	ERR_FAIL_NULL_V_MSG(m, output, "m should not be null.");

	SAFE_CALL(cv::split(m->get_mat(), mv));

	return output;
}

Ref<CVMat> CVCore::sqrt(Ref<CVMat> src){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::sqrt(src->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::subtract(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

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
	cv::Scalar defReturn;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(defReturn = cv::sum(src->get_mat()));

	output = Color(defReturn[0], defReturn[1], defReturn[2]);

	return output;
}

Ref<CVMat> CVCore::SVBackSubst(Ref<CVMat> w, Ref<CVMat> u, Ref<CVMat> vt, Ref<CVMat> rhs){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(w, output, "w should not be null.");
	ERR_FAIL_NULL_V_MSG(u, output, "u should not be null.");
	ERR_FAIL_NULL_V_MSG(vt, output, "vt should not be null.");
	ERR_FAIL_NULL_V_MSG(rhs, output, "rhs should not be null.");

	SAFE_CALL(cv::SVBackSubst(w->get_mat(), u->get_mat(), vt->get_mat(), rhs->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Dictionary CVCore::SVDecomp(Ref<CVMat> src, Dictionary additional_parameters){
	Dictionary output;
	cv::Mat w;
	cv::Mat u;
	cv::Mat vt;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, 0);

	SAFE_CALL(cv::SVDecomp(src->get_mat(), w, u, vt, flags));

	return output;
}

Color CVCore::trace(Ref<CVMat> mtx){
	Color output;
	cv::Scalar defReturn;

	ERR_FAIL_NULL_V_MSG(mtx, output, "mtx should not be null.");

	SAFE_CALL(defReturn = cv::trace(mtx->get_mat()));

	output = Color(defReturn[0], defReturn[1], defReturn[2]);

	return output;
}

Ref<CVMat> CVCore::transform(Ref<CVMat> src, Ref<CVMat> m){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(m, output, "m should not be null.");

	SAFE_CALL(cv::transform(src->get_mat(), dst, m->get_mat()));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::transpose(Ref<CVMat> src){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::transpose(src->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::transposeND(Ref<CVMat> src, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(vector<int, Variant::VECTOR<INT, >, cv::order);

	SAFE_CALL(cv::transposeND(src->get_mat(), >, dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::vconcat(Ref<CVMat> src1, Ref<CVMat> src2){
	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");

	SAFE_CALL(cv::vconcat(src1->get_mat(), src2->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

String CVCore::_to_string() const {
	return "[ CVCore Module ]";
}
