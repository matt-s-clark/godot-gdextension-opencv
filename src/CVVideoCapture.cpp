#include "CVVideoCapture.h"

using namespace godot;

void CVVideoCapture::_bind_methods() {
	ClassDB::bind_method(D_METHOD("open", "index", "api_preference"), &CVVideoCapture::open);
	ClassDB::bind_method(D_METHOD("release"), &CVVideoCapture::release);
	ClassDB::bind_method(D_METHOD("read"), &CVVideoCapture::read);
	ClassDB::bind_method(D_METHOD("is_opened"), &CVVideoCapture::is_opened);
}

CVVideoCapture::CVVideoCapture() {
}

CVVideoCapture::~CVVideoCapture() {
	release();
}

void CVVideoCapture::open(int index, int api) {
	try {
		rawCap.open(index, api);
	} catch (std::exception &stde) {
		UtilityFunctions::push_error(stde.what());
	}
}

Ref<CVMat> CVVideoCapture::read() {
	cv::Mat outMat;
	Ref<CVMat> output = Ref<CVMat>(memnew(CVMat));

	try {
		rawCap.read(outMat);
	} catch (std::exception &stde) {
		UtilityFunctions::push_error(stde.what());
	}

	output->set_mat(outMat);

	return output;
}

bool CVVideoCapture::is_opened() {
	bool output = false;

	try {
		output = rawCap.isOpened();
	} catch (std::exception &stde) {
		UtilityFunctions::push_error(stde.what());
	}

	return output;
}

void CVVideoCapture::release() {
	try {
		rawCap.release();
	} catch (std::exception &stde) {
		UtilityFunctions::push_error(stde.what());
	}
}