#include "CVTrackerDaSiamRPN.h"

using namespace godot;

void CVTrackerDaSiamRPN::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("init", "image", "bounding_box"),
			&CVTrackerDaSiamRPN::init);
	ClassDB::bind_method(
			D_METHOD("update", "image"),
			&CVTrackerDaSiamRPN::update);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("create", "additional_parameters"),
			&CVTrackerDaSiamRPN::create);
}

CVTrackerDaSiamRPN::CVTrackerDaSiamRPN() {
}

CVTrackerDaSiamRPN::~CVTrackerDaSiamRPN() {
}

void CVTrackerDaSiamRPN::init(Ref<CVMat> image, Ref<CVRect> boundingBox) {
	ERR_FAIL_NULL_V_MSG(image, , "image should not be null.");
	ERR_FAIL_NULL_V_MSG(boundingBox, , "boundingBox should not be null.");

	SAFE_CALL(rawTracker->init(image->get_mat(), boundingBox->get_rect()));
}

Ref<CVRect> CVTrackerDaSiamRPN::update(Ref<CVMat> image) {
	cv::Rect outRect;
	Ref<CVRect> output;
	output.instantiate();

	ERR_FAIL_NULL_V_MSG(image, output, "image should not be null.");

	SAFE_CALL(rawTracker->update(image->get_mat(), outRect));

	output->set_rect(outRect);

	return output;
}

Ref<CVTrackerDaSiamRPN> CVTrackerDaSiamRPN::create(Dictionary additional_parameters) {
	cv::Ptr<cv::TrackerDaSiamRPN> outPointer;
	Ref<CVTrackerDaSiamRPN> output;
	output.instantiate();

	cv::TrackerDaSiamRPN::Params p = cv::TrackerDaSiamRPN::Params();

	String kernel_cls1 = "", kernel_r1 = "", model = "";

	GET_ADITIONAL_PROPERTY(additional_parameters, p.backend, "backend", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, kernel_cls1, "kernel_cls1", Variant::STRING, "STRING");
	GET_ADITIONAL_PROPERTY(additional_parameters, kernel_r1, "kernel_r1", Variant::STRING, "STRING");
	GET_ADITIONAL_PROPERTY(additional_parameters, model, "model", Variant::STRING, "STRING");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.target, "target", Variant::INT, "INT");

	if (kernel_cls1 != "") {
		cv::String kernel_cls1In(kernel_cls1.utf8());
		p.kernel_cls1 = kernel_cls1In;
	}
	if (kernel_cls1 != "") {
		cv::String kernel_r1In(kernel_r1.utf8());
		p.kernel_r1 = kernel_r1In;
	}
	if (kernel_cls1 != "") {
		cv::String modelIn(model.utf8());
		p.model = modelIn;
	}

	SAFE_CALL(outPointer = cv::TrackerDaSiamRPN::create(p));

	output->set_pointer(outPointer);

	return output;
}

cv::Ptr<cv::TrackerDaSiamRPN> CVTrackerDaSiamRPN::get_pointer() {
	return rawTracker;
}

void CVTrackerDaSiamRPN::set_pointer(cv::Ptr<cv::TrackerDaSiamRPN> value) {
	rawTracker = value;
}

String CVTrackerDaSiamRPN::_to_string() const {
	return UtilityFunctions::str("[ CVTrackerDaSiamRPN instance ]");
}
