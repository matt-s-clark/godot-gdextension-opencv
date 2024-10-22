#include "CVImgProc.h"

using namespace godot;
using namespace cv;

void CVImgProc::_bind_methods() {
	ClassDB::bind_static_method(get_class_static(), D_METHOD("bilateral_filter", "src", "d", "sigmaColor", "sigmaSpace", "additional_parameters"), &CVImgProc::bilateral_filter);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("blur", "src", "ksize", "additional_parameters"), &CVImgProc::blur);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("box_filter", "src", "ddepth", "ksize", "additional_parameters"), &CVImgProc::box_filter);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("dilate", "src", "kernel", "additional_parameters"), &CVImgProc::dilate);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("erode", "src", "kernel", "additional_parameters"), &CVImgProc::erode);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("filter_2d", "src", "ddepth", "kernel", "additional_parameters"), &CVImgProc::filter_2d);
	ClassDB::bind_static_method( get_class_static(), D_METHOD("gaussian_blur", "src", "ksize", "sigmaX", "additional_parameters"), &CVImgProc::gaussian_blur);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("get_deriv_kernels", "dx", "dy", "ksize", "additional_parameters"), &CVImgProc::get_deriv_kernels);
	ClassDB::bind_static_method( get_class_static(), D_METHOD("get_gabor_kernel", "ksize", "sigma", "theta", "lambd", "gamma", "additional_parameters"), &CVImgProc::get_gabor_kernel);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("get_gaussian_kernel", "ksize", "sigma", "additional_parameters"), &CVImgProc::get_gaussian_kernel);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("get_structuring_element", "shape", "ksize", "additional_parameters"), &CVImgProc::get_structuring_element);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("laplacian", "src", "ddepth", "additional_parameters"), &CVImgProc::laplacian);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("median_blur", "src", "ksize"), &CVImgProc::median_blur);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("morphology_default_border_value"), &CVImgProc::morphology_default_border_value);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("morphology_ex", "src", "op", "kernel", "additional_parameters"), &CVImgProc::morphology_ex);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("pyr_down", "src", "additional_parameters"), &CVImgProc::pyr_down);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("pyr_up", "src", "additional_parameters"), &CVImgProc::pyr_up);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("scharr", "src", "ddepth", "dx", "dy", "additional_parameters"), &CVImgProc::scharr);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("sep_filter_2d", "src", "ddepth", "kernelX", "kernelY", "additional_parameters"), &CVImgProc::sep_filter_2d);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("sobel", "src", "ddepth", "dx", "dy", "additional_parameters"), &CVImgProc::sobel);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("spatial_gradient", "src", "additional_parameters"), &CVImgProc::spatial_gradient);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("convert_maps", "map1", "map2", "dstmap1type", "additional_parameters"), &CVImgProc::convert_maps);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("get_affine_transform", "src", "dst"), &CVImgProc::get_affine_transform);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("get_perspective_transform", "src", "dst", "additional_parameters"), &CVImgProc::get_perspective_transform);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("get_rect_sub_pix", "image", "patchSize", "center", "additional_parameters"), &CVImgProc::get_rect_sub_pix);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("get_rotation_matrix_2d", "center", "angle", "scale"), &CVImgProc::get_rotation_matrix_2d);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("invert_affine_transform", "M"), &CVImgProc::invert_affine_transform);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("linear_polar", "src", "center", "maxRadius", "flags"), &CVImgProc::linear_polar);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("log_polar", "src", "center", "M", "flags"), &CVImgProc::log_polar);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("remap", "src", "map1", "map2", "interpolation", "additional_parameters"), &CVImgProc::remap);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("resize", "src", "dsize", "additional_parameters"), &CVImgProc::resize);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("warp_affine", "src", "M", "dsize", "additional_parameters"), &CVImgProc::warp_affine);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("warp_perspective", "src", "M", "dsize", "additional_parameters"), &CVImgProc::warp_perspective);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("warp_polar", "src", "dsize", "center", "maxRadius", "flags"), &CVImgProc::warp_polar);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("adaptive_threshold", "src", "maxValue", "adaptiveMethod", "thresholdType", "blockSize", "C"), &CVImgProc::adaptive_threshold);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("blend_linear", "src1", "src2", "weights1", "weights2"), &CVImgProc::blend_linear);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("distance_transform", "src", "distanceType", "maskSize", "additional_parameters"), &CVImgProc::distance_transform);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("integral", "src", "additional_parameters"), &CVImgProc::integral);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("threshold", "src", "thresh", "maxval", "type"), &CVImgProc::threshold);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("arrowed_line", "img", "pt1", "pt2", "color", "additional_parameters"), &CVImgProc::arrowed_line);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("circle", "img", "center", "radius", "color", "additional_parameters"), &CVImgProc::circle);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("draw_contours", "image", "contours", "contourIdx", "color", "additional_parameters"), &CVImgProc::draw_contours);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("draw_marker", "img", "position", "color", "additional_parameters"), &CVImgProc::draw_marker);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("ellipse", "img", "center", "axes", "angle", "startAngle", "endAngle", "color", "additional_parameters"), &CVImgProc::ellipse);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("fill_convex_poly", "img", "points", "color", "additional_parameters"), &CVImgProc::fill_convex_poly);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("get_font_scale_from_height", "fontFace", "pixelHeight", "additional_parameters"), &CVImgProc::get_font_scale_from_height);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("line", "img", "pt1", "pt2", "color", "additional_parameters"), &CVImgProc::line);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("rectangle", "img", "additional_parameters"), &CVImgProc::rectangle);
	ClassDB::bind_static_method( get_class_static(), D_METHOD("cvt_color", "src", "code", "additional_parameters"), &CVImgProc::cvt_color);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("demosaicing", "src", "code", "additional_parameters"), &CVImgProc::demosaicing);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("apply_color_map", "src", "userColor"), &CVImgProc::apply_color_map);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("compare_hist", "H1", "H2", "method"), &CVImgProc::compare_hist);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("equalize_hist", "src"), &CVImgProc::equalize_hist);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("arc_length", "curve", "closed"), &CVImgProc::arc_length);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("bounding_rect", "array"), &CVImgProc::bounding_rect);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("connected_components", "image", "connectivity", "ltype", "ccltype"), &CVImgProc::connected_components);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("connected_components_with_stats", "image", "connectivity", "ltype", "ccltype"), &CVImgProc::connected_components_with_stats);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("contour_area", "contour", "additional_parameters"), &CVImgProc::contour_area);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("convex_hull", "points", "additional_parameters"), &CVImgProc::convex_hull);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("convexity_defects", "contour", "convexhull"), &CVImgProc::convexity_defects);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("find_contours", "image", "mode", "method", "additional_parameters"), &CVImgProc::find_contours);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("fit_line", "points", "distType", "param", "reps", "aeps"), &CVImgProc::fit_line);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("intersect_convex_convex", "p1", "p2", "additional_parameters"), &CVImgProc::intersect_convex_convex);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("is_contour_convex", "contour"), &CVImgProc::is_contour_convex);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("match_shapes", "contour1", "contour2", "method", "parameter"), &CVImgProc::match_shapes);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("min_enclosing_triangle", "points"), &CVImgProc::min_enclosing_triangle);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("moments", "array", "additional_parameters"), &CVImgProc::moments);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("point_polygon_test", "contour", "pt", "measureDist"), &CVImgProc::point_polygon_test);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("accumulate", "src", "dst", "additional_parameters"), &CVImgProc::accumulate);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("accumulate_product", "src1", "src2", "dst", "additional_parameters"), &CVImgProc::accumulate_product);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("accumulate_square", "src", "dst", "additional_parameters"), &CVImgProc::accumulate_square);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("accumulate_weighted", "src", "dst", "alpha", "additional_parameters"), &CVImgProc::accumulate_weighted);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("create_hanning_window", "winSize", "type"), &CVImgProc::create_hanning_window);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("canny", "image", "threshold1", "threshold2", "additional_parameters"), &CVImgProc::canny);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("corner_eigen_vals_and_vecs", "src", "blockSize", "ksize", "additional_parameters"), &CVImgProc::corner_eigen_vals_and_vecs);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("corner_harris", "src", "blockSize", "ksize", "k", "additional_parameters"), &CVImgProc::corner_harris);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("corner_min_eigen_val", "src", "blockSize", "additional_parameters"), &CVImgProc::corner_min_eigen_val);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("good_features_to_track", "image", "maxCorners", "qualityLevel", "minDistance", "additional_parameters"), &CVImgProc::good_features_to_track);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("hough_circles", "image", "method", "dp", "minDist", "additional_parameters"), &CVImgProc::hough_circles);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("hough_lines", "image", "rho", "theta", "threshold", "additional_parameters"), &CVImgProc::hough_lines);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("hough_lines_p", "image", "rho", "theta", "threshold", "additional_parameters"), &CVImgProc::hough_lines_p);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("hough_lines_point_set", "point", "lines_max", "threshold", "min_rho", "max_rho", "rho_step", "min_theta", "max_theta", "theta_step"), &CVImgProc::hough_lines_point_set);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("pre_corner_detect", "src", "ksize", "additional_parameters"), &CVImgProc::pre_corner_detect);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("match_template", "image", "templ", "method", "additional_parameters"), &CVImgProc::match_template);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("grab_cut", "img", "mask", "rect", "bgdModel", "fgdModel", "iterCount", "additional_parameters"), &CVImgProc::grab_cut);
	ClassDB::bind_static_method(get_class_static(), D_METHOD("watershed", "image", "markers"), &CVImgProc::watershed);
}

