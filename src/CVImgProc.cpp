#include "CVImgProc.h"

using namespace godot;

void CVImgProc::_bind_methods() {
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("cvt_color", "src", "code", "additional_parameters"),
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
			D_METHOD("bilateral_filter", "src", "d", "sigmaColor", "sigmaSpace", "additional_parameters"),
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
			D_METHOD("get_structuring_element", "shape", "ksize", "additional_parameters"),
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

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("laplacian", "src", "ddepth", "additional_parameters"),
			&CVImgProc::laplacian);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("sobel", "src", "ddepth", "dx", "dy", "additional_parameters"),
			&CVImgProc::sobel);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("filter2D", "src", "ddepth", "kernel", "additional_parameters"),
			&CVImgProc::filter2D);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("get_gaussian_kernel", "ksize", "sigma", "additional_parameters"),
			&CVImgProc::get_gaussian_kernel);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("get_gabor_kernel", "ksize", "sigma", "theta", "lambd", "gamma", "additional_parameters"),
			&CVImgProc::get_gabor_kernel);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("ellipse", "img", "center", "axes", "angle", "start_angle", "end_angle", "additional_parameters"),
			&CVImgProc::ellipse);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("line", "img", "pt1", "pt2", "additional_parameters"),
			&CVImgProc::line);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("resize", "src", "dsize", "additional_parameters"),
			&CVImgProc::resize);
}

CVImgProc::CVImgProc() {
	UtilityFunctions::push_warning("This module should not be initialized, something is wrong");
}

CVImgProc::~CVImgProc() {
}

Ref<CVMat> CVImgProc::cvt_color(Ref<CVMat> src, int code, Dictionary additional_parameters) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	int dstCn = 0;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_ADITIONAL_PROPERTY(additional_parameters, dstCn, "dst_cn", Variant::INT, "INT");

	SAFE_CALL(cv::cvtColor(src->get_mat(), matOut, code, dstCn));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::equalize_hist(Ref<CVMat> src) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::equalizeHist(src->get_mat(), matOut));

	output->set_mat(matOut);

	return output;
}

