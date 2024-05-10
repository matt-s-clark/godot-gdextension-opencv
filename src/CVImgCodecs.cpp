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
	Ref<CVMat> output = Ref<CVMat>(memnew(CVMat));

	try {
		const char *path = filename.utf8().get_data();
		outMat = cv::imread(path, flags);
	} catch (std::exception &stde) {
		UtilityFunctions::push_error(stde.what());
	}

	output->set_mat(outMat);

	return output;
}