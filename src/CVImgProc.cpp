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

String CVImgProc::_to_string() const {
	return "[ CVImgProc Module ]";
}