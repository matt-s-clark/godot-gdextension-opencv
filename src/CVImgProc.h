#ifndef CVIMGPROC_H
#define CVIMGPROC_H

#include "CVMat.h"
#include "Macros.h"
#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include "CVRect.h"
#include "CVScalar.h"
#include "HelperFunctions.h"

namespace godot {

class CVImgProc : public Object {
	GDCLASS(CVImgProc, Object)

private:

protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVImgProc();
	~CVImgProc();

	static Ref<CVMat> bilateral_filter(Ref<CVMat> src, int d, float sigmaColor, float sigmaSpace, Dictionary additional_parameters);
	static Ref<CVMat> blur(Ref<CVMat> src, Vector2 ksize, Dictionary additional_parameters);
	static Ref<CVMat> box_filter(Ref<CVMat> src, int ddepth, Vector2 ksize, Dictionary additional_parameters);
	static Ref<CVMat> dilate(Ref<CVMat> src, Ref<CVMat> kernel, Dictionary additional_parameters);
	static Ref<CVMat> erode(Ref<CVMat> src, Ref<CVMat> kernel, Dictionary additional_parameters);
	static Ref<CVMat> filter_2d(Ref<CVMat> src, int ddepth, Ref<CVMat> kernel, Dictionary additional_parameters);
	static Ref<CVMat> gaussian_blur(Ref<CVMat> src, Vector2 ksize, float sigmaX, Dictionary additional_parameters);
	static Dictionary get_deriv_kernels(int dx, int dy, int ksize, Dictionary additional_parameters);
	static Ref<CVMat> get_gabor_kernel(Vector2 ksize, float sigma, float theta, float lambd, float gamma, Dictionary additional_parameters);
	static Ref<CVMat> get_gaussian_kernel(int ksize, float sigma, Dictionary additional_parameters);
	static Ref<CVMat> get_structuring_element(int shape, Vector2 ksize, Dictionary additional_parameters);
	static Ref<CVMat> laplacian(Ref<CVMat> src, int ddepth, Dictionary additional_parameters);
	static Ref<CVMat> median_blur(Ref<CVMat> src, int ksize);
	static Ref<CVScalar> morphology_default_border_value();
	static Ref<CVMat> morphology_ex(Ref<CVMat> src, int op, Ref<CVMat> kernel, Dictionary additional_parameters);
	static Ref<CVMat> pyr_down(Ref<CVMat> src, Dictionary additional_parameters);
	static Ref<CVMat> pyr_up(Ref<CVMat> src, Dictionary additional_parameters);
	static Ref<CVMat> scharr(Ref<CVMat> src, int ddepth, int dx, int dy, Dictionary additional_parameters);
	static Ref<CVMat> sep_filter_2d(Ref<CVMat> src, int ddepth, Ref<CVMat> kernelX, Ref<CVMat> kernelY, Dictionary additional_parameters);
	static Ref<CVMat> sobel(Ref<CVMat> src, int ddepth, int dx, int dy, Dictionary additional_parameters);
	static Dictionary spatial_gradient(Ref<CVMat> src, Dictionary additional_parameters);
	static Dictionary convert_maps(Ref<CVMat> map1, Ref<CVMat> map2, int dstmap1type, Dictionary additional_parameters);
	static Ref<CVMat> get_affine_transform(Ref<CVMat> src, Ref<CVMat> dst);
	static Ref<CVMat> get_perspective_transform(Ref<CVMat> src, Ref<CVMat> dst, Dictionary additional_parameters);
	static Ref<CVMat> get_rect_sub_pix(Ref<CVMat> image, Vector2 patchSize, Vector2 center, Dictionary additional_parameters);
	static Ref<CVMat> get_rotation_matrix_2d(Vector2 center, float angle, float scale);
	static Ref<CVMat> invert_affine_transform(Ref<CVMat> M);
	static Ref<CVMat> linear_polar(Ref<CVMat> src, Vector2 center, float maxRadius, int flags);
	static Ref<CVMat> log_polar(Ref<CVMat> src, Vector2 center, float M, int flags);
	static Ref<CVMat> remap(Ref<CVMat> src, Ref<CVMat> map1, Ref<CVMat> map2, int interpolation, Dictionary additional_parameters);
	static Ref<CVMat> resize(Ref<CVMat> src, Vector2 dsize, Dictionary additional_parameters);
	static Ref<CVMat> warp_affine(Ref<CVMat> src, Ref<CVMat> M, Vector2 dsize, Dictionary additional_parameters);
	static Ref<CVMat> warp_perspective(Ref<CVMat> src, Ref<CVMat> M, Vector2 dsize, Dictionary additional_parameters);
	static Ref<CVMat> warp_polar(Ref<CVMat> src, Vector2 dsize, Vector2 center, float maxRadius, int flags);
	static Ref<CVMat> adaptive_threshold(Ref<CVMat> src, float maxValue, int adaptiveMethod, int thresholdType, int blockSize, float C);
	static Ref<CVMat> blend_linear(Ref<CVMat> src1, Ref<CVMat> src2, Ref<CVMat> weights1, Ref<CVMat> weights2);
	static Dictionary distance_transform(Ref<CVMat> src, int distanceType, int maskSize, Dictionary additional_parameters);
	static Dictionary integral(Ref<CVMat> src, Dictionary additional_parameters);
	static Dictionary threshold(Ref<CVMat> src, float thresh, float maxval, int type);
	static void arrowed_line(Ref<CVMat> img, Vector2 pt1, Vector2 pt2, Ref<CVScalar> color, Dictionary additional_parameters);
	static void circle(Ref<CVMat> img, Vector2 center, int radius, Ref<CVScalar> color, Dictionary additional_parameters);
	static void draw_contours(Ref<CVMat> image, Array contours, int contourIdx, Ref<CVScalar> color, Dictionary additional_parameters);
	static void draw_marker(Ref<CVMat> img, Vector2 position, Ref<CVScalar> color, Dictionary additional_parameters);
	static void ellipse(Ref<CVMat> img, Vector2 center, Vector2 axes, float angle, float startAngle, float endAngle, Ref<CVScalar> color, Dictionary additional_parameters);
	static void fill_convex_poly(Ref<CVMat> img, Ref<CVMat> points, Ref<CVScalar> color, Dictionary additional_parameters);
	static float get_font_scale_from_height(int fontFace, int pixelHeight, Dictionary additional_parameters);
	static void line(Ref<CVMat> img, Vector2 pt1, Vector2 pt2, Ref<CVScalar> color, Dictionary additional_parameters);
	static void rectangle(Ref<CVMat> img, Dictionary additional_parameters);
	static Ref<CVMat> cvt_color(Ref<CVMat> src, int code, Dictionary additional_parameters);
	static Ref<CVMat> demosaicing(Ref<CVMat> src, int code, Dictionary additional_parameters);
	static Ref<CVMat> apply_color_map(Ref<CVMat> src, Ref<CVMat> userColor);
	static float compare_hist(Ref<CVMat> H1, Ref<CVMat> H2, int method);
	static Ref<CVMat> equalize_hist(Ref<CVMat> src);
	static float arc_length(Ref<CVMat> curve, bool closed);
	static Ref<CVRect> bounding_rect(Ref<CVMat> array);
	static Dictionary connected_components(Ref<CVMat> image, int connectivity, int ltype, int ccltype);
	static Dictionary connected_components_with_stats(Ref<CVMat> image, int connectivity, int ltype, int ccltype);
	static float contour_area(Ref<CVMat> contour, Dictionary additional_parameters);
	static Ref<CVMat> convex_hull(Ref<CVMat> points, Dictionary additional_parameters);
	static Ref<CVMat> convexity_defects(Ref<CVMat> contour, Ref<CVMat> convexhull);
	static Dictionary find_contours(Ref<CVMat> image, int mode, int method, Dictionary additional_parameters);
	static Ref<CVMat> fit_line(Ref<CVMat> points, int distType, float param, float reps, float aeps);
	static Dictionary intersect_convex_convex(Ref<CVMat> p1, Ref<CVMat> p2, Dictionary additional_parameters);
	static bool is_contour_convex(Ref<CVMat> contour);
	static float match_shapes(Ref<CVMat> contour1, Ref<CVMat> contour2, int method, float parameter);
	static Dictionary min_enclosing_triangle(Ref<CVMat> points);
	static float point_polygon_test(Ref<CVMat> contour, Vector2 pt, bool measureDist);
	static void accumulate(Ref<CVMat> src, Ref<CVMat> dst, Dictionary additional_parameters);
	static void accumulate_product(Ref<CVMat> src1, Ref<CVMat> src2, Ref<CVMat> dst, Dictionary additional_parameters);
	static void accumulate_square(Ref<CVMat> src, Ref<CVMat> dst, Dictionary additional_parameters);
	static void accumulate_weighted(Ref<CVMat> src, Ref<CVMat> dst, float alpha, Dictionary additional_parameters);
	static Ref<CVMat> create_hanning_window(Vector2 winSize, int type);
	static Ref<CVMat> canny(Ref<CVMat> image, float threshold1, float threshold2, Dictionary additional_parameters);
	static Ref<CVMat> corner_eigen_vals_and_vecs(Ref<CVMat> src, int blockSize, int ksize, Dictionary additional_parameters);
	static Ref<CVMat> corner_harris(Ref<CVMat> src, int blockSize, int ksize, float k, Dictionary additional_parameters);
	static Ref<CVMat> corner_min_eigen_val(Ref<CVMat> src, int blockSize, Dictionary additional_parameters);
	static Ref<CVMat> good_features_to_track(Ref<CVMat> image, int maxCorners, float qualityLevel, float minDistance, Dictionary additional_parameters);
	static Ref<CVMat> hough_circles(Ref<CVMat> image, int method, float dp, float minDist, Dictionary additional_parameters);
	static Ref<CVMat> hough_lines(Ref<CVMat> image, float rho, float theta, int threshold, Dictionary additional_parameters);
	static Ref<CVMat> hough_lines_p(Ref<CVMat> image, float rho, float theta, int threshold, Dictionary additional_parameters);
	static Ref<CVMat> hough_lines_point_set(Ref<CVMat> point, int lines_max, int threshold, float min_rho, float max_rho, float rho_step, float min_theta, float max_theta, float theta_step);
	static Ref<CVMat> pre_corner_detect(Ref<CVMat> src, int ksize, Dictionary additional_parameters);
	static Ref<CVMat> match_template(Ref<CVMat> image, Ref<CVMat> templ, int method, Dictionary additional_parameters);
	static void grab_cut(Ref<CVMat> img, Ref<CVMat> mask, Ref<CVRect> rect, Ref<CVMat> bgdModel, Ref<CVMat> fgdModel, int iterCount, Dictionary additional_parameters);
	static void watershed(Ref<CVMat> image, Ref<CVMat> markers);
};

} //namespace godot

#endif