#include "CVImgCodecs.h"

using namespace godot;

void CVImgCodecs::_bind_methods() {
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("imread", "filename", "additional_parameters"),
			&CVImgCodecs::imread);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("imwrite", "filename", "img", "additional_parameters"),
			&CVImgCodecs::imwrite);
}

CVImgCodecs::CVImgCodecs() {
	UtilityFunctions::push_warning("This module should not be initialized, something is wrong");
}

CVImgCodecs::~CVImgCodecs() {
}

Ref<CVMat> CVImgCodecs::imread(
		const String filename,
		Dictionary additional_parameters) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();
	cv::String path(filename.utf8());

	int flags = cv::IMREAD_COLOR;

	GET_ADITIONAL_PROPERTY(additional_parameters, flags, "flags", Variant::INT, "INT");

	SAFE_CALL(outMat = cv::imread(path, flags));

	output->set_mat(outMat);

	return output;
}

bool CVImgCodecs::imwrite(
		const String filename,
		Ref<CVMat> img,
		Dictionary additional_parameters) {
	bool output = false;
	cv::String path(filename.utf8());
	std::vector<int> p;
	Array params;

	GET_ADITIONAL_PROPERTY(additional_parameters, params, "params", Variant::ARRAY, "ARRAY");

	for (int64_t i = 0; i < params.size(); i++) {
		p.push_back(params[i]);
		UtilityFunctions::print(params[i]);
	}

	SAFE_CALL(output = cv::imwrite(path, img->get_mat(), p));

	return output;
}

String CVImgCodecs::_to_string() const {
	return "[ CVImgCodecs Module ]";
}