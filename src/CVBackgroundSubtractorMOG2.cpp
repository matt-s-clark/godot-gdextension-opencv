#include "CVBackgroundSubtractorMOG2.h"

using namespace godot;

void CVBackgroundSubtractorMOG2::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("apply", "image", "additional_parameters"),
			&CVBackgroundSubtractorMOG2::apply);
	ClassDB::bind_method(
			D_METHOD("get_background_image"),
			&CVBackgroundSubtractorMOG2::get_background_image);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("create", "additional_parameters"),
			&CVBackgroundSubtractorMOG2::create);
}

CVBackgroundSubtractorMOG2::CVBackgroundSubtractorMOG2() {
}

CVBackgroundSubtractorMOG2::~CVBackgroundSubtractorMOG2() {
}

Ref<CVMat> CVBackgroundSubtractorMOG2::apply(Ref<CVMat> image, Dictionary additional_parameters) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	float learning_rate = -1.0;

	GET_ADITIONAL_PROPERTY(additional_parameters, learning_rate, "learning_rate", Variant::FLOAT, "FLOAT");

	SAFE_CALL(rawPointer->apply(image->get_mat(), outMat, learning_rate));

	output->set_mat(outMat);

	return output;
}

Ref<CVBackgroundSubtractorMOG2> CVBackgroundSubtractorMOG2::create(Dictionary additional_parameters) {
	cv::Ptr<cv::BackgroundSubtractorMOG2> outPoi;
	Ref<CVBackgroundSubtractorMOG2> output;
	output.instantiate();

	int history = 500;
	float distThreshold = 16.0;
	bool detectShadows = true;

	GET_ADITIONAL_PROPERTY(additional_parameters, history, "history", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, distThreshold, "dist_threshold", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, detectShadows, "detect_shadows", Variant::BOOL, "BOOL");

	SAFE_CALL(outPoi = cv::createBackgroundSubtractorMOG2(history, distThreshold, detectShadows));

	output->set_pointer(outPoi);

	return output;
}

Ref<CVMat> CVBackgroundSubtractorMOG2::get_background_image() {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	SAFE_CALL(rawPointer->getBackgroundImage(outMat));

	output->set_mat(outMat);

	return output;
}

cv::Ptr<cv::BackgroundSubtractorMOG2> CVBackgroundSubtractorMOG2::get_pointer() {
	return rawPointer;
}

void CVBackgroundSubtractorMOG2::set_pointer(cv::Ptr<cv::BackgroundSubtractorMOG2> value) {
	rawPointer = value;
}

String CVBackgroundSubtractorMOG2::_to_string() const {
	return "[ CVBackgroundSubtractorMOG2 Module ]";
}