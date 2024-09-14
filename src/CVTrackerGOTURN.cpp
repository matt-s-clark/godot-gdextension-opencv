#include "CVTrackerGOTURN.h"

using namespace godot;

void CVTrackerGOTURN::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("init", "image", "bounding_box"),
			&CVTrackerGOTURN::init);
	ClassDB::bind_method(
			D_METHOD("update", "image"),
			&CVTrackerGOTURN::update);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("create", "additional_parameters"),
			&CVTrackerGOTURN::create);
}

CVTrackerGOTURN::CVTrackerGOTURN() {
}

CVTrackerGOTURN::~CVTrackerGOTURN() {
}

void CVTrackerGOTURN::init(Ref<CVMat> image, Ref<CVRect> boundingBox) {
	ERR_FAIL_NULL_V_MSG(image, , "image should not be null.");
	ERR_FAIL_NULL_V_MSG(boundingBox, , "boundingBox should not be null.");

	SAFE_CALL(rawTracker->init(image->get_pointer(), boundingBox->get_pointer()));
}

Ref<CVRect> CVTrackerGOTURN::update(Ref<CVMat> image) {
	cv::Rect outRect;
	Ref<CVRect> output;
	output.instantiate();

	ERR_FAIL_NULL_V_MSG(image, output, "image should not be null.");

	SAFE_CALL(rawTracker->update(image->get_pointer(), outRect));

	output->set_pointer(outRect);

	return output;
}

Ref<CVTrackerGOTURN> CVTrackerGOTURN::create(Dictionary additional_parameters) {
	cv::Ptr<cv::TrackerGOTURN> outPointer;
	Ref<CVTrackerGOTURN> output;
	output.instantiate();

	cv::TrackerGOTURN::Params p = cv::TrackerGOTURN::Params();

	String modelBin = "", modelTxt = "";

	GET_ADITIONAL_PROPERTY(additional_parameters, modelBin, "model_bin", Variant::STRING, "STRING");
	GET_ADITIONAL_PROPERTY(additional_parameters, modelTxt, "model_txt", Variant::STRING, "STRING");

	if (modelBin != "") {
		cv::String modelBinIn(modelBin.utf8());
		p.modelBin = modelBinIn;
	}

	if (modelTxt != "") {
		cv::String modelTxtIn(modelTxt.utf8());
		p.modelTxt = modelTxtIn;
	}

	SAFE_CALL(outPointer = cv::TrackerGOTURN::create(p));

	output->set_pointer(outPointer);

	return output;
}

cv::Ptr<cv::TrackerGOTURN> CVTrackerGOTURN::get_pointer() {
	return rawTracker;
}

void CVTrackerGOTURN::set_pointer(cv::Ptr<cv::TrackerGOTURN> value) {
	rawTracker = value;
}

String CVTrackerGOTURN::_to_string() const {
	return UtilityFunctions::str("[ CVTrackerGOTURN instance ]");
}
