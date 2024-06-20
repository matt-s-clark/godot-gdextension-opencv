#include "CVTrackerCSRT.h"

using namespace godot;

void CVTrackerCSRT::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("init", "image", "bounding_box"),
			&CVTrackerCSRT::init);
	ClassDB::bind_method(
			D_METHOD("update", "image"),
			&CVTrackerCSRT::update);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("create", "additional_parameters"),
			&CVTrackerCSRT::create);
}

CVTrackerCSRT::CVTrackerCSRT() {
}

CVTrackerCSRT::~CVTrackerCSRT() {
}

void CVTrackerCSRT::init(Ref<CVMat> image, Ref<CVRect> boundingBox) {
	SAFE_CALL(rawTracker->init(image->get_mat(), boundingBox->get_rect()));
}

Ref<CVRect> CVTrackerCSRT::update(Ref<CVMat> image) {
	cv::Rect outRect;
	Ref<CVRect> output;
	output.instantiate();

	SAFE_CALL(rawTracker->update(image->get_mat(), outRect));

	output->set_rect(outRect);

	return output;
}

Ref<CVTrackerCSRT> CVTrackerCSRT::create(Dictionary additional_parameters) {
	cv::Ptr<cv::TrackerCSRT> outPointer;
	Ref<CVTrackerCSRT> output;
	output.instantiate();
	String window_function = "";

	cv::TrackerCSRT::Params p = cv::TrackerCSRT::Params();

	GET_ADITIONAL_PROPERTY(additional_parameters, p.admm_iterations, "admm_iterations", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.background_ratio, "background_ratio", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.cheb_attenuation, "cheb_attenuation", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.filter_lr, "filter_lr", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.gsl_sigma, "gsl_sigma", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.histogram_bins, "histogram_bins", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.histogram_lr, "histogram_lr", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.hog_clip, "hog_clip", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.hog_orientations, "hog_orientations", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.kaiser_alpha, "kaiser_alpha", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.num_hog_channels_used, "num_hog_channels_used", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.number_of_scales, "number_of_scales", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.padding, "padding", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.psr_threshold, "psr_threshold", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.scale_lr, "scale_lr", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.scale_model_max_area, "scale_model_max_area", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.scale_sigma_factor, "scale_sigma_factor", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.scale_step, "scale_step", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.template_size, "template_size", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.use_channel_weights, "use_channel_weights", Variant::BOOL, "BOOL");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.use_color_names, "use_color_names", Variant::BOOL, "BOOL");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.use_gray, "use_gray", Variant::BOOL, "BOOL");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.use_hog, "use_hog", Variant::BOOL, "BOOL");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.use_rgb, "use_rgb", Variant::BOOL, "BOOL");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.use_segmentation, "use_segmentation", Variant::BOOL, "BOOL");
	GET_ADITIONAL_PROPERTY(additional_parameters, p.weights_lr, "weights_lr", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, window_function, "window_function", Variant::STRING, "STRING");

	if (window_function != "") {
		cv::String window_functionIn(window_function.utf8());
		p.window_function = window_functionIn;
	}

	SAFE_CALL(outPointer = cv::TrackerCSRT::create(p));

	output->set_pointer(outPointer);

	return output;
}

cv::Ptr<cv::TrackerCSRT> CVTrackerCSRT::get_pointer() {
	return rawTracker;
}

void CVTrackerCSRT::set_pointer(cv::Ptr<cv::TrackerCSRT> value) {
	rawTracker = value;
}

String CVTrackerCSRT::_to_string() const {
	return UtilityFunctions::str("[ CVTrackerCSRT instance ]");
}
