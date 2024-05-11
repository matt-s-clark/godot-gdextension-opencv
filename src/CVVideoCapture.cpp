#include "CVVideoCapture.h"

using namespace godot;

void CVVideoCapture::_bind_methods() {
	ClassDB::bind_method(D_METHOD("open", "source", "api_preference", "params"), &CVVideoCapture::open);
	ClassDB::bind_method(D_METHOD("release"), &CVVideoCapture::release);
	ClassDB::bind_method(D_METHOD("read"), &CVVideoCapture::read);
	ClassDB::bind_method(D_METHOD("is_opened"), &CVVideoCapture::is_opened);
}

CVVideoCapture::CVVideoCapture() {
}

CVVideoCapture::~CVVideoCapture() {
	release();
}

void CVVideoCapture::open(Variant source, int api, Variant params) {
	std::vector<int> p;
	Array parameters = params;
	if (params.get_type() == Variant::Type::ARRAY) {
		for (int64_t i = 0; i < ((Array)parameters).size(); i++) {
			p.push_back(parameters[i]);
			UtilityFunctions::print(parameters[i]);
		}
	} else if (params.get_type() != Variant::Type::NIL) {
		UtilityFunctions::push_error("Invalid input: Parameters should be an array, input will be ignored.");
	}
	if (source.get_type() == Variant::Type::INT) {
		SAFECALL(rawCap.open(source, api, p));
	} else if ((source.get_type() == Variant::Type::STRING)) {
		const char *path = ((String)source).utf8().get_data();
		SAFECALL(rawCap.open(path, api, p));
	} else {
		UtilityFunctions::push_error("Invalid input: Expected integer or string.");
	}
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