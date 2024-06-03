#include "CVVideoCapture.h"

using namespace godot;

void CVVideoCapture::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("open", "source", "api_preference", "params"),
			&CVVideoCapture::open);

	ClassDB::bind_method(
			D_METHOD("release"),
			&CVVideoCapture::release);

	ClassDB::bind_method(
			D_METHOD("read"),
			&CVVideoCapture::read);

	ClassDB::bind_method(
			D_METHOD("is_opened"),
			&CVVideoCapture::is_opened);

	ClassDB::bind_method(
			D_METHOD("get", "propId"),
			&CVVideoCapture::get);

	ClassDB::bind_method(
			D_METHOD("get_backend_name"),
			&CVVideoCapture::getBackendName);

	ClassDB::bind_method(
			D_METHOD("get_exception_mode"), &CVVideoCapture::getExceptionMode);

	ClassDB::bind_method(
			D_METHOD("grab"),
			&CVVideoCapture::grab);

	ClassDB::bind_method(
			D_METHOD("retrieve", "flag"),
			&CVVideoCapture::retrieve);

	ClassDB::bind_method(
			D_METHOD("set", "propId", "value"),
			&CVVideoCapture::set);

	ClassDB::bind_method(
			D_METHOD("set_exception_mode", "enable"),
			&CVVideoCapture::setExceptionMode);
}

CVVideoCapture::CVVideoCapture() {
}

CVVideoCapture::~CVVideoCapture() {
	release();
}

void CVVideoCapture::open(Variant source, int api_preference, Variant params) {
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
		SAFE_CALL(rawCap.open(source, api_preference, p));
	} else if ((source.get_type() == Variant::Type::STRING)) {
		const cv::String path(((String)source).utf8());
		SAFE_CALL(rawCap.open(path, api_preference, p));
	} else {
		UtilityFunctions::push_error("Invalid input: Expected integer or string.");
	}
}

Ref<CVMat> CVVideoCapture::retrieve(Dictionary additional_parameters) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	int flag = 0;

	GET_ADITIONAL_PROPERTY(additional_parameters, flag, "flag", Variant::INT, "INT");

	SAFE_CALL(rawCap.retrieve(outMat, flag));

	output->set_mat(outMat);

	return output;
}

Ref<CVMat> CVVideoCapture::read() {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	SAFE_CALL(rawCap.read(outMat));

	output->set_mat(outMat);

	return output;
}

bool CVVideoCapture::is_opened() {
	bool output = false;

	SAFE_CALL(output = rawCap.isOpened());

	return output;
}

String CVVideoCapture::getBackendName() {
	String output;

	SAFE_CALL(output = rawCap.getBackendName().c_str());

	return output;
}

bool CVVideoCapture::grab() {
	bool output = false;

	SAFE_CALL(output = rawCap.grab());

	return output;
}

bool CVVideoCapture::getExceptionMode() {
	bool output = false;

	SAFE_CALL(output = rawCap.getExceptionMode());

	return output;
}

float CVVideoCapture::get(int propId) {
	float output;

	// Output type of the value changed from double to float
	SAFE_CALL(output = rawCap.get(propId));

	return output;
}

bool CVVideoCapture::set(int propId, float value) {
	bool output = false;

	// Input type of the value changed from double to float
	SAFE_CALL(rawCap.set(propId, value));

	return output;
}

void CVVideoCapture::release() {
	SAFE_CALL(rawCap.release());
}

void CVVideoCapture::setExceptionMode(bool enable) {
	SAFE_CALL(rawCap.setExceptionMode(enable));
}

String CVVideoCapture::_to_string() const {
	return "[ CVVideoCapture instance ]";
}