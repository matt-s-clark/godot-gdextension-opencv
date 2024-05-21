#include "CVCore.h"

using namespace godot;

void CVCore::_bind_methods() {
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("add", "mat1", "mat2", "additional_parameters"),
			&CVCore::add);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("subtract", "mat1", "mat2", "additional_parameters"),
			&CVCore::subtract);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("max", "mat1", "mat2"),
			&CVCore::max);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("min", "mat1", "mat2"),
			&CVCore::min);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("absdiff", "mat1", "mat2"),
			&CVCore::absdiff);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("vconcat", "mat1", "mat2"),
			&CVCore::vconcat);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("hconcat", "mat1", "mat2"),
			&CVCore::hconcat);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("bitwise_and", "mat1", "mat2", "additional_parameters"),
			&CVCore::bitwise_and);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("bitwise_or", "mat1", "mat2", "additional_parameters"),
			&CVCore::bitwise_or);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("bitwise_xor", "mat1", "mat2", "additional_parameters"),
			&CVCore::bitwise_xor);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("bitwise_not", "mat", "additional_parameters"),
			&CVCore::bitwise_not);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("convert_fp16", "mat"),
			&CVCore::convert_fp16);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("exp", "mat"),
			&CVCore::exp);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("log", "mat"),
			&CVCore::log);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("sqrt", "mat"),
			&CVCore::sqrt);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("transpose", "mat"), &CVCore::transpose);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("add_weighted",
					"src1",
					"alpha",
					"src2",
					"beta",
					"gamma",
					"additional_parameters"),
			&CVCore::add_weighted);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("dft", "src", "additional_parameters"), &CVCore::dft);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("get_optimal_dft_size", "vecsize"), &CVCore::get_optimal_dft_size);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("normalize", "src", "additional_parameters"), &CVCore::normalize);
}

CVCore::CVCore() {
	UtilityFunctions::push_warning("This module should not be initialized, something is wrong");
}

CVCore::~CVCore() {
}

// Arithmetic Operations
Ref<CVMat> CVCore::add(
		Ref<CVMat> mat1,
		Ref<CVMat> mat2,
		Dictionary additional_parameters) {
	return arithmetic_wrapper(&cv::add, mat1, mat2, additional_parameters);
}

Ref<CVMat> CVCore::subtract(
		Ref<CVMat> mat1,
		Ref<CVMat> mat2,
		Dictionary additional_parameters) {
	return arithmetic_wrapper(&cv::subtract, mat1, mat2, additional_parameters);
}

Ref<CVMat> CVCore::arithmetic_wrapper(
		void (*func)(
				cv::InputArray,
				cv::InputArray,
				cv::OutputArray,
				cv::InputArray, int),
		Ref<CVMat> mat1,
		Ref<CVMat> mat2,
		Dictionary additional_parameters) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	Ref<CVMat> mask;
	int dtype = -1;

	GETADITIONALPROPERTY(additional_parameters, mask, "mask", Variant::OBJECT, "CVMat");
	GETADITIONALPROPERTY(additional_parameters, dtype, "dtype", Variant::INT, "INT");

	if (mask.is_null()) {
		mask.instantiate();
	}

	SAFECALL(func(mat1->get_mat(), mat2->get_mat(), outMat, mask->get_mat(), dtype));

	output->set_mat(outMat);

	return output;
}

// Mat in mat in mat out
Ref<CVMat> CVCore::max(
		Ref<CVMat> mat1,
		Ref<CVMat> mat2) {
	return mat_in_mat_in_mat_out_wrapper(&cv::max, mat1, mat2);
}

Ref<CVMat> CVCore::min(
		Ref<CVMat> mat1,
		Ref<CVMat> mat2) {
	return mat_in_mat_in_mat_out_wrapper(&cv::min, mat1, mat2);
}

Ref<CVMat> CVCore::absdiff(
		Ref<CVMat> mat1,
		Ref<CVMat> mat2) {
	return mat_in_mat_in_mat_out_wrapper(&cv::absdiff, mat1, mat2);
}

Ref<CVMat> CVCore::hconcat(
		Ref<CVMat> mat1,
		Ref<CVMat> mat2) {
	return mat_in_mat_in_mat_out_wrapper(&cv::hconcat, mat1, mat2);
}

Ref<CVMat> CVCore::vconcat(
		Ref<CVMat> mat1,
		Ref<CVMat> mat2) {
	return mat_in_mat_in_mat_out_wrapper(&cv::vconcat, mat1, mat2);
}

Ref<CVMat> CVCore::mat_in_mat_in_mat_out_wrapper(
		void (*func)(
				cv::InputArray,
				cv::InputArray,
				cv::OutputArray),
		Ref<CVMat> mat1,
		Ref<CVMat> mat2) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	SAFECALL(func(mat1->get_mat(), mat2->get_mat(), outMat));

	output->set_mat(outMat);

	return output;
}