void CVImgProc::rectangle(Ref<CVMat> img, Dictionary additional_parameters) {
	Ref<CVRect> rect;
	Vector2 pt1 = Vector2(-1, -1), pt2 = Vector2(-1, -1);
	Color color = Color(0, 255, 0);
	int thickness = 1, lineType = 8, shift = 0;

	ERR_FAIL_NULL_V_MSG(img, , "img should not be null.");

	GET_ADITIONAL_PROPERTY(additional_parameters, rect, "rec", Variant::OBJECT, "CVRECT");
	GET_ADITIONAL_PROPERTY(additional_parameters, pt1, "pt1", Variant::VECTOR2, "VECTOR2");
	GET_ADITIONAL_PROPERTY(additional_parameters, pt2, "pt2", Variant::VECTOR2, "VECTOR2");
	GET_ADITIONAL_PROPERTY(additional_parameters, color, "color", Variant::COLOR, "COLOR");
	GET_ADITIONAL_PROPERTY(additional_parameters, thickness, "thickness", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, lineType, "line_type", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, shift, "shift", Variant::INT, "INT");

	if (!rect.is_null()) {
		SAFE_CALL(cv::rectangle(
				img->get_mat(),
				rect->get_rect(),
				cv::Scalar(color.b, color.g, color.r) * 255,
				thickness,
				lineType,
				shift));

	} else if (pt1.x >= 0 && pt2.x >= 0 && pt1.y >= 0 && pt2.y >= 0) {
		SAFE_CALL(cv::rectangle(
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

Ref<CVMat> CVImgProc::bilateral_filter(Ref<CVMat> src, int d, double sigmaColor, double sigmaSpace, Dictionary additional_parameters) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	int borderType = 4;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_ADITIONAL_PROPERTY(additional_parameters, borderType, "border_type", Variant::INT, "INT");

	SAFE_CALL(cv::bilateralFilter(src->get_mat(), matOut, d, sigmaColor, sigmaSpace, borderType));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::blur(Ref<CVMat> src, Vector2 ksize, Dictionary additional_parameters) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	int borderType = 4;
	Vector2 anchor = Vector2(-1, -1);

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_ADITIONAL_PROPERTY(additional_parameters, borderType, "border_type", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, anchor, "anchor", Variant::VECTOR2, "VECTOR2");

	SAFE_CALL(cv::blur(src->get_mat(), matOut, cv::Size(ksize.x, ksize.y), cv::Point(anchor.x, anchor.y), borderType));

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

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(kernel, output, "kernel should not be null.");

	GET_ADITIONAL_PROPERTY(additional_parameters, borderType, "border_type", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, interactions, "interactions", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, anchor, "anchor", Variant::VECTOR2, "VECTOR2");
	GET_ADITIONAL_PROPERTY(additional_parameters, borderValue, "border_value", Variant::VECTOR2, "VECTOR2");

	if (borderValue.x != -1 && borderValue.y != -1) {
		borderValueScalar = cv::Scalar(borderValue.x, borderValue.y);
	}

	SAFE_CALL(cv::dilate(src->get_mat(), matOut, kernel->get_mat(), cv::Point(anchor.x, anchor.y), interactions, borderType, borderValueScalar));

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

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(kernel, output, "kernel should not be null.");

	GET_ADITIONAL_PROPERTY(additional_parameters, borderType, "border_type", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, interactions, "interactions", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, anchor, "anchor", Variant::VECTOR2, "VECTOR2");
	GET_ADITIONAL_PROPERTY(additional_parameters, borderValue, "border_value", Variant::VECTOR2, "VECTOR2");

	if (borderValue.x != -1 && borderValue.y != -1) {
		borderValueScalar = cv::Scalar(borderValue.x, borderValue.y);
	}

	SAFE_CALL(cv::erode(src->get_mat(), matOut, kernel->get_mat(), cv::Point(anchor.x, anchor.y), interactions, borderType, borderValueScalar));

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

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(kernel, output, "kernel should not be null.");

	GET_ADITIONAL_PROPERTY(additional_parameters, borderType, "border_type", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, interactions, "interactions", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, anchor, "anchor", Variant::VECTOR2, "VECTOR2");
	GET_ADITIONAL_PROPERTY(additional_parameters, borderValue, "border_value", Variant::VECTOR2, "VECTOR2");

	if (borderValue.x != -1 && borderValue.y != -1) {
		borderValueScalar = cv::Scalar(borderValue.x, borderValue.y);
	}

	SAFE_CALL(cv::morphologyEx(src->get_mat(), matOut, op, kernel->get_mat(), cv::Point(anchor.x, anchor.y), interactions, borderType, borderValueScalar));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::get_structuring_element(int shape, Vector2 ksize, Dictionary additional_parameters) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	Vector2 anchor = Vector2(-1, -1);

	GET_ADITIONAL_PROPERTY(additional_parameters, anchor, "anchor", Variant::VECTOR2, "VECTOR2");

	SAFE_CALL(matOut = cv::getStructuringElement(shape, cv::Size(ksize.x, ksize.y), cv::Point(anchor.x, anchor.y)));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::gaussian_blur(Ref<CVMat> src, Vector2 ksize, float sigmaX, Dictionary additional_parameters) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	float sigmaY = 0;
	int borderType = 4;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_ADITIONAL_PROPERTY(additional_parameters, sigmaY, "sigma_y", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, borderType, "border_type", Variant::INT, "INT");

	SAFE_CALL(cv::GaussianBlur(src->get_mat(), matOut, cv::Size(ksize.x, ksize.y), sigmaX, sigmaY, borderType));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::median_blur(Ref<CVMat> src, int ksize) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::medianBlur(src->get_mat(), matOut, ksize));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::adaptive_threshold(Ref<CVMat> src, float maxValue, int adaptiveMethod, int thresholdType, int blockSize, float C) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::adaptiveThreshold(src->get_mat(), matOut, maxValue, adaptiveMethod, thresholdType, blockSize, C));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::threshold(Ref<CVMat> src, float thresh, float maxval, int type) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::threshold(src->get_mat(), matOut, thresh, maxval, type));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::filter2D(Ref<CVMat> src, int ddepth, Ref<CVMat> kernel, Dictionary additional_parameters) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	Vector2 anchor = Vector2(-1, -1);
	float delta = 0;
	int borderType = 4;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(kernel, output, "kernel should not be null.");

	GET_ADITIONAL_PROPERTY(additional_parameters, anchor, "anchor", Variant::VECTOR2, "VECTOR2");
	GET_ADITIONAL_PROPERTY(additional_parameters, delta, "delta", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, borderType, "border_type", Variant::INT, "INT");

	SAFE_CALL(cv::filter2D(src->get_mat(), matOut, ddepth, kernel->get_mat(),
			cv::Point(anchor.x, anchor.y), delta, borderType));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::get_gaussian_kernel(int ksize, float sigma, Dictionary additional_parameters) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	int ktype = 6;

	GET_ADITIONAL_PROPERTY(additional_parameters, ktype, "ktype", Variant::INT, "INT");

	SAFE_CALL(matOut = cv::getGaussianKernel(ksize, sigma, ktype));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::get_gabor_kernel(Vector2 ksize, float sigma, float theta, float lambd, float gamma, Dictionary additional_parameters) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	int ktype = 6;
	float psi = 1.5707963267948966;

	GET_ADITIONAL_PROPERTY(additional_parameters, ktype, "ktype", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, psi, "psi", Variant::FLOAT, "FLOAT");

	SAFE_CALL(matOut = cv::getGaborKernel(cv::Size(ksize.x, ksize.y), sigma, theta, lambd, gamma, psi, ktype));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::laplacian(Ref<CVMat> src, int ddepth, Dictionary additional_parameters) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	int ksize = 1, borderType = 4;
	float scale = 1.0, delta = 0.0;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_ADITIONAL_PROPERTY(additional_parameters, ksize, "ksize", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, borderType, "border_type", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, scale, "scale", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, delta, "delta", Variant::FLOAT, "FLOAT");

	SAFE_CALL(cv::Laplacian(src->get_mat(), matOut, ddepth, ksize, scale, delta, borderType));

	output->set_mat(matOut);

	return output;
}

