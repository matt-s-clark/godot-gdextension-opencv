#ifndef CV_IMGPROC_H
#define CV_IMGPROC_H

#include "CVMat.h"
#include "CVRect.h"
#include "Macros.h"
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

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

	static Ref<CVMat> adaptive_threshold(Ref<CVMat> src, float maxValue, int adaptiveMethod, int thresholdType, int blockSize, float C);
	static Ref<CVMat> bilateral_filter(Ref<CVMat> src, int d, double sigmaColor, double sigmaSpace, Dictionary additional_parameters);
	static Ref<CVMat> blur(Ref<CVMat> src, Vector2 ksize, Dictionary additional_parameters);
	static Ref<CVMat> cvt_color(Ref<CVMat> src, int code, Dictionary additional_parameters);
	static Ref<CVMat> dilate(Ref<CVMat> src, Ref<CVMat> kernel, Dictionary additional_parameters);
	static Ref<CVMat> equalize_hist(Ref<CVMat> src);
	static Ref<CVMat> erode(Ref<CVMat> src, Ref<CVMat> kernel, Dictionary additional_parameters);
	static Ref<CVMat> filter2D(Ref<CVMat> src, int ddepth, Ref<CVMat> kernel, Dictionary additional_parameters);
	static Ref<CVMat> gaussian_blur(Ref<CVMat> src, Vector2 ksize, float sigmaX, Dictionary additional_parameters);
	static Ref<CVMat> get_gaussian_kernel(int ksize, float sigma, Dictionary additional_parameters);
	static Ref<CVMat> get_gabor_kernel(Vector2 ksize, float sigma, float theta, float lambd, float gamma, Dictionary additional_parameters);
	static Ref<CVMat> get_structuring_element(int shape, Vector2 ksize, Dictionary additional_parameters);
	static Ref<CVMat> laplacian(Ref<CVMat> src, int ddepth, Dictionary additional_parameters);
	static Ref<CVMat> median_blur(Ref<CVMat> src, int ksize);
	static Ref<CVMat> morphology_ex(Ref<CVMat> src, int op, Ref<CVMat> kernel, Dictionary additional_parameters);
	static void rectangle(Ref<CVMat> img, Dictionary additional_parameters);
	static Ref<CVMat> sobel(Ref<CVMat> src, int ddepth, int dx, int dy, Dictionary additional_parameters);
	static Ref<CVMat> threshold(Ref<CVMat> src, float thresh, float maxval, int type);
};

} //namespace godot

#endif