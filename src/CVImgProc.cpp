#include "CVImgProc.h"

using namespace godot;

void CVImgProc::_bind_methods() {
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("cvt_color", "src", "code", "dstCn"),
			&CVImgProc::cvt_color);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("equalize_hist", "src"),
			&CVImgProc::equalize_hist);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("rectangle", "img", "additional_parameters"),
			&CVImgProc::rectangle);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("bilateral_filter", "src", "d", "sigmaColor", "sigmaSpace", "borderType"),
			&CVImgProc::bilateral_filter);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("blur", "src", "ksize", "additional_parameters"),
			&CVImgProc::blur);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("dilate", "src", "kernel", "additional_parameters"),
			&CVImgProc::dilate);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("erode", "src", "kernel", "additional_parameters"),
			&CVImgProc::erode);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("gaussian_blur", "src", "ksize", "sigmaX", "additional_parameters"),
			&CVImgProc::gaussian_blur);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("get_structuring_element", "shape", "ksize", "anchor"),
			&CVImgProc::get_structuring_element);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("median_blur", "src", "ksize"),
			&CVImgProc::median_blur);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("morphology_ex", "src", "op", "kernel", "additional_parameters"),
			&CVImgProc::morphology_ex);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("adaptive_threshold", "src", "maxValue", "adaptiveMethod", "thresholdType", "blockSize", "C"),
			&CVImgProc::adaptive_threshold);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("threshold", "src", "thresh", "maxval", "type"),
			&CVImgProc::threshold);
}

CVImgProc::CVImgProc() {
	UtilityFunctions::push_warning("This module should not be initialized, something is wrong");
}

CVImgProc::~CVImgProc() {
}

Ref<CVMat> CVImgProc::cvt_color(Ref<CVMat> src, int code, int dstCn) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	SAFECALL(cv::cvtColor(src->get_mat(), matOut, code, dstCn));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::equalize_hist(Ref<CVMat> src) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	SAFECALL(cv::equalizeHist(src->get_mat(), matOut));

	output->set_mat(matOut);

	return output;
}

void CVImgProc::rectangle(Ref<CVMat> img, Dictionary additional_parameters) {
	Ref<CVRect> rect;
	Vector2 pt1 = Vector2(-1, -1), pt2 = Vector2(-1, -1);
	Color color = Color(0, 255, 0);
	int thickness = 1, lineType = 8, shift = 0;

	GETADITIONALPROPERTY(additional_parameters, rect, "rec", Variant::OBJECT, "CVRECT");
	GETADITIONALPROPERTY(additional_parameters, pt1, "pt1", Variant::VECTOR2, "VECTOR2");
	GETADITIONALPROPERTY(additional_parameters, pt2, "pt2", Variant::VECTOR2, "VECTOR2");
	GETADITIONALPROPERTY(additional_parameters, color, "color", Variant::COLOR, "COLOR");
	GETADITIONALPROPERTY(additional_parameters, thickness, "thickness", Variant::INT, "INT");
	GETADITIONALPROPERTY(additional_parameters, lineType, "line_type", Variant::INT, "INT");
	GETADITIONALPROPERTY(additional_parameters, shift, "shift", Variant::INT, "INT");

	if (!rect.is_null()) {
		SAFECALL(cv::rectangle(
				img->get_mat(),
				rect->get_rect(),
				cv::Scalar(color.b, color.g, color.r) * 255,
				thickness,
				lineType,
				shift));

	} else if (pt1.x >= 0 && pt2.x >= 0 && pt1.y >= 0 && pt2.y >= 0) {
		SAFECALL(cv::rectangle(
				img->get_mat(),
				cv::Point((int)pt1.x, (int)pt1.y),
				cv::Point((int)pt2.x, (int)pt2.y),
				cv::Scalar(color.b, color.g, color.r) * 255,
				thickness,
				lineType,
				shift));
	} else {
		UtilityFunctions::push_error("Invalid input: either rec or pt1 and pt2 needed");
	}
}

