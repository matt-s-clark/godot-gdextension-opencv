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
	SAFECALL(rawCap.open(index, api));
}

Ref<CVMat> CVVideoCapture::read() {
	cv::Mat outMat;
	Ref<CVMat> output = Ref<CVMat>(memnew(CVMat));

	SAFECALL(rawCap.read(outMat));

	output->set_mat(outMat);

	return output;
}

bool CVVideoCapture::is_opened() {
	bool output = false;

	SAFECALL(output = rawCap.isOpened());

	return output;
}

void CVVideoCapture::release() {
	SAFECALL(rawCap.release());
}