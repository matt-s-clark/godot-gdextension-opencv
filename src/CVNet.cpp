#include "CVNet.h"

using namespace godot;

void CVNet::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("dump"),
			&CVNet::dump);
	ClassDB::bind_method(
			D_METHOD("empty"),
			&CVNet::empty);
	ClassDB::bind_method(
			D_METHOD("forward"),
			&CVNet::forward);
	ClassDB::bind_method(
			D_METHOD("setInput", "blob", "additional_parameters"),
			&CVNet::setInput);
}

CVNet::CVNet() {
}

CVNet::~CVNet() {
}

String CVNet::dump() {
	String output;

	SAFE_CALL(output = rawNet.dump().c_str());

	return output;
}

bool CVNet::empty() {
	bool output;

	SAFE_CALL(output = rawNet.empty());

	return output;
}

Ref<CVMat> CVNet::forward() {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	SAFE_CALL(outMat = rawNet.forward());

	output->set_mat(outMat);

	return output;
}

void CVNet::setInput(Ref<CVMat> blob, Dictionary additional_parameters) {
	String name = "";
	float scaleFactor = 1.0;
	Vector3 mean = Vector3();

	ERR_FAIL_NULL_V_MSG(blob, , "blob should not be null.");

	GET_ADITIONAL_PROPERTY(additional_parameters, name, "name", Variant::STRING, "STRING");
	GET_ADITIONAL_PROPERTY(additional_parameters, scaleFactor, "scale_factor", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, mean, "mean", Variant::VECTOR3, "VECTOR3");

	cv::String nameIn(name.utf8());

	SAFE_CALL(rawNet.setInput(blob->get_mat(), nameIn, scaleFactor, cv::Scalar(mean.x, mean.y)));
}

cv::dnn::Net CVNet::get_net() {
	return rawNet;
}

void CVNet::set_net(cv::dnn::Net value) {
	rawNet = value;
}

String CVNet::_to_string() const {
	return UtilityFunctions::str("[ CVNet instance ]");
}
