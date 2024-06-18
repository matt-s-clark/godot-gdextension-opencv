#include "CVTrackerKCF.h"

using namespace godot;
/*
void CVTrackerKCF::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("init", "image", "bounding_box"),
			&CVTrackerKCF::init);
	ClassDB::bind_method(
			D_METHOD("update", "image"),
			&CVTrackerKCF::update);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("create", "additional_parameters"),
			&CVTrackerKCF::create);
}

CVTrackerKCF::CVTrackerKCF() {
}

CVTrackerKCF::~CVTrackerKCF() {
}

void CVTrackerKCF::init(Ref<CVMat> image, Ref<CVRect> boundingBox) {
	SAFE_CALL(rawTracker->init(image->get_mat(), boundingBox->get_rect()));
}

Ref<CVRect> CVTrackerKCF::update(Ref<CVMat> image) {
	cv::Rect outRect;
	Ref<CVRect> output;
	output.instantiate();

	SAFE_CALL(rawTracker->update(image->get_mat(), outRect));

	output->set_rect(outRect);

	return output;
}

Ref<CVTrackerKCF> CVTrackerKCF::create(Dictionary additional_parameters) {
	cv::Ptr<cv::TrackerKCF> outPointer;
	Ref<CVTrackerKCF> output;
	output.instantiate();

	cv::TrackerKCF::Params p = cv::TrackerKCF::Params();

	

	SAFE_CALL(outPointer = cv::TrackerKCF::create(p));

	output->set_pointer(outPointer);

	return output;
}

cv::Ptr<cv::TrackerKCF> CVTrackerKCF::get_pointer() {
	return rawTracker;
}

void CVTrackerKCF::set_pointer(cv::Ptr<cv::TrackerKCF> value) {
	rawTracker = value;
}
*/
String CVTrackerKCF::_to_string() const {
	return UtilityFunctions::str("[ CVTrackerKCF instance ]");
}