CVImgProc::CVImgProc() {
}

CVImgProc::~CVImgProc() {
}

Ref<CVMat> CVImgProc::bilateral_filter(Ref<CVMat> src, int d, float sigmaColor, float sigmaSpace, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, borderType, BORDER_DEFAULT);

	SAFE_CALL(cv::bilateralFilter(src->get_pointer(), dst, d, sigmaColor, sigmaSpace, borderType));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::blur(Ref<CVMat> src, Vector2 ksize, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_CONVERTIBLE_PROPERTY(Point, Variant::VECTOR2, anchor, Point(-1,-1));
	GET_SIMPLE_PROPERTY(int, Variant::INT, borderType, BORDER_DEFAULT);

	SAFE_CALL(cv::blur(src->get_pointer(), dst, Size(ksize.x, ksize.y), anchor, borderType));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::box_filter(Ref<CVMat> src, int ddepth, Vector2 ksize, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_CONVERTIBLE_PROPERTY(Point, Variant::VECTOR2, anchor, Point(-1,-1));
	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, normalize, true);
	GET_SIMPLE_PROPERTY(int, Variant::INT, borderType, BORDER_DEFAULT);

	SAFE_CALL(cv::boxFilter(src->get_pointer(), dst, ddepth, Size(ksize.x, ksize.y), anchor, normalize, borderType));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::dilate(Ref<CVMat> src, Ref<CVMat> kernel, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(kernel, output, "kernel should not be null.");

	GET_CONVERTIBLE_PROPERTY(Point, Variant::VECTOR2, anchor, Point(-1,-1));
	GET_SIMPLE_PROPERTY(int, Variant::INT, iterations, 1);
	GET_SIMPLE_PROPERTY(int, Variant::INT, borderType, BORDER_CONSTANT);
	GET_OBJECT_PROPERTY(Ref<CVScalar>, borderValue, morphologyDefaultBorderValue());

	SAFE_CALL(cv::dilate(src->get_pointer(), dst, kernel->get_pointer(), anchor, iterations, borderType, borderValue->get_pointer()));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::erode(Ref<CVMat> src, Ref<CVMat> kernel, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(kernel, output, "kernel should not be null.");

	GET_CONVERTIBLE_PROPERTY(Point, Variant::VECTOR2, anchor, Point(-1,-1));
	GET_SIMPLE_PROPERTY(int, Variant::INT, iterations, 1);
	GET_SIMPLE_PROPERTY(int, Variant::INT, borderType, BORDER_CONSTANT);
	GET_OBJECT_PROPERTY(Ref<CVScalar>, borderValue, morphologyDefaultBorderValue());

	SAFE_CALL(cv::erode(src->get_pointer(), dst, kernel->get_pointer(), anchor, iterations, borderType, borderValue->get_pointer()));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::filter_2d(Ref<CVMat> src, int ddepth, Ref<CVMat> kernel, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(kernel, output, "kernel should not be null.");

	GET_CONVERTIBLE_PROPERTY(Point, Variant::VECTOR2, anchor, Point(-1,-1));
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, delta, 0);
	GET_SIMPLE_PROPERTY(int, Variant::INT, borderType, BORDER_DEFAULT);

	SAFE_CALL(cv::filter2D(src->get_pointer(), dst, ddepth, kernel->get_pointer(), anchor, delta, borderType));

	output->set_pointer(dst);

	return output;
}

// Custom Implementation

Ref<CVMat> CVImgProc::gaussian_blur(Ref<CVMat> src, Vector2 ksize, float sigmaX, Dictionary additional_parameters) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	float sigmaY = 0;
	int borderType = 4;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_ADITIONAL_PROPERTY(additional_parameters, sigmaY, "sigma_y", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, borderType, "border_type", Variant::INT, "INT");

	SAFE_CALL(cv::GaussianBlur(src->get_pointer(), matOut, cv::Size(ksize.x, ksize.y), sigmaX, sigmaY, borderType));

	output->set_pointer(matOut);

	return output;
}

Dictionary CVImgProc::get_deriv_kernels(int dx, int dy, int ksize, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outkx;
	outkx.instantiate();
	Ref<CVMat> outky;
	outky.instantiate();
	Mat kx;
	Mat ky;

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, normalize, false);
	GET_SIMPLE_PROPERTY(int, Variant::INT, ktype, CV_32F);

	SAFE_CALL(cv::getDerivKernels(kx, ky, dx, dy, ksize, normalize, ktype));

	outkx->set_pointer(kx);
	outky->set_pointer(ky);

	output["kx"] = outkx;
	output["ky"] = outky;

	return output;
}

