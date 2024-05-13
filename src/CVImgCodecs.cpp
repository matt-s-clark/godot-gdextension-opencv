#include "CVImgCodecs.h"

using namespace godot;

void CVImgCodecs::_bind_methods() {
	ClassDB::bind_static_method(get_class_static(), D_METHOD("imread", "filename", "flags"), &CVImgCodecs::imread);
}

CVImgCodecs::CVImgCodecs() {
}

CVImgCodecs::~CVImgCodecs() {
}

Ref<CVMat> CVImgCodecs::imread(const String filename, const int flags = cv::IMREAD_COLOR) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();
	const char *path = filename.utf8().get_data();

	SAFECALL(outMat = cv::imread(path, flags));

	output->set_mat(outMat);

	return output;
}