Ref<CVMat> CVImgProc::sobel(Ref<CVMat> src, int ddepth, int dx, int dy, Dictionary additional_parameters) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	int ksize = 3, borderType = 4;
	float scale = 1.0, delta = 0.0;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_ADITIONAL_PROPERTY(additional_parameters, ksize, "ksize", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, borderType, "border_type", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, scale, "scale", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, delta, "delta", Variant::FLOAT, "FLOAT");

	SAFE_CALL(cv::Sobel(src->get_mat(), matOut, ddepth, dx, dy, ksize, scale, delta, borderType));

	output->set_mat(matOut);

	return output;
}

void CVImgProc::ellipse(Ref<CVMat> img, Vector2 center, Vector2 axes, float angle, float startAngle, float endAngle, Dictionary additional_parameters) {
	Color color = Color(0, 255, 0);
	int thickness = 1, lineType = 8, shift = 0;

	ERR_FAIL_NULL_V_MSG(img, , "img should not be null.");

	GET_ADITIONAL_PROPERTY(additional_parameters, color, "color", Variant::COLOR, "COLOR");
	GET_ADITIONAL_PROPERTY(additional_parameters, thickness, "thickness", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, lineType, "line_type", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, shift, "shift", Variant::INT, "INT");

	SAFE_CALL(cv::ellipse(img->get_mat(),
			cv::Size(center.x, center.y),
			cv::Size(axes.x, axes.y),
			angle,
			startAngle,
			endAngle,
			cv::Scalar(color.b, color.g, color.r) * 255,
			thickness,
			lineType,
			shift));
}

void CVImgProc::line(Ref<CVMat> img, Vector2 pt1, Vector2 pt2, Dictionary additional_parameters) {
	Color color = Color(0, 255, 0);
	int thickness = 1, lineType = 8, shift = 0;

	ERR_FAIL_NULL_V_MSG(img, , "img should not be null.");

	GET_ADITIONAL_PROPERTY(additional_parameters, color, "color", Variant::COLOR, "COLOR");
	GET_ADITIONAL_PROPERTY(additional_parameters, thickness, "thickness", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, lineType, "line_type", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, shift, "shift", Variant::INT, "INT");

	SAFE_CALL(cv::line(img->get_mat(),
			cv::Size(pt1.x, pt1.y),
			cv::Size(pt2.x, pt2.y),
			cv::Scalar(color.b, color.g, color.r) * 255,
			thickness,
			lineType,
			shift));
}

Ref<CVMat> CVImgProc::resize(Ref<CVMat> src, Vector2 dsize, Dictionary additional_parameters) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	float fx = 0, fy = 0;
	int interpolation = 1;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_ADITIONAL_PROPERTY(additional_parameters, fx, "fx", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, fy, "fy", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, interpolation, "interpolation", Variant::INT, "INT");

	SAFE_CALL(cv::resize(src->get_mat(), matOut,
			cv::Size(dsize.x, dsize.y), fx, fy, interpolation));

	output->set_mat(matOut);
	
	return output;
}

String CVImgProc::_to_string() const {
	return "[ CVImgProc Module ]";
}