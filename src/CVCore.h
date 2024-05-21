#ifndef GDCORE_H
#define GDCORE_H

#include "CVMat.h"
#include "Macros.h"
#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

namespace godot {

class CVCore : public Object {
	GDCLASS(CVCore, Object)

private:
	static Ref<CVMat> arithmetic_wrapper(
			void (*func)(
					cv::InputArray,
					cv::InputArray,
					cv::OutputArray,
					cv::InputArray,
					int),
			Ref<CVMat> mat1,
			Ref<CVMat> mat2,
			Dictionary additional_parameters);

	static Ref<CVMat> mat_in_mat_in_mat_out_wrapper(
			void (*func)(
					cv::InputArray,
					cv::InputArray,
					cv::OutputArray),
			Ref<CVMat> mat1,
			Ref<CVMat> mat2);

	static Ref<CVMat> bitwise_wrapper(
			void (*func)(
					cv::InputArray,
					cv::InputArray,
					cv::OutputArray,
					cv::InputArray),
			Ref<CVMat> mat1,
			Ref<CVMat> mat2,
			Dictionary additional_parameters);

	static Ref<CVMat> mat_in_mat_out_wrapper(
			void (*func)(
					cv::InputArray,
					cv::OutputArray),
			Ref<CVMat> mat);

protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVCore();
	~CVCore();

	static Ref<CVMat> absdiff(Ref<CVMat> mat1, Ref<CVMat> mat2);
	static Ref<CVMat> add(Ref<CVMat> mat1, Ref<CVMat> mat2, Dictionary additional_parameters);
	static Ref<CVMat> add_weighted(Ref<CVMat> src1, double alpha, Ref<CVMat> src2, double beta, double gamma, Dictionary additional_parameters);
	static Ref<CVMat> bitwise_and(Ref<CVMat> mat1, Ref<CVMat> mat2, Dictionary additional_parameters);
	static Ref<CVMat> bitwise_not(Ref<CVMat> mat, Dictionary additional_parameters);
	static Ref<CVMat> bitwise_or(Ref<CVMat> mat1, Ref<CVMat> mat2, Dictionary additional_parameters);
	static Ref<CVMat> bitwise_xor(Ref<CVMat> mat1, Ref<CVMat> mat2, Dictionary additional_parameters);
	static Ref<CVMat> convert_fp16(Ref<CVMat> mat);
	static Ref<CVMat> dft(Ref<CVMat> src, Dictionary additional_parameters);
	static Ref<CVMat> exp(Ref<CVMat> mat);
	static int get_optimal_dft_size(int vecsize);
	static Ref<CVMat> hconcat(Ref<CVMat> mat1, Ref<CVMat> mat2);
	static Ref<CVMat> log(Ref<CVMat> mat);
	static Ref<CVMat> max(Ref<CVMat> mat1, Ref<CVMat> mat2);
	static Ref<CVMat> min(Ref<CVMat> mat1, Ref<CVMat> mat2);
	static Ref<CVMat> normalize(Ref<CVMat> src, Dictionary additional_parameters);
	static Ref<CVMat> subtract(Ref<CVMat> mat1, Ref<CVMat> mat2, Dictionary additional_parameters);
	static Ref<CVMat> sqrt(Ref<CVMat> mat);
	static Ref<CVMat> transpose(Ref<CVMat> mat);
	static Ref<CVMat> vconcat(Ref<CVMat> mat1, Ref<CVMat> mat2);
};

} //namespace godot

#endif