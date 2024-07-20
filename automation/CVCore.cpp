#include "CVCore.h"

using namespace godot;

void CVCore::_bind_methods() {
	ClassDB::bind_static_method(get_class_static(), D_METHOD("absdiff", "src1", "src2"), &CVCore::absdiff);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("add", "src1", "src2", "additional_parameters"), &CVCore::add);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("addWeighted", "src1", "alpha", "src2", "beta", "gamma", "additional_parameters"), &CVCore::addWeighted);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("bitwise_and", "src1", "src2", "additional_parameters"), &CVCore::bitwise_and);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("bitwise_not", "src", "additional_parameters"), &CVCore::bitwise_not);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("bitwise_or", "src1", "src2", "additional_parameters"), &CVCore::bitwise_or);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("bitwise_xor", "src1", "src2", "additional_parameters"), &CVCore::bitwise_xor);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("compare", "src1", "src2", "cmpop"), &CVCore::compare);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("convertFp16", "src"), &CVCore::convertFp16);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("dct", "src", "additional_parameters"), &CVCore::dct);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("determinant", "mtx"), &CVCore::determinant);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("dft", "src", "additional_parameters"), &CVCore::dft);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("exp", "src"), &CVCore::exp);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("findNonZero", "src"), &CVCore::findNonZero);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("flip", "src", "flipCode"), &CVCore::flip);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("getOptimalDFTSize", "vecsize"), &CVCore::getOptimalDFTSize);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("hconcat", "src1", "src2"), &CVCore::hconcat);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("idct", "src", "additional_parameters"), &CVCore::idct);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("idft", "src", "additional_parameters"), &CVCore::idft);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("invert", "src", "additional_parameters"), &CVCore::invert);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("log", "src"), &CVCore::log);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("max", "src1", "src2"), &CVCore::max);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("mean", "src", "additional_parameters"), &CVCore::mean);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("meanStdDev", "src", "additional_parameters"), &CVCore::meanStdDev);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("merge", "mv"), &CVCore::merge);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("min", "src1", "src2"), &CVCore::min);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("normalize", "src", "dst", "additional_parameters"), &CVCore::normalize);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("pow", "src", "power"), &CVCore::pow);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("reduce", "src", "dim", "rtype", "additional_parameters"), &CVCore::reduce);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("repeat", "src", "ny", "nx"), &CVCore::repeat);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("repeat", "src", "ny", "nx"), &CVCore::repeat);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("rotate", "src", "rotateCode"), &CVCore::rotate);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("setIdentity", "mtx", "additional_parameters"), &CVCore::setIdentity);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("split", "m"), &CVCore::split);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("sqrt", "src"), &CVCore::sqrt);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("subtract", "src1", "src2", "additional_parameters"), &CVCore::subtract);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("transpose", "src"), &CVCore::transpose);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("vconcat", "src1", "src2"), &CVCore::vconcat);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("countNonZero", "src"), &CVCore::countNonZero);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("flip", "src", "flipCode"), &CVCore::flip);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("invert", "src", "additional_parameters"), &CVCore::invert);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("LUT", "src", "lut"), &CVCore::LUT);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("mean", "src", "additional_parameters"), &CVCore::mean);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("merge", "mv"), &CVCore::merge);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("sum", "src"), &CVCore::sum);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("trace", "mtx"), &CVCore::trace);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("transform", "src", "m"), &CVCore::transform);
}

CVCore::CVCore() {
}

CVCore::~CVCore() {
}

Ref<CVMat> CVCore::absdiff(Ref<CVMat> src1, Ref<CVMat> src2){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::absdiff(src1->get_mat(), src2->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::add(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::add(src1->get_mat(), src2->get_mat(), dst, mask->get_mat(), dtype));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::addWeighted(Ref<CVMat> src1, float alpha, Ref<CVMat> src2, float beta, float gamma, Dictionary additional_parameters){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::addWeighted(src1->get_mat(), alpha, src2->get_mat(), beta, gamma, dst, dtype));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::bitwise_and(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::bitwise_and(src1->get_mat(), src2->get_mat(), dst, mask->get_mat()));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::bitwise_not(Ref<CVMat> src, Dictionary additional_parameters){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::bitwise_not(src->get_mat(), dst, mask->get_mat()));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::bitwise_or(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::bitwise_or(src1->get_mat(), src2->get_mat(), dst, mask->get_mat()));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::bitwise_xor(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::bitwise_xor(src1->get_mat(), src2->get_mat(), dst, mask->get_mat()));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::compare(Ref<CVMat> src1, Ref<CVMat> src2, int cmpop){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::compare(src1->get_mat(), src2->get_mat(), dst, cmpop));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::convertFp16(Ref<CVMat> src){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::convertFp16(src->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::dct(Ref<CVMat> src, Dictionary additional_parameters){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::dct(src->get_mat(), dst, flags));

	output->set_mat(dst);

	return output;
}

float CVCore::determinant(Ref<CVMat> mtx){

	float output;
	double defReturn;

	SAFE_CALL(output = cv::determinant(mtx->get_mat()));


	return output;
}

Ref<CVMat> CVCore::dft(Ref<CVMat> src, Dictionary additional_parameters){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::dft(src->get_mat(), dst, flags, nonzeroRows));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::exp(Ref<CVMat> src){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::exp(src->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::findNonZero(Ref<CVMat> src){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat idx;

	SAFE_CALL(cv::findNonZero(src->get_mat(), idx));

	output->set_mat(idx);

	return output;
}

Ref<CVMat> CVCore::flip(Ref<CVMat> src, int flipCode){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::flip(src->get_mat(), dst, flipCode));

	output->set_mat(dst);

	return output;
}

int CVCore::getOptimalDFTSize(int vecsize){

	int output;
	int defReturn;

	SAFE_CALL(output = cv::getOptimalDFTSize(vecsize));


	return output;
}

Ref<CVMat> CVCore::hconcat(Ref<CVMat> src1, Ref<CVMat> src2){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::hconcat(src1->get_mat(), src2->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::idct(Ref<CVMat> src, Dictionary additional_parameters){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::idct(src->get_mat(), dst, flags));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::idft(Ref<CVMat> src, Dictionary additional_parameters){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::idft(src->get_mat(), dst, flags, nonzeroRows));

	output->set_mat(dst);

	return output;
}

Dictionary CVCore::invert(Ref<CVMat> src, Dictionary additional_parameters){

	Dictionary output;
	double defReturn;
	cv::Mat dst;

	SAFE_CALL(defReturn = cv::invert(src->get_mat(), dst, flags));


	return output;
}

Ref<CVMat> CVCore::log(Ref<CVMat> src){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::log(src->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::max(Ref<CVMat> src1, Ref<CVMat> src2){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::max(src1->get_mat(), src2->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Color CVCore::mean(Ref<CVMat> src, Dictionary additional_parameters){

	Color output;
	Scalar defReturn;

	SAFE_CALL(defReturn = cv::mean(src->get_mat(), mask->get_mat()));

	output = Color(defReturn[0], defReturn[1], defReturn[2]);

	return output;
}

Dictionary CVCore::meanStdDev(Ref<CVMat> src, Dictionary additional_parameters){

	Dictionary output;
	cv::Mat mean;
	cv::Mat stddev;

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

	SAFE_CALL(cv::min(src1->get_mat(), src2->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

void CVCore::normalize(Ref<CVMat> src, Ref<CVMat> dst, Dictionary additional_parameters){


	SAFE_CALL(cv::normalize(src->get_mat(), dst->get_mat(), alpha, beta, norm_type, dtype, mask->get_mat()));


}

Ref<CVMat> CVCore::pow(Ref<CVMat> src, float power){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::pow(src->get_mat(), power, dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::reduce(Ref<CVMat> src, int dim, int rtype, Dictionary additional_parameters){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::reduce(src->get_mat(), dst, dim, rtype, dtype));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::repeat(Ref<CVMat> src, int ny, int nx){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::repeat(src->get_mat(), ny, nx, dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::repeat(Ref<CVMat> src, int ny, int nx){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat defReturn;

	SAFE_CALL(defReturn = cv::repeat(src->get_mat(), ny, nx));

	output->set_mat(defReturn);

	return output;
}

Ref<CVMat> CVCore::rotate(Ref<CVMat> src, int rotateCode){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::rotate(src->get_mat(), dst, rotateCode));

	output->set_mat(dst);

	return output;
}

void CVCore::setIdentity(Ref<CVMat> mtx, Dictionary additional_parameters){


	SAFE_CALL(cv::setIdentity(mtx->get_mat(), scv::Scalar(color.b, color.g, color.r) * 255));


}

Array CVCore::split(Ref<CVMat> m){

	Array output;
	Array mv;

	SAFE_CALL(cv::split(m->get_mat(), mv));


	return output;
}

Ref<CVMat> CVCore::sqrt(Ref<CVMat> src){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::sqrt(src->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::subtract(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::subtract(src1->get_mat(), src2->get_mat(), dst, mask->get_mat(), dtype));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::transpose(Ref<CVMat> src){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::transpose(src->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Ref<CVMat> CVCore::vconcat(Ref<CVMat> src1, Ref<CVMat> src2){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::vconcat(src1->get_mat(), src2->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

int CVCore::countNonZero(Ref<CVMat> src){

	int output;
	int defReturn;

	SAFE_CALL(output = cv::countNonZero(src->get_mat()));


	return output;
}

Ref<CVMat> CVCore::flip(Ref<CVMat> src, int flipCode){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::flip(src->get_mat(), dst, flipCode));

	output->set_mat(dst);

	return output;
}

Dictionary CVCore::invert(Ref<CVMat> src, Dictionary additional_parameters){

	Dictionary output;
	double defReturn;
	cv::Mat dst;

	SAFE_CALL(defReturn = cv::invert(src->get_mat(), dst, flags));


	return output;
}

Ref<CVMat> CVCore::LUT(Ref<CVMat> src, Ref<CVMat> lut){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::LUT(src->get_mat(), lut->get_mat(), dst));

	output->set_mat(dst);

	return output;
}

Color CVCore::mean(Ref<CVMat> src, Dictionary additional_parameters){

	Color output;
	Scalar defReturn;

	SAFE_CALL(defReturn = cv::mean(src->get_mat(), mask->get_mat()));

	output = Color(defReturn[0], defReturn[1], defReturn[2]);

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

Color CVCore::sum(Ref<CVMat> src){

	Color output;
	Scalar defReturn;

	SAFE_CALL(defReturn = cv::sum(src->get_mat()));

	output = Color(defReturn[0], defReturn[1], defReturn[2]);

	return output;
}

Color CVCore::trace(Ref<CVMat> mtx){

	Color output;
	Scalar defReturn;

	SAFE_CALL(defReturn = cv::trace(mtx->get_mat()));

	output = Color(defReturn[0], defReturn[1], defReturn[2]);

	return output;
}

Ref<CVMat> CVCore::transform(Ref<CVMat> src, Ref<CVMat> m){

	Ref<CVMat> output;
	output.instantiate();
	cv::Mat dst;

	SAFE_CALL(cv::transform(src->get_mat(), dst, m->get_mat()));

	output->set_mat(dst);

	return output;
}

String CVCore::_to_string() const {
	return "[ CVCore Module ]";
}
