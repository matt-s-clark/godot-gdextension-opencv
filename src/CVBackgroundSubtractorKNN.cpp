#include "CVBackgroundSubtractorKNN.h"

using namespace godot;

void CVBackgroundSubtractorKNN::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("apply", "image", "additional_parameters"),
			&CVBackgroundSubtractorKNN::apply);
	ClassDB::bind_method(
			D_METHOD("get_background_image"),
			&CVBackgroundSubtractorKNN::get_background_image);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("create", "additional_parameters"),
			&CVBackgroundSubtractorKNN::create);
}

CVBackgroundSubtractorKNN::CVBackgroundSubtractorKNN() {
}

CVBackgroundSubtractorKNN::~CVBackgroundSubtractorKNN() {
}

Ref<CVMat> CVBackgroundSubtractorKNN::apply(Ref<CVMat> image, Dictionary additional_parameters) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	float learning_rate = -1.0;

	GET_ADITIONAL_PROPERTY(additional_parameters, learning_rate, "learning_rate", Variant::FLOAT, "FLOAT");

	SAFE_CALL(rawPointer->apply(image->get_mat(), outMat, learning_rate));

	output->set_mat(outMat);

	return output;
}

Ref<CVBackgroundSubtractorKNN> CVBackgroundSubtractorKNN::create(Dictionary additional_parameters) {
	cv::Ptr<cv::BackgroundSubtractorKNN> outPoi;
	Ref<CVBackgroundSubtractorKNN> output;
	output.instantiate();

	int history = 500;
	float dist2Threshold = 400.0;
	bool detectShadows = true;

	GET_ADITIONAL_PROPERTY(additional_parameters, history, "history", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, dist2Threshold, "dist2_threshold", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, detectShadows, "detect_shadows", Variant::BOOL, "BOOL");

	SAFE_CALL(outPoi = cv::createBackgroundSubtractorKNN(history, dist2Threshold, detectShadows));

	output->set_pointer(outPoi);

	return output;
}

Ref<CVMat> CVBackgroundSubtractorKNN::get_background_image() {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	SAFE_CALL(rawPointer->getBackgroundImage(outMat));

	output->set_mat(outMat);

	return output;
}

cv::Ptr<cv::BackgroundSubtractorKNN> CVBackgroundSubtractorKNN::get_pointer() {
	return rawPointer;
}

void CVBackgroundSubtractorKNN::set_pointer(cv::Ptr<cv::BackgroundSubtractorKNN> value) {
	rawPointer = value;
}

String CVBackgroundSubtractorKNN::_to_string() const {
	return "[ CVBackgroundSubtractorKNN Module ]";
}