Ref<CVMat> CVImgProc::bilateral_filter(Ref<CVMat> src, int d, double sigmaColor, double sigmaSpace, int borderType) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	SAFECALL(cv::bilateralFilter(src->get_mat(), matOut, d, sigmaColor, sigmaSpace, borderType));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::blur(Ref<CVMat> src, Vector2 ksize, Dictionary additional_parameters) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	int borderType = 4;
	Vector2 anchor = Vector2(-1, -1);

	GETADITIONALPROPERTY(additional_parameters, borderType, "border_type", Variant::INT, "INT");
	GETADITIONALPROPERTY(additional_parameters, anchor, "anchor", Variant::VECTOR2, "VECTOR2");

	SAFECALL(cv::blur(src->get_mat(), matOut, cv::Size(ksize.x, ksize.y), cv::Point(anchor.x, anchor.y), borderType));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::dilate(Ref<CVMat> src, Ref<CVMat> kernel, Dictionary additional_parameters) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	int borderType = 4, interactions = 1;
	Vector2 anchor = Vector2(-1, -1), borderValue = Vector2(-1, -1);
	cv::Scalar borderValueScalar = cv::morphologyDefaultBorderValue();

	GETADITIONALPROPERTY(additional_parameters, borderType, "border_type", Variant::INT, "INT");
	GETADITIONALPROPERTY(additional_parameters, interactions, "interactions", Variant::INT, "INT");
	GETADITIONALPROPERTY(additional_parameters, anchor, "anchor", Variant::VECTOR2, "VECTOR2");
	GETADITIONALPROPERTY(additional_parameters, borderValue, "border_value", Variant::VECTOR2, "VECTOR2");

	if (borderValue.x != -1 && borderValue.y != -1) {
		borderValueScalar = cv::Scalar(borderValue.x, borderValue.y);
	}

	SAFECALL(cv::dilate(src->get_mat(), matOut, kernel->get_mat(), cv::Point(anchor.x, anchor.y), interactions, borderType, borderValueScalar));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::erode(Ref<CVMat> src, Ref<CVMat> kernel, Dictionary additional_parameters) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	int borderType = 4, interactions = 1;
	Vector2 anchor = Vector2(-1, -1), borderValue = Vector2(-1, -1);
	cv::Scalar borderValueScalar = cv::morphologyDefaultBorderValue();

	GETADITIONALPROPERTY(additional_parameters, borderType, "border_type", Variant::INT, "INT");
	GETADITIONALPROPERTY(additional_parameters, interactions, "interactions", Variant::INT, "INT");
	GETADITIONALPROPERTY(additional_parameters, anchor, "anchor", Variant::VECTOR2, "VECTOR2");
	GETADITIONALPROPERTY(additional_parameters, borderValue, "border_value", Variant::VECTOR2, "VECTOR2");

	if (borderValue.x != -1 && borderValue.y != -1) {
		borderValueScalar = cv::Scalar(borderValue.x, borderValue.y);
	}

	SAFECALL(cv::erode(src->get_mat(), matOut, kernel->get_mat(), cv::Point(anchor.x, anchor.y), interactions, borderType, borderValueScalar));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::morphology_ex(Ref<CVMat> src, int op, Ref<CVMat> kernel, Dictionary additional_parameters) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	int borderType = 4, interactions = 1;
	Vector2 anchor = Vector2(-1, -1), borderValue = Vector2(-1, -1);
	cv::Scalar borderValueScalar = cv::morphologyDefaultBorderValue();

	GETADITIONALPROPERTY(additional_parameters, borderType, "border_type", Variant::INT, "INT");
	GETADITIONALPROPERTY(additional_parameters, interactions, "interactions", Variant::INT, "INT");
	GETADITIONALPROPERTY(additional_parameters, anchor, "anchor", Variant::VECTOR2, "VECTOR2");
	GETADITIONALPROPERTY(additional_parameters, borderValue, "border_value", Variant::VECTOR2, "VECTOR2");

	if (borderValue.x != -1 && borderValue.y != -1) {
		borderValueScalar = cv::Scalar(borderValue.x, borderValue.y);
	}

	SAFECALL(cv::morphologyEx(src->get_mat(), matOut, op, kernel->get_mat(), cv::Point(anchor.x, anchor.y), interactions, borderType, borderValueScalar));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::get_structuring_element(int shape, Vector2 ksize, Vector2 anchor) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	SAFECALL(matOut = cv::getStructuringElement(shape, cv::Size(ksize.x, ksize.y), cv::Point(anchor.x, anchor.y)));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::gaussian_blur(Ref<CVMat> src, Vector2 ksize, float sigmaX, Dictionary additional_parameters) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	float sigmaY = 0;
	int borderType = 4;

	GETADITIONALPROPERTY(additional_parameters, sigmaY, "sigma_y", Variant::FLOAT, "FLOAT");
	GETADITIONALPROPERTY(additional_parameters, borderType, "border_type", Variant::INT, "INT");

	SAFECALL(cv::GaussianBlur(src->get_mat(), matOut, cv::Size(ksize.x, ksize.y), sigmaX, sigmaY, borderType));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::median_blur(Ref<CVMat> src, int ksize) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	SAFECALL(cv::medianBlur(src->get_mat(), matOut, ksize));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::adaptive_threshold(Ref<CVMat> src, float maxValue, int adaptiveMethod, int thresholdType, int blockSize, float C) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	SAFECALL(cv::adaptiveThreshold(src->get_mat(), matOut, maxValue, adaptiveMethod, thresholdType, blockSize, C));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::threshold(Ref<CVMat> src, float thresh, float maxval, int type) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	SAFECALL(cv::threshold(src->get_mat(), matOut, thresh, maxval, type));

	output->set_mat(matOut);

	return output;
}

String CVImgProc::_to_string() const {
	return "[ CVImgProc Module ]";
}