// Bitwise operations
Ref<CVMat> CVCore::bitwise_and(
		Ref<CVMat> mat1,
		Ref<CVMat> mat2,
		Dictionary additional_parameters) {
	return bitwise_wrapper(&cv::bitwise_and, mat1, mat2, additional_parameters);
}

Ref<CVMat> CVCore::bitwise_or(
		Ref<CVMat> mat1,
		Ref<CVMat> mat2,
		Dictionary additional_parameters) {
	return bitwise_wrapper(&cv::bitwise_or, mat1, mat2, additional_parameters);
}

Ref<CVMat> CVCore::bitwise_xor(
		Ref<CVMat> mat1,
		Ref<CVMat> mat2,
		Dictionary additional_parameters) {
	return bitwise_wrapper(&cv::bitwise_xor, mat1, mat2, additional_parameters);
}

Ref<CVMat> CVCore::bitwise_not(
		Ref<CVMat> mat,
		Dictionary additional_parameters) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	Ref<CVMat> mask;

	GETADITIONALPROPERTY(additional_parameters, mask, "mask", Variant::OBJECT, "CVMat");

	if (mask.is_null()) {
		mask.instantiate();
	}

	SAFECALL(cv::bitwise_not(mat->get_mat(), outMat, mask->get_mat()));

	output->set_mat(outMat);

	return output;
}

Ref<CVMat> CVCore::bitwise_wrapper(
		void (*func)(
				cv::InputArray,
				cv::InputArray,
				cv::OutputArray,
				cv::InputArray),
		Ref<CVMat> mat1,
		Ref<CVMat> mat2,
		Dictionary additional_parameters) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	Ref<CVMat> mask;

	GETADITIONALPROPERTY(additional_parameters, mask, "mask", Variant::OBJECT, "CVMat");

	if (mask.is_null()) {
		mask.instantiate();
	}

	SAFECALL(func(mat1->get_mat(), mat2->get_mat(), outMat, mask->get_mat()));

	output->set_mat(outMat);

	return output;
}

// Mat in mat out
Ref<CVMat> CVCore::convert_fp16(Ref<CVMat> mat) {
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

Ref<CVMat> CVCore::mat_in_mat_out_wrapper(
		void (*func)(
				cv::InputArray,
				cv::OutputArray),
		Ref<CVMat> mat) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	SAFECALL(func(mat->get_mat(), outMat));

	output->set_mat(outMat);

	return output;
}

Ref<CVMat> CVCore::add_weighted(
		Ref<CVMat> src1,
		double alpha,
		Ref<CVMat> src2,
		double beta,
		double gamma,
		Dictionary additional_parameters) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	int dtype = -1;

	GETADITIONALPROPERTY(additional_parameters, dtype, "dtype", Variant::INT, "INT");

	SAFECALL(cv::addWeighted(
			src1->get_mat(),
			alpha,
			src2->get_mat(),
			beta,
			gamma,
			outMat,
			dtype));

	output->set_mat(outMat);

	return output;
}

Ref<CVMat> CVCore::dft(Ref<CVMat> src, Dictionary additional_parameters) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();
	int flags = 0, nonZeroRows = 0;

	GETADITIONALPROPERTY(additional_parameters, flags, "flags", Variant::INT, "INT");
	GETADITIONALPROPERTY(additional_parameters, nonZeroRows, "non_zero_rows", Variant::INT, "INT");

	SAFECALL(cv::dft(src->get_mat(), outMat, flags, nonZeroRows));

	output->set_mat(outMat);

	return output;
}

int CVCore::get_optimal_dft_size(int vecsize) {
	int output = -1;

	SAFECALL(cv::getOptimalDFTSize(vecsize));

	return output;
}

Ref<CVMat> CVCore::normalize(Ref<CVMat> src, Dictionary additional_parameters) {
	cv::Mat outMat;
	Ref<CVMat> output, mask;
	output.instantiate();
	float alpha = 1.0, beta = 0.0;
	int norm_type = 4, dtype = -1;

	GETADITIONALPROPERTY(additional_parameters, alpha, "alpha", Variant::FLOAT, "FLOAT");
	GETADITIONALPROPERTY(additional_parameters, beta, "beta", Variant::FLOAT, "FLOAT");
	GETADITIONALPROPERTY(additional_parameters, norm_type, "norm_type", Variant::INT, "INT");
	GETADITIONALPROPERTY(additional_parameters, dtype, "dtype", Variant::INT, "INT");
	GETADITIONALPROPERTY(additional_parameters, mask, "mask", Variant::OBJECT, "CVMat");

	if (mask.is_null()) {
		mask.instantiate();
	}

	SAFECALL(cv::normalize(src->get_mat(), outMat, alpha, beta, norm_type, dtype, mask->get_mat()));

	output->set_mat(outMat);

	return output;
}

String CVCore::_to_string() const {
	return "[ CVCore Module ]";
}