// Custom Implementation

Ref<CVMat> CVImgProc::get_gabor_kernel(Vector2 ksize, float sigma, float theta, float lambd, float gamma, Dictionary additional_parameters) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	int ktype = 6;
	float psi = 1.5707963267948966;

	GET_ADITIONAL_PROPERTY(additional_parameters, ktype, "ktype", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, psi, "psi", Variant::FLOAT, "FLOAT");

	SAFE_CALL(matOut = cv::getGaborKernel(cv::Size(ksize.x, ksize.y), sigma, theta, lambd, gamma, psi, ktype));

	output->set_pointer(matOut);

	return output;
}

Ref<CVMat> CVImgProc::get_gaussian_kernel(int ksize, float sigma, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat defReturn;

	GET_SIMPLE_PROPERTY(int, Variant::INT, ktype, CV_64F);

	SAFE_CALL(defReturn = cv::getGaussianKernel(ksize, sigma, ktype));

	output->set_pointer(defReturn);

	return output;
}

Ref<CVMat> CVImgProc::get_structuring_element(int shape, Vector2 ksize, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat defReturn;

	GET_CONVERTIBLE_PROPERTY(Point, Variant::VECTOR2, anchor, Point(-1,-1));

	SAFE_CALL(defReturn = cv::getStructuringElement(shape, Size(ksize.x, ksize.y), anchor));

	output->set_pointer(defReturn);

	return output;
}

Ref<CVMat> CVImgProc::laplacian(Ref<CVMat> src, int ddepth, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, ksize, 1);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, scale, 1);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, delta, 0);
	GET_SIMPLE_PROPERTY(int, Variant::INT, borderType, BORDER_DEFAULT);

	SAFE_CALL(cv::Laplacian(src->get_pointer(), dst, ddepth, ksize, scale, delta, borderType));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::median_blur(Ref<CVMat> src, int ksize){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::medianBlur(src->get_pointer(), dst, ksize));

	output->set_pointer(dst);

	return output;
}

Ref<CVScalar> CVImgProc::morphology_default_border_value(){
	Ref<CVScalar> output;
	output.instantiate();
	Scalar defReturn;

	SAFE_CALL(defReturn = cv::morphologyDefaultBorderValue());

	output->set_pointer(defReturn);

	return output;
}

Ref<CVMat> CVImgProc::morphology_ex(Ref<CVMat> src, int op, Ref<CVMat> kernel, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(kernel, output, "kernel should not be null.");

	GET_CONVERTIBLE_PROPERTY(Point, Variant::VECTOR2, anchor, Point(-1,-1));
	GET_SIMPLE_PROPERTY(int, Variant::INT, iterations, 1);
	GET_SIMPLE_PROPERTY(int, Variant::INT, borderType, BORDER_CONSTANT);
	GET_OBJECT_PROPERTY(Ref<CVScalar>, borderValue, morphologyDefaultBorderValue());

	SAFE_CALL(cv::morphologyEx(src->get_pointer(), dst, op, kernel->get_pointer(), anchor, iterations, borderType, borderValue->get_pointer()));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::pyr_down(Ref<CVMat> src, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_CONVERTIBLE_PROPERTY(Size, Variant::VECTOR2, dstsize, Size());
	GET_SIMPLE_PROPERTY(int, Variant::INT, borderType, BORDER_DEFAULT);

	SAFE_CALL(cv::pyrDown(src->get_pointer(), dst, dstsize, borderType));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::pyr_up(Ref<CVMat> src, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_CONVERTIBLE_PROPERTY(Size, Variant::VECTOR2, dstsize, Size());
	GET_SIMPLE_PROPERTY(int, Variant::INT, borderType, BORDER_DEFAULT);

	SAFE_CALL(cv::pyrUp(src->get_pointer(), dst, dstsize, borderType));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::scharr(Ref<CVMat> src, int ddepth, int dx, int dy, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, scale, 1);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, delta, 0);
	GET_SIMPLE_PROPERTY(int, Variant::INT, borderType, BORDER_DEFAULT);

	SAFE_CALL(cv::Scharr(src->get_pointer(), dst, ddepth, dx, dy, scale, delta, borderType));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::sep_filter_2d(Ref<CVMat> src, int ddepth, Ref<CVMat> kernelX, Ref<CVMat> kernelY, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(kernelX, output, "kernelX should not be null.");
	ERR_FAIL_NULL_V_MSG(kernelY, output, "kernelY should not be null.");

	GET_CONVERTIBLE_PROPERTY(Point, Variant::VECTOR2, anchor, Point(-1,-1));
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, delta, 0);
	GET_SIMPLE_PROPERTY(int, Variant::INT, borderType, BORDER_DEFAULT);

	SAFE_CALL(cv::sepFilter2D(src->get_pointer(), dst, ddepth, kernelX->get_pointer(), kernelY->get_pointer(), anchor, delta, borderType));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::sobel(Ref<CVMat> src, int ddepth, int dx, int dy, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, ksize, 3);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, scale, 1);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, delta, 0);
	GET_SIMPLE_PROPERTY(int, Variant::INT, borderType, BORDER_DEFAULT);

	SAFE_CALL(cv::Sobel(src->get_pointer(), dst, ddepth, dx, dy, ksize, scale, delta, borderType));

	output->set_pointer(dst);

	return output;
}

Dictionary CVImgProc::spatial_gradient(Ref<CVMat> src, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outdx;
	outdx.instantiate();
	Ref<CVMat> outdy;
	outdy.instantiate();
	Mat dx;
	Mat dy;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, ksize, 3);
	GET_SIMPLE_PROPERTY(int, Variant::INT, borderType, BORDER_DEFAULT);

	SAFE_CALL(cv::spatialGradient(src->get_pointer(), dx, dy, ksize, borderType));

	outdx->set_pointer(dx);
	outdy->set_pointer(dy);

	output["dx"] = outdx;
	output["dy"] = outdy;

	return output;
}

Dictionary CVImgProc::convert_maps(Ref<CVMat> map1, Ref<CVMat> map2, int dstmap1type, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outdstmap1;
	outdstmap1.instantiate();
	Ref<CVMat> outdstmap2;
	outdstmap2.instantiate();
	Mat dstmap1;
	Mat dstmap2;

	ERR_FAIL_NULL_V_MSG(map1, output, "map1 should not be null.");
	ERR_FAIL_NULL_V_MSG(map2, output, "map2 should not be null.");

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, nninterpolation, false);

	SAFE_CALL(cv::convertMaps(map1->get_pointer(), map2->get_pointer(), dstmap1, dstmap2, dstmap1type, nninterpolation));

	outdstmap1->set_pointer(dstmap1);
	outdstmap2->set_pointer(dstmap2);

	output["dstmap1"] = outdstmap1;
	output["dstmap2"] = outdstmap2;

	return output;
}

