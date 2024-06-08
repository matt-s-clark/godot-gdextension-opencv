#include "CVDnn.h"

using namespace godot;

void CVDnn::_bind_methods() {
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("blobFromImage", "image", "additional_parameters"),
			&CVDnn::blobFromImage);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("readNet", "model", "additional_parameters"),
			&CVDnn::readNet);
}

CVDnn::CVDnn() {
	UtilityFunctions::push_warning("This module should not be initialized, something is wrong");
}

CVDnn::~CVDnn() {
}

Ref<CVMat> CVDnn::blobFromImage(Ref<CVMat> image, Dictionary additional_parameters) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	float scaleFactor = 1;
	Vector2 size = Vector2();
	Vector3 mean = Vector3();
	bool swapRB = false, crop = false;
	int ddepth = 5;

	GET_ADITIONAL_PROPERTY(additional_parameters, scaleFactor, "scale_factor", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, size, "size", Variant::VECTOR2, "VECTOR2");
	GET_ADITIONAL_PROPERTY(additional_parameters, mean, "mean", Variant::VECTOR3, "VECTOR3");
	GET_ADITIONAL_PROPERTY(additional_parameters, swapRB, "swap_rb", Variant::BOOL, "BOOL");
	GET_ADITIONAL_PROPERTY(additional_parameters, crop, "crop", Variant::BOOL, "BOOL");
	GET_ADITIONAL_PROPERTY(additional_parameters, ddepth, "ddepth", Variant::INT, "INT");

	SAFE_CALL(outMat = cv::dnn::blobFromImage(image->get_mat(),
					  scaleFactor,
					  cv::Size(size.x, size.y),
					  cv::Scalar(mean.x, mean.y),
					  swapRB, crop, ddepth));

	output->set_mat(outMat);

	return output;
}

Ref<CVNet> CVDnn::readNet(const String model, Dictionary additional_parameters) {
	cv::dnn::Net outNet;
	Ref<CVNet> output;
	output.instantiate();

	String config = "", framework = "";

	GET_ADITIONAL_PROPERTY(additional_parameters, config, "config", Variant::STRING, "STRING");
	GET_ADITIONAL_PROPERTY(additional_parameters, framework, "framework", Variant::STRING, "STRING");

	cv::String modelIn(model.utf8());
	cv::String configIn(config.utf8());
	cv::String frameworkIn(framework.utf8());

	SAFE_CALL(outNet = cv::dnn::readNet(modelIn, configIn, frameworkIn));

	output->set_net(outNet);

	return output;
}

String CVDnn::_to_string() const {
	return "[ CVDnn Module ]";
}