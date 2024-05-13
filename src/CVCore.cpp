#include "CVCore.h"

using namespace godot;

void CVCore::_bind_methods() {
	ClassDB::bind_static_method("CVCore", D_METHOD("add"), &CVCore::add, "mat1",
			"mat2", "mask", "dType");
	ClassDB::bind_static_method("CVCore", D_METHOD("subtract"), &CVCore::subtract,
			"mat1", "mat2", "mask", "dType");
	ClassDB::bind_static_method("CVCore", D_METHOD("max"), &CVCore::max, "mat1",
			"mat2");
	ClassDB::bind_static_method("CVCore", D_METHOD("min"), &CVCore::min, "mat1",
			"mat2");
	ClassDB::bind_static_method("CVCore", D_METHOD("absdiff"), &CVCore::absdiff,
			"mat1", "mat2");
	ClassDB::bind_static_method("CVCore", D_METHOD("vconcat"), &CVCore::vconcat,
			"mat1", "mat2");
	ClassDB::bind_static_method("CVCore", D_METHOD("hconcat"), &CVCore::hconcat,
			"mat1", "mat2");
	ClassDB::bind_static_method("CVCore", D_METHOD("bitwise_and"),
			&CVCore::bitwise_and, "mat1", "mat2", "mask");
	ClassDB::bind_static_method("CVCore", D_METHOD("bitwise_or"), &CVCore::bitwise_or,
			"mat1", "mat2", "mask");
	ClassDB::bind_static_method("CVCore", D_METHOD("bitwise_xor"),
			&CVCore::bitwise_xor, "mat1", "mat2", "mask");
	ClassDB::bind_static_method("CVCore", D_METHOD("bitwise_not"),
			&CVCore::bitwise_not, "mat", "mask");
	ClassDB::bind_static_method("CVCore", D_METHOD("convertFp16"),
			&CVCore::convertFp16, "mat");
	ClassDB::bind_static_method("CVCore", D_METHOD("exp"), &CVCore::exp, "mat");
	ClassDB::bind_static_method("CVCore", D_METHOD("log"), &CVCore::log, "mat");
	ClassDB::bind_static_method("CVCore", D_METHOD("sqrt"), &CVCore::sqrt, "mat");
	ClassDB::bind_static_method("CVCore", D_METHOD("transpose"), &CVCore::transpose,
			"mat");
}

CVCore::CVCore() {
}

CVCore::~CVCore() {
}

// Arithmetic Operations
Ref<CVMat> CVCore::add(Ref<CVMat> mat1, Ref<CVMat> mat2, Ref<CVMat> mask, int dtype) {
	return arithmetic_wrapper(&cv::add, mat1, mat2, mask, dtype);
}

Ref<CVMat> CVCore::subtract(Ref<CVMat> mat1, Ref<CVMat> mat2, Ref<CVMat> mask, int dtype) {
	return arithmetic_wrapper(&cv::subtract, mat1, mat2, mask, dtype);
}

Ref<CVMat> CVCore::arithmetic_wrapper(void (*func)(cv::InputArray, cv::InputArray,
											  cv::OutputArray, cv::InputArray, int),
		Ref<CVMat> mat1, Ref<CVMat> mat2, Ref<CVMat> mask, int dtype) {
	cv::Mat outMat;
	Ref<CVMat> output = Ref<CVMat>(memnew(CVMat));

	if (mask.is_null()) {
		mask = Ref<CVMat>(memnew(CVMat));
	}

	SAFECALL(func(mat1->get_mat(), mat2->get_mat(), outMat, mask->get_mat(), dtype));

	output->set_mat(outMat);

	return output;
}

// Mat in mat in mat out
Ref<CVMat> CVCore::max(Ref<CVMat> mat1, Ref<CVMat> mat2) {
	return mat_in_mat_in_mat_out_wrapper(&cv::max, mat1, mat2);
}

Ref<CVMat> CVCore::min(Ref<CVMat> mat1, Ref<CVMat> mat2) {
	return mat_in_mat_in_mat_out_wrapper(&cv::min, mat1, mat2);
}

Ref<CVMat> CVCore::absdiff(Ref<CVMat> mat1, Ref<CVMat> mat2) {
	return mat_in_mat_in_mat_out_wrapper(&cv::absdiff, mat1, mat2);
}

Ref<CVMat> CVCore::hconcat(Ref<CVMat> mat1, Ref<CVMat> mat2) {
	return mat_in_mat_in_mat_out_wrapper(&cv::hconcat, mat1, mat2);
}

Ref<CVMat> CVCore::vconcat(Ref<CVMat> mat1, Ref<CVMat> mat2) {
	return mat_in_mat_in_mat_out_wrapper(&cv::vconcat, mat1, mat2);
}

Ref<CVMat> CVCore::mat_in_mat_in_mat_out_wrapper(void (*func)(cv::InputArray, cv::InputArray,
														 cv::OutputArray),
		Ref<CVMat> mat1, Ref<CVMat> mat2) {
	cv::Mat outMat;
	Ref<CVMat> output = Ref<CVMat>(memnew(CVMat));

	SAFECALL(func(mat1->get_mat(), mat2->get_mat(), outMat));

	output->set_mat(outMat);

	return output;
}

// Bitwise operations
Ref<CVMat> CVCore::bitwise_and(Ref<CVMat> mat1, Ref<CVMat> mat2, Ref<CVMat> mask) {
	return bitwise_wrapper(&cv::bitwise_and, mat1, mat2, mask);
}

Ref<CVMat> CVCore::bitwise_or(Ref<CVMat> mat1, Ref<CVMat> mat2, Ref<CVMat> mask) {
	return bitwise_wrapper(&cv::bitwise_or, mat1, mat2, mask);
}

Ref<CVMat> CVCore::bitwise_xor(Ref<CVMat> mat1, Ref<CVMat> mat2, Ref<CVMat> mask) {
	return bitwise_wrapper(&cv::bitwise_xor, mat1, mat2, mask);
}

Ref<CVMat> CVCore::bitwise_not(Ref<CVMat> mat, Ref<CVMat> mask) {
	cv::Mat outMat;
	Ref<CVMat> output = Ref<CVMat>(memnew(CVMat));

	if (mask.is_null()) {
		mask = Ref<CVMat>(memnew(CVMat));
	}

	SAFECALL(cv::bitwise_not(mat->get_mat(), outMat, mask->get_mat()));

	output->set_mat(outMat);

	return output;
}

Ref<CVMat> CVCore::bitwise_wrapper(void (*func)(cv::InputArray, cv::InputArray,
										   cv::OutputArray, cv::InputArray),
		Ref<CVMat> mat1, Ref<CVMat> mat2, Ref<CVMat> mask) {
	cv::Mat outMat;
	Ref<CVMat> output = Ref<CVMat>(memnew(CVMat));

	if (mask.is_null()) {
		mask = Ref<CVMat>(memnew(CVMat));
	}

	SAFECALL(func(mat1->get_mat(), mat2->get_mat(), outMat, mask->get_mat()));

	output->set_mat(outMat);

	return output;
}

// Mat in mat out
Ref<CVMat> CVCore::convertFp16(Ref<CVMat> mat) {
	return mat_in_mat_out_wrapper(&cv::convertFp16, mat);
}

Ref<CVMat> CVCore::exp(Ref<CVMat> mat) {
	return mat_in_mat_out_wrapper(&cv::exp, mat);
}

Ref<CVMat> CVCore::log(Ref<CVMat> mat) {
	return mat_in_mat_out_wrapper(&cv::log, mat);
}

Ref<CVMat> CVCore::sqrt(Ref<CVMat> mat) {
	return mat_in_mat_out_wrapper(&cv::sqrt, mat);
}

Ref<CVMat> CVCore::transpose(Ref<CVMat> mat) {
	return mat_in_mat_out_wrapper(&cv::transpose, mat);
}

Ref<CVMat> CVCore::mat_in_mat_out_wrapper(void (*func)(cv::InputArray, cv::OutputArray),
		Ref<CVMat> mat) {
	cv::Mat outMat;
	Ref<CVMat> output = Ref<CVMat>(memnew(CVMat));

	SAFECALL(func(mat->get_mat(), outMat));

	output->set_mat(outMat);

	return output;
}