Ref<CVMat> CVImgProc::get_affine_transform(Ref<CVMat> src, Ref<CVMat> dst){
	Ref<CVMat> output;
	output.instantiate();
	Mat defReturn;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(dst, output, "dst should not be null.");

	SAFE_CALL(defReturn = cv::getAffineTransform(src->get_pointer(), dst->get_pointer()));

	output->set_pointer(defReturn);

	return output;
}

Ref<CVMat> CVImgProc::get_perspective_transform(Ref<CVMat> src, Ref<CVMat> dst, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat defReturn;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(dst, output, "dst should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, solveMethod, DECOMP_LU);

	SAFE_CALL(defReturn = cv::getPerspectiveTransform(src->get_pointer(), dst->get_pointer(), solveMethod));

	output->set_pointer(defReturn);

	return output;
}

Ref<CVMat> CVImgProc::get_rect_sub_pix(Ref<CVMat> image, Vector2 patchSize, Vector2 center, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat patch;

	ERR_FAIL_NULL_V_MSG(image, output, "image should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, patchType, -1);

	SAFE_CALL(cv::getRectSubPix(image->get_pointer(), Size(patchSize.x, patchSize.y), Point2f(center.x, center.y), patch, patchType));

	output->set_pointer(patch);

	return output;
}

Ref<CVMat> CVImgProc::get_rotation_matrix_2d(Vector2 center, float angle, float scale){
	Ref<CVMat> output;
	output.instantiate();
	Mat defReturn;

	SAFE_CALL(defReturn = cv::getRotationMatrix2D(Point2f(center.x, center.y), angle, scale));

	output->set_pointer(defReturn);

	return output;
}

Ref<CVMat> CVImgProc::invert_affine_transform(Ref<CVMat> M){
	Ref<CVMat> output;
	output.instantiate();
	Mat iM;

	ERR_FAIL_NULL_V_MSG(M, output, "M should not be null.");

	SAFE_CALL(cv::invertAffineTransform(M->get_pointer(), iM));

	output->set_pointer(iM);

	return output;
}

Ref<CVMat> CVImgProc::linear_polar(Ref<CVMat> src, Vector2 center, float maxRadius, int flags){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::linearPolar(src->get_pointer(), dst, Point2f(center.x, center.y), maxRadius, flags));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::log_polar(Ref<CVMat> src, Vector2 center, float M, int flags){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::logPolar(src->get_pointer(), dst, Point2f(center.x, center.y), M, flags));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::remap(Ref<CVMat> src, Ref<CVMat> map1, Ref<CVMat> map2, int interpolation, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(map1, output, "map1 should not be null.");
	ERR_FAIL_NULL_V_MSG(map2, output, "map2 should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, borderMode, BORDER_CONSTANT);
	GET_OBJECT_PROPERTY(Ref<CVScalar>, borderValue, Scalar());

	SAFE_CALL(cv::remap(src->get_pointer(), dst, map1->get_pointer(), map2->get_pointer(), interpolation, borderMode, borderValue->get_pointer()));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::resize(Ref<CVMat> src, Vector2 dsize, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, fx, 0);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, fy, 0);
	GET_SIMPLE_PROPERTY(int, Variant::INT, interpolation, INTER_LINEAR);

	SAFE_CALL(cv::resize(src->get_pointer(), dst, Size(dsize.x, dsize.y), fx, fy, interpolation));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::warp_affine(Ref<CVMat> src, Ref<CVMat> M, Vector2 dsize, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(M, output, "M should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, INTER_LINEAR);
	GET_SIMPLE_PROPERTY(int, Variant::INT, borderMode, BORDER_CONSTANT);
	GET_OBJECT_PROPERTY(Ref<CVScalar>, borderValue, Scalar());

	SAFE_CALL(cv::warpAffine(src->get_pointer(), dst, M->get_pointer(), Size(dsize.x, dsize.y), flags, borderMode, borderValue->get_pointer()));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::warp_perspective(Ref<CVMat> src, Ref<CVMat> M, Vector2 dsize, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(M, output, "M should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, flags, INTER_LINEAR);
	GET_SIMPLE_PROPERTY(int, Variant::INT, borderMode, BORDER_CONSTANT);
	GET_OBJECT_PROPERTY(Ref<CVScalar>, borderValue, Scalar());

	SAFE_CALL(cv::warpPerspective(src->get_pointer(), dst, M->get_pointer(), Size(dsize.x, dsize.y), flags, borderMode, borderValue->get_pointer()));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::warp_polar(Ref<CVMat> src, Vector2 dsize, Vector2 center, float maxRadius, int flags){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::warpPolar(src->get_pointer(), dst, Size(dsize.x, dsize.y), Point2f(center.x, center.y), maxRadius, flags));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::adaptive_threshold(Ref<CVMat> src, float maxValue, int adaptiveMethod, int thresholdType, int blockSize, float C){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::adaptiveThreshold(src->get_pointer(), dst, maxValue, adaptiveMethod, thresholdType, blockSize, C));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::blend_linear(Ref<CVMat> src1, Ref<CVMat> src2, Ref<CVMat> weights1, Ref<CVMat> weights2){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src1, output, "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, output, "src2 should not be null.");
	ERR_FAIL_NULL_V_MSG(weights1, output, "weights1 should not be null.");
	ERR_FAIL_NULL_V_MSG(weights2, output, "weights2 should not be null.");

	SAFE_CALL(cv::blendLinear(src1->get_pointer(), src2->get_pointer(), weights1->get_pointer(), weights2->get_pointer(), dst));

	output->set_pointer(dst);

	return output;
}

Dictionary CVImgProc::distance_transform(Ref<CVMat> src, int distanceType, int maskSize, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outdst;
	outdst.instantiate();
	Ref<CVMat> outlabels;
	outlabels.instantiate();
	Mat dst;
	Mat labels;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, labelType, DIST_LABEL_CCOMP);

	SAFE_CALL(cv::distanceTransform(src->get_pointer(), dst, labels, distanceType, maskSize, labelType));

	outdst->set_pointer(dst);
	outlabels->set_pointer(labels);

	output["dst"] = outdst;
	output["labels"] = outlabels;

	return output;
}

Dictionary CVImgProc::integral(Ref<CVMat> src, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outsum;
	outsum.instantiate();
	Ref<CVMat> outsqsum;
	outsqsum.instantiate();
	Ref<CVMat> outtilted;
	outtilted.instantiate();
	Mat sum;
	Mat sqsum;
	Mat tilted;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, sdepth, -1);
	GET_SIMPLE_PROPERTY(int, Variant::INT, sqdepth, -1);

	SAFE_CALL(cv::integral(src->get_pointer(), sum, sqsum, tilted, sdepth, sqdepth));

	outsum->set_pointer(sum);
	outsqsum->set_pointer(sqsum);
	outtilted->set_pointer(tilted);

	output["sum"] = outsum;
	output["sqsum"] = outsqsum;
	output["tilted"] = outtilted;

	return output;
}

Dictionary CVImgProc::threshold(Ref<CVMat> src, float thresh, float maxval, int type){
	Dictionary output;
	Ref<CVMat> outdst;
	outdst.instantiate();
	double defReturn;
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(defReturn = cv::threshold(src->get_pointer(), dst, thresh, maxval, type));

	outdst->set_pointer(dst);

	output["defReturn"] = defReturn;
	output["dst"] = outdst;

	return output;
}

void CVImgProc::arrowed_line(Ref<CVMat> img, Vector2 pt1, Vector2 pt2, Ref<CVScalar> color, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(img, , "img should not be null.");
	ERR_FAIL_NULL_V_MSG(color, , "color should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, thickness, 1);
	GET_SIMPLE_PROPERTY(int, Variant::INT, line_type, 8);
	GET_SIMPLE_PROPERTY(int, Variant::INT, shift, 0);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, tipLength, 0.1);

	SAFE_CALL(cv::arrowedLine(img->get_pointer(), Point(pt1.x, pt1.y), Point(pt2.x, pt2.y), color->get_pointer(), thickness, line_type, shift, tipLength));
}

void CVImgProc::circle(Ref<CVMat> img, Vector2 center, int radius, Ref<CVScalar> color, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(img, , "img should not be null.");
	ERR_FAIL_NULL_V_MSG(color, , "color should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, thickness, 1);
	GET_SIMPLE_PROPERTY(int, Variant::INT, lineType, LINE_8);
	GET_SIMPLE_PROPERTY(int, Variant::INT, shift, 0);

	SAFE_CALL(cv::circle(img->get_pointer(), Point(center.x, center.y), radius, color->get_pointer(), thickness, lineType, shift));
}

// Custom Implementation

void CVImgProc::draw_contours(Ref<CVMat> image, Array contours, int contourIdx, Ref<CVScalar> color, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(image, , "image should not be null.");
	ERR_FAIL_NULL_V_MSG(color, , "color should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, thickness, 1);
	GET_SIMPLE_PROPERTY(int, Variant::INT, lineType, LINE_8);
	GET_OBJECT_PROPERTY(Ref<CVMat>, hierarchy, Mat());
	GET_SIMPLE_PROPERTY(int, Variant::INT, maxLevel, INT_MAX);
	GET_CONVERTIBLE_PROPERTY(Point, Variant::VECTOR2, offset, Point());

	std::vector<std::vector<cv::Point>> incontours;

	for (size_t i = 0; i < contours.size(); i++) {
		std::vector<cv::Point> newContour;
		Array contour = contours[i];
		
		for (size_t j = 0; j < contour.size(); j++) {
			Vector2 p = contour[j];
			newContour.push_back(cv::Point(p.x, p.y));
		}

		incontours.push_back(newContour);
	}

	cv::drawContours(image->get_pointer(), incontours, contourIdx, color->get_pointer(), thickness, lineType, hierarchy->get_pointer(), maxLevel, offset);
}

void CVImgProc::draw_marker(Ref<CVMat> img, Vector2 position, Ref<CVScalar> color, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(img, , "img should not be null.");
	ERR_FAIL_NULL_V_MSG(color, , "color should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, markerType, MARKER_CROSS);
	GET_SIMPLE_PROPERTY(int, Variant::INT, markerSize, 20);
	GET_SIMPLE_PROPERTY(int, Variant::INT, thickness, 1);
	GET_SIMPLE_PROPERTY(int, Variant::INT, line_type, 8);

	SAFE_CALL(cv::drawMarker(img->get_pointer(), Point(position.x, position.y), color->get_pointer(), markerType, markerSize, thickness, line_type));
}

void CVImgProc::ellipse(Ref<CVMat> img, Vector2 center, Vector2 axes, float angle, float startAngle, float endAngle, Ref<CVScalar> color, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(img, , "img should not be null.");
	ERR_FAIL_NULL_V_MSG(color, , "color should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, thickness, 1);
	GET_SIMPLE_PROPERTY(int, Variant::INT, lineType, LINE_8);
	GET_SIMPLE_PROPERTY(int, Variant::INT, shift, 0);

	SAFE_CALL(cv::ellipse(img->get_pointer(), Point(center.x, center.y), Size(axes.x, axes.y), angle, startAngle, endAngle, color->get_pointer(), thickness, lineType, shift));
}

void CVImgProc::fill_convex_poly(Ref<CVMat> img, Ref<CVMat> points, Ref<CVScalar> color, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(img, , "img should not be null.");
	ERR_FAIL_NULL_V_MSG(points, , "points should not be null.");
	ERR_FAIL_NULL_V_MSG(color, , "color should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, lineType, LINE_8);
	GET_SIMPLE_PROPERTY(int, Variant::INT, shift, 0);

	SAFE_CALL(cv::fillConvexPoly(img->get_pointer(), points->get_pointer(), color->get_pointer(), lineType, shift));
}

float CVImgProc::get_font_scale_from_height(int fontFace, int pixelHeight, Dictionary additional_parameters){
	float output;
	double defReturn;

	GET_SIMPLE_PROPERTY(int, Variant::INT, thickness, 1);

	SAFE_CALL(output = cv::getFontScaleFromHeight(fontFace, pixelHeight, thickness));

	return output;
}

void CVImgProc::line(Ref<CVMat> img, Vector2 pt1, Vector2 pt2, Ref<CVScalar> color, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(img, , "img should not be null.");
	ERR_FAIL_NULL_V_MSG(color, , "color should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, thickness, 1);
	GET_SIMPLE_PROPERTY(int, Variant::INT, lineType, LINE_8);
	GET_SIMPLE_PROPERTY(int, Variant::INT, shift, 0);

	SAFE_CALL(cv::line(img->get_pointer(), Point(pt1.x, pt1.y), Point(pt2.x, pt2.y), color->get_pointer(), thickness, lineType, shift));
}

// Custom Implementation

void CVImgProc::rectangle(Ref<CVMat> img, Dictionary additional_parameters) {
	Ref<CVRect> rect;
	Vector2 pt1 = Vector2(-1, -1), pt2 = Vector2(-1, -1);
	int thickness = 1, lineType = 8, shift = 0;

	ERR_FAIL_NULL_V_MSG(img, , "img should not be null.");

	GET_ADITIONAL_PROPERTY(additional_parameters, rect, "rec", Variant::OBJECT, "CVRECT");
	GET_ADITIONAL_PROPERTY(additional_parameters, pt1, "pt1", Variant::VECTOR2, "VECTOR2");
	GET_ADITIONAL_PROPERTY(additional_parameters, pt2, "pt2", Variant::VECTOR2, "VECTOR2");
	GET_OBJECT_PROPERTY(Ref<CVScalar>, color, cv::Scalar(0, 255, 0));
	GET_ADITIONAL_PROPERTY(additional_parameters, thickness, "thickness", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, lineType, "line_type", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, shift, "shift", Variant::INT, "INT");

	if (!rect.is_null()) {
		SAFE_CALL(cv::rectangle(
				img->get_pointer(),
				rect->get_pointer(),
				color->get_pointer(),
				thickness,
				lineType,
				shift));

	} else if (pt1.x >= 0 && pt2.x >= 0 && pt1.y >= 0 && pt2.y >= 0) {
		SAFE_CALL(cv::rectangle(
				img->get_pointer(),
				cv::Point((int)pt1.x, (int)pt1.y),
				cv::Point((int)pt2.x, (int)pt2.y),
				color->get_pointer(),
				thickness,
				lineType,
				shift));
	} else {
		UtilityFunctions::push_error("Invalid input: either rec or pt1 and pt2 needed");
	}
}

// Custom Implementation

Ref<CVMat> CVImgProc::cvt_color(Ref<CVMat> src, int code, Dictionary additional_parameters) {
	cv::Mat matOut;
	Ref<CVMat> output;
	output.instantiate();

	int dstCn = 0;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_ADITIONAL_PROPERTY(additional_parameters, dstCn, "dst_cn", Variant::INT, "INT");

	SAFE_CALL(cv::cvtColor(src->get_pointer(), matOut, code, dstCn));

	output->set_pointer(matOut);

	return output;
}

Ref<CVMat> CVImgProc::demosaicing(Ref<CVMat> src, int code, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, dstCn, 0);

	SAFE_CALL(cv::demosaicing(src->get_pointer(), dst, code, dstCn));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::apply_color_map(Ref<CVMat> src, Ref<CVMat> userColor){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");
	ERR_FAIL_NULL_V_MSG(userColor, output, "userColor should not be null.");

	SAFE_CALL(cv::applyColorMap(src->get_pointer(), dst, userColor->get_pointer()));

	output->set_pointer(dst);

	return output;
}

float CVImgProc::compare_hist(Ref<CVMat> H1, Ref<CVMat> H2, int method){
	float output;
	double defReturn;

	ERR_FAIL_NULL_V_MSG(H1, output, "H1 should not be null.");
	ERR_FAIL_NULL_V_MSG(H2, output, "H2 should not be null.");

	SAFE_CALL(output = cv::compareHist(H1->get_pointer(), H2->get_pointer(), method));

	return output;
}

Ref<CVMat> CVImgProc::equalize_hist(Ref<CVMat> src){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	SAFE_CALL(cv::equalizeHist(src->get_pointer(), dst));

	output->set_pointer(dst);

	return output;
}

float CVImgProc::arc_length(Ref<CVMat> curve, bool closed){
	float output;
	double defReturn;

	ERR_FAIL_NULL_V_MSG(curve, output, "curve should not be null.");

	SAFE_CALL(output = cv::arcLength(curve->get_pointer(), closed));

	return output;
}

Ref<CVRect> CVImgProc::bounding_rect(Ref<CVMat> array){
	Ref<CVRect> output;
	output.instantiate();
	Rect defReturn;

	ERR_FAIL_NULL_V_MSG(array, output, "array should not be null.");

	SAFE_CALL(defReturn = cv::boundingRect(array->get_pointer()));

	output->set_pointer(defReturn);

	return output;
}

Dictionary CVImgProc::connected_components(Ref<CVMat> image, int connectivity, int ltype, int ccltype){
	Dictionary output;
	Ref<CVMat> outlabels;
	outlabels.instantiate();
	int defReturn;
	Mat labels;

	ERR_FAIL_NULL_V_MSG(image, output, "image should not be null.");

	SAFE_CALL(defReturn = cv::connectedComponents(image->get_pointer(), labels, connectivity, ltype, ccltype));

	outlabels->set_pointer(labels);

	output["defReturn"] = defReturn;
	output["labels"] = outlabels;

	return output;
}

Dictionary CVImgProc::connected_components_with_stats(Ref<CVMat> image, int connectivity, int ltype, int ccltype){
	Dictionary output;
	Ref<CVMat> outlabels;
	outlabels.instantiate();
	Ref<CVMat> outstats;
	outstats.instantiate();
	Ref<CVMat> outcentroids;
	outcentroids.instantiate();
	int defReturn;
	Mat labels;
	Mat stats;
	Mat centroids;

	ERR_FAIL_NULL_V_MSG(image, output, "image should not be null.");

	SAFE_CALL(defReturn = cv::connectedComponentsWithStats(image->get_pointer(), labels, stats, centroids, connectivity, ltype, ccltype));

	outlabels->set_pointer(labels);
	outstats->set_pointer(stats);
	outcentroids->set_pointer(centroids);

	output["defReturn"] = defReturn;
	output["labels"] = outlabels;
	output["stats"] = outstats;
	output["centroids"] = outcentroids;

	return output;
}

// Custom Implementation

float CVImgProc::contour_area(Variant contour, Dictionary additional_parameters) {
	float output;

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, oriented, false);

	if (contour.get_type() == Variant::PACKED_VECTOR2_ARRAY) {
		std::vector<Point> contourIn;
		PackedVector2Array contourCast = contour;
		for (size_t i = 0; i < contourCast.size(); i++) {
			contourIn.push_back(Point(contourCast[i].x, contourCast[i].y));
		}

		SAFE_CALL(output = cv::contourArea(contourIn, oriented));
	} else if (contour.get_type() == Variant::OBJECT) {
		Ref<CVMat> contourIn = contour;

		ERR_FAIL_NULL_V_MSG(contourIn, output, "array should not be null.");

		SAFE_CALL(output = cv::contourArea(contourIn->get_pointer(), oriented));
	} else {
		UtilityFunctions::push_error("Type not supported, contour should be Mat or PackedVector2Array.");
	}

	return output;
}

Ref<CVMat> CVImgProc::convex_hull(Ref<CVMat> points, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat hull;

	ERR_FAIL_NULL_V_MSG(points, output, "points should not be null.");

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, clockwise, false);
	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, returnPoints, true);

	SAFE_CALL(cv::convexHull(points->get_pointer(), hull, clockwise, returnPoints));

	output->set_pointer(hull);

	return output;
}

Ref<CVMat> CVImgProc::convexity_defects(Ref<CVMat> contour, Ref<CVMat> convexhull){
	Ref<CVMat> output;
	output.instantiate();
	Mat convexityDefects;

	ERR_FAIL_NULL_V_MSG(contour, output, "contour should not be null.");
	ERR_FAIL_NULL_V_MSG(convexhull, output, "convexhull should not be null.");

	SAFE_CALL(cv::convexityDefects(contour->get_pointer(), convexhull->get_pointer(), convexityDefects));

	output->set_pointer(convexityDefects);

	return output;
}

// Custom Implementation

Dictionary CVImgProc::find_contours(Ref<CVMat> image, int mode, int method, Dictionary additional_parameters) {
	Dictionary output;
	Ref<CVMat> outhierarchy;
	Array outcontours;
	outhierarchy.instantiate();
	std::vector<std::vector<cv::Point>> contours;
	Mat hierarchy;

	ERR_FAIL_NULL_V_MSG(image, output, "image should not be null.");

	GET_CONVERTIBLE_PROPERTY(Point, Variant::VECTOR2, offset, Point());

	SAFE_CALL(cv::findContours(image->get_pointer(), contours, hierarchy, mode, method, offset));

	for (std::vector<cv::Point> contour : contours) {
		PackedVector2Array newContour = PackedVector2Array();

		for (cv::Point p : contour) {
			newContour.append(Vector2(p.x, p.y));
		}

		outcontours.push_back(newContour);
	}

	outhierarchy->set_pointer(hierarchy);

	output["contours"] = outcontours;
	output["hierarchy"] = outhierarchy;

	return output;
}

Ref<CVMat> CVImgProc::fit_line(Ref<CVMat> points, int distType, float param, float reps, float aeps){
	Ref<CVMat> output;
	output.instantiate();
	Mat line;

	ERR_FAIL_NULL_V_MSG(points, output, "points should not be null.");

	SAFE_CALL(cv::fitLine(points->get_pointer(), line, distType, param, reps, aeps));

	output->set_pointer(line);

	return output;
}

Dictionary CVImgProc::intersect_convex_convex(Ref<CVMat> p1, Ref<CVMat> p2, Dictionary additional_parameters){
	Dictionary output;
	Ref<CVMat> outp12;
	outp12.instantiate();
	float defReturn;
	Mat p12;

	ERR_FAIL_NULL_V_MSG(p1, output, "p1 should not be null.");
	ERR_FAIL_NULL_V_MSG(p2, output, "p2 should not be null.");

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, handleNested, true);

	SAFE_CALL(defReturn = cv::intersectConvexConvex(p1->get_pointer(), p2->get_pointer(), p12, handleNested));

	outp12->set_pointer(p12);

	output["defReturn"] = defReturn;
	output["p12"] = outp12;

	return output;
}

bool CVImgProc::is_contour_convex(Ref<CVMat> contour){
	bool output;
	bool defReturn;

	ERR_FAIL_NULL_V_MSG(contour, output, "contour should not be null.");

	SAFE_CALL(output = cv::isContourConvex(contour->get_pointer()));

	return output;
}

float CVImgProc::match_shapes(Ref<CVMat> contour1, Ref<CVMat> contour2, int method, float parameter){
	float output;
	double defReturn;

	ERR_FAIL_NULL_V_MSG(contour1, output, "contour1 should not be null.");
	ERR_FAIL_NULL_V_MSG(contour2, output, "contour2 should not be null.");

	SAFE_CALL(output = cv::matchShapes(contour1->get_pointer(), contour2->get_pointer(), method, parameter));

	return output;
}

Dictionary CVImgProc::min_enclosing_triangle(Ref<CVMat> points){
	Dictionary output;
	Ref<CVMat> outtriangle;
	outtriangle.instantiate();
	double defReturn;
	Mat triangle;

	ERR_FAIL_NULL_V_MSG(points, output, "points should not be null.");

	SAFE_CALL(defReturn = cv::minEnclosingTriangle(points->get_pointer(), triangle));

	outtriangle->set_pointer(triangle);

	output["defReturn"] = defReturn;
	output["triangle"] = outtriangle;

	return output;
}

// Custom Implementation

Ref<CVMoments> CVImgProc::moments(Variant array, Dictionary additional_parameters) {
	Moments outMoment;
	Ref<CVMoments> output;
	output.instantiate();

	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, binaryImage, false);

	if (array.get_type() == Variant::PACKED_VECTOR2_ARRAY) {
		std::vector<Point> arrayIn;
		PackedVector2Array arrayCast = array;
		for (size_t i = 0; i < arrayCast.size(); i++) {
			arrayIn.push_back(Point(arrayCast[i].x, arrayCast[i].y));
		}

		SAFE_CALL(outMoment = cv::moments(arrayIn, binaryImage));
	} else if (array.get_type() == Variant::OBJECT) {
		Ref<CVMat> arrayIn = array;

		ERR_FAIL_NULL_V_MSG(arrayIn, output, "array should not be null.");

		SAFE_CALL(outMoment = cv::moments(arrayIn->get_pointer(), binaryImage));
	} else {
		UtilityFunctions::push_error("Type not supported, array should be Mat or PackedVector2Array.");
	}

	output->set_pointer(outMoment);

	return output;
}

float CVImgProc::point_polygon_test(Ref<CVMat> contour, Vector2 pt, bool measureDist){
	float output;
	double defReturn;

	ERR_FAIL_NULL_V_MSG(contour, output, "contour should not be null.");

	SAFE_CALL(output = cv::pointPolygonTest(contour->get_pointer(), Point2f(pt.x, pt.y), measureDist));

	return output;
}

void CVImgProc::accumulate(Ref<CVMat> src, Ref<CVMat> dst, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(src, , "src should not be null.");
	ERR_FAIL_NULL_V_MSG(dst, , "dst should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask, Mat());

	SAFE_CALL(cv::accumulate(src->get_pointer(), dst->get_pointer(), mask->get_pointer()));
}

void CVImgProc::accumulate_product(Ref<CVMat> src1, Ref<CVMat> src2, Ref<CVMat> dst, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(src1, , "src1 should not be null.");
	ERR_FAIL_NULL_V_MSG(src2, , "src2 should not be null.");
	ERR_FAIL_NULL_V_MSG(dst, , "dst should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask, Mat());

	SAFE_CALL(cv::accumulateProduct(src1->get_pointer(), src2->get_pointer(), dst->get_pointer(), mask->get_pointer()));
}

void CVImgProc::accumulate_square(Ref<CVMat> src, Ref<CVMat> dst, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(src, , "src should not be null.");
	ERR_FAIL_NULL_V_MSG(dst, , "dst should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask, Mat());

	SAFE_CALL(cv::accumulateSquare(src->get_pointer(), dst->get_pointer(), mask->get_pointer()));
}

void CVImgProc::accumulate_weighted(Ref<CVMat> src, Ref<CVMat> dst, float alpha, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(src, , "src should not be null.");
	ERR_FAIL_NULL_V_MSG(dst, , "dst should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask, Mat());

	SAFE_CALL(cv::accumulateWeighted(src->get_pointer(), dst->get_pointer(), alpha, mask->get_pointer()));
}

Ref<CVMat> CVImgProc::create_hanning_window(Vector2 winSize, int type){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	SAFE_CALL(cv::createHanningWindow(dst, Size(winSize.x, winSize.y), type));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::canny(Ref<CVMat> image, float threshold1, float threshold2, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat edges;

	ERR_FAIL_NULL_V_MSG(image, output, "image should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, apertureSize, 3);
	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, L2gradient, false);

	SAFE_CALL(cv::Canny(image->get_pointer(), edges, threshold1, threshold2, apertureSize, L2gradient));

	output->set_pointer(edges);

	return output;
}

Ref<CVMat> CVImgProc::corner_eigen_vals_and_vecs(Ref<CVMat> src, int blockSize, int ksize, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, borderType, BORDER_DEFAULT);

	SAFE_CALL(cv::cornerEigenValsAndVecs(src->get_pointer(), dst, blockSize, ksize, borderType));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::corner_harris(Ref<CVMat> src, int blockSize, int ksize, float k, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, borderType, BORDER_DEFAULT);

	SAFE_CALL(cv::cornerHarris(src->get_pointer(), dst, blockSize, ksize, k, borderType));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::corner_min_eigen_val(Ref<CVMat> src, int blockSize, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, ksize, 3);
	GET_SIMPLE_PROPERTY(int, Variant::INT, borderType, BORDER_DEFAULT);

	SAFE_CALL(cv::cornerMinEigenVal(src->get_pointer(), dst, blockSize, ksize, borderType));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::good_features_to_track(Ref<CVMat> image, int maxCorners, float qualityLevel, float minDistance, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat corners;

	ERR_FAIL_NULL_V_MSG(image, output, "image should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask, Mat());
	GET_SIMPLE_PROPERTY(int, Variant::INT, blockSize, 3);
	GET_SIMPLE_PROPERTY(bool, Variant::BOOL, useHarrisDetector, false);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, k, 0.04);

	SAFE_CALL(cv::goodFeaturesToTrack(image->get_pointer(), corners, maxCorners, qualityLevel, minDistance, mask->get_pointer(), blockSize, useHarrisDetector, k));

	output->set_pointer(corners);

	return output;
}

Ref<CVMat> CVImgProc::hough_circles(Ref<CVMat> image, int method, float dp, float minDist, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat circles;

	ERR_FAIL_NULL_V_MSG(image, output, "image should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, param1, 100);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, param2, 100);
	GET_SIMPLE_PROPERTY(int, Variant::INT, minRadius, 0);
	GET_SIMPLE_PROPERTY(int, Variant::INT, maxRadius, 0);

	SAFE_CALL(cv::HoughCircles(image->get_pointer(), circles, method, dp, minDist, param1, param2, minRadius, maxRadius));

	output->set_pointer(circles);

	return output;
}

Ref<CVMat> CVImgProc::hough_lines(Ref<CVMat> image, float rho, float theta, int threshold, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat lines;

	ERR_FAIL_NULL_V_MSG(image, output, "image should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, srn, 0);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, stn, 0);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, min_theta, 0);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, max_theta, CV_PI);

	SAFE_CALL(cv::HoughLines(image->get_pointer(), lines, rho, theta, threshold, srn, stn, min_theta, max_theta));

	output->set_pointer(lines);

	return output;
}

Ref<CVMat> CVImgProc::hough_lines_p(Ref<CVMat> image, float rho, float theta, int threshold, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat lines;

	ERR_FAIL_NULL_V_MSG(image, output, "image should not be null.");

	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, minLineLength, 0);
	GET_SIMPLE_PROPERTY(float, Variant::FLOAT, maxLineGap, 0);

	SAFE_CALL(cv::HoughLinesP(image->get_pointer(), lines, rho, theta, threshold, minLineLength, maxLineGap));

	output->set_pointer(lines);

	return output;
}

Ref<CVMat> CVImgProc::hough_lines_point_set(Ref<CVMat> point, int lines_max, int threshold, float min_rho, float max_rho, float rho_step, float min_theta, float max_theta, float theta_step){
	Ref<CVMat> output;
	output.instantiate();
	Mat lines;

	ERR_FAIL_NULL_V_MSG(point, output, "point should not be null.");

	SAFE_CALL(cv::HoughLinesPointSet(point->get_pointer(), lines, lines_max, threshold, min_rho, max_rho, rho_step, min_theta, max_theta, theta_step));

	output->set_pointer(lines);

	return output;
}

Ref<CVMat> CVImgProc::pre_corner_detect(Ref<CVMat> src, int ksize, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat dst;

	ERR_FAIL_NULL_V_MSG(src, output, "src should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, borderType, BORDER_DEFAULT);

	SAFE_CALL(cv::preCornerDetect(src->get_pointer(), dst, ksize, borderType));

	output->set_pointer(dst);

	return output;
}

Ref<CVMat> CVImgProc::match_template(Ref<CVMat> image, Ref<CVMat> templ, int method, Dictionary additional_parameters){
	Ref<CVMat> output;
	output.instantiate();
	Mat result;

	ERR_FAIL_NULL_V_MSG(image, output, "image should not be null.");
	ERR_FAIL_NULL_V_MSG(templ, output, "templ should not be null.");

	GET_OBJECT_PROPERTY(Ref<CVMat>, mask, Mat());

	SAFE_CALL(cv::matchTemplate(image->get_pointer(), templ->get_pointer(), result, method, mask->get_pointer()));

	output->set_pointer(result);

	return output;
}

void CVImgProc::grab_cut(Ref<CVMat> img, Ref<CVMat> mask, Ref<CVRect> rect, Ref<CVMat> bgdModel, Ref<CVMat> fgdModel, int iterCount, Dictionary additional_parameters){

	ERR_FAIL_NULL_V_MSG(img, , "img should not be null.");
	ERR_FAIL_NULL_V_MSG(mask, , "mask should not be null.");
	ERR_FAIL_NULL_V_MSG(rect, , "rect should not be null.");
	ERR_FAIL_NULL_V_MSG(bgdModel, , "bgdModel should not be null.");
	ERR_FAIL_NULL_V_MSG(fgdModel, , "fgdModel should not be null.");

	GET_SIMPLE_PROPERTY(int, Variant::INT, mode, GC_EVAL);

	SAFE_CALL(cv::grabCut(img->get_pointer(), mask->get_pointer(), rect->get_pointer(), bgdModel->get_pointer(), fgdModel->get_pointer(), iterCount, mode));
}

void CVImgProc::watershed(Ref<CVMat> image, Ref<CVMat> markers){

	ERR_FAIL_NULL_V_MSG(image, , "image should not be null.");
	ERR_FAIL_NULL_V_MSG(markers, , "markers should not be null.");

	SAFE_CALL(cv::watershed(image->get_pointer(), markers->get_pointer()));
}

godot::String CVImgProc::_to_string() const {
	return "[ CVImgProc Module ]";
}
