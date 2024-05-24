#include "CVImgCodecs.h"

using namespace godot;

void CVImgCodecs::_bind_methods() {
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("imread", "filename", "additional_parameters"),
			&CVImgCodecs::imread);
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

String CVImgCodecs::_to_string() const {
	return "[ CVImgCodecs Module ]";
}