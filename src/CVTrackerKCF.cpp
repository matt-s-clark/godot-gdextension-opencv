#include "CVTrackerKCF.h"

using namespace godot;

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
	ERR_FAIL_NULL_V_MSG(image, , "image should not be null.");
	ERR_FAIL_NULL_V_MSG(boundingBox, , "boundingBox should not be null.");

	SAFE_CALL(rawTracker->init(image->get_pointer(), boundingBox->get_pointer()));
}

Ref<CVRect> CVTrackerKCF::update(Ref<CVMat> image) {
	cv::Rect outRect;
	Ref<CVRect> output;
	output.instantiate();

	ERR_FAIL_NULL_V_MSG(image, output, "image should not be null.");

	SAFE_CALL(rawTracker->update(image->get_pointer(), outRect));

	output->set_pointer(outRect);

	return output;
}

Ref<CVTrackerKCF> CVTrackerKCF::create(Dictionary additional_parameters) {
	cv::Ptr<cv::TrackerKCF> outPointer;
	Ref<CVTrackerKCF> output;
	output.instantiate();

	cv::TrackerKCF::Params p = cv::TrackerKCF::Params();

	GET_ADITIONAL_PROPERTY(additional_parameters, p.compress_feature, "compress_feature", Variant::BOOL, "BOOL");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.compressed_size, "compressed_size", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.desc_npca, "desc_npca", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.desc_pca, "desc_pca", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.detect_thresh, "detect_thresh", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.interp_factor, "interp_factor", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.lambda, "lambda", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.max_patch_size, "max_patch_size", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.output_sigma_factor, "output_sigma_factor", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.resize, "resize", Variant::BOOL, "BOOL");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.sigma, "sigma", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.split_coeff, "split_coeff", Variant::BOOL, "BOOL");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.wrap_kernel, "wrap_kernel", Variant::BOOL, "BOOL");

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

String CVTrackerKCF::_to_string() const {
	return UtilityFunctions::str("[ CVTrackerKCF instance ]");
}
