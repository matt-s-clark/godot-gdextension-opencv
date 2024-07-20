#ifndef CVCore_H
#define CVCore_H

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

protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVCore();
	~CVCore();

	Ref<CVMat> absdiff(Ref<CVMat> src1, Ref<CVMat> src2);
	Ref<CVMat> add(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	Ref<CVMat> addWeighted(Ref<CVMat> src1, float alpha, Ref<CVMat> src2, float beta, float gamma, Dictionary additional_parameters);
	Ref<CVMat> bitwise_and(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	Ref<CVMat> bitwise_not(Ref<CVMat> src, Dictionary additional_parameters);
	Ref<CVMat> bitwise_or(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	Ref<CVMat> bitwise_xor(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	Ref<CVMat> compare(Ref<CVMat> src1, Ref<CVMat> src2, int cmpop);
	Ref<CVMat> convertFp16(Ref<CVMat> src);
	Ref<CVMat> dct(Ref<CVMat> src, Dictionary additional_parameters);
	float determinant(Ref<CVMat> mtx);
	Ref<CVMat> dft(Ref<CVMat> src, Dictionary additional_parameters);
	Ref<CVMat> exp(Ref<CVMat> src);
	Ref<CVMat> findNonZero(Ref<CVMat> src);
	Ref<CVMat> flip(Ref<CVMat> src, int flipCode);
	int getOptimalDFTSize(int vecsize);
	Ref<CVMat> hconcat(Ref<CVMat> src1, Ref<CVMat> src2);
	Ref<CVMat> idct(Ref<CVMat> src, Dictionary additional_parameters);
	Ref<CVMat> idft(Ref<CVMat> src, Dictionary additional_parameters);
	Dictionary invert(Ref<CVMat> src, Dictionary additional_parameters);
	Ref<CVMat> log(Ref<CVMat> src);
	Ref<CVMat> max(Ref<CVMat> src1, Ref<CVMat> src2);
	Color mean(Ref<CVMat> src, Dictionary additional_parameters);
	Dictionary meanStdDev(Ref<CVMat> src, Dictionary additional_parameters);
	Ref<CVMat> merge(Array mv);
	Ref<CVMat> min(Ref<CVMat> src1, Ref<CVMat> src2);
	void normalize(Ref<CVMat> src, Ref<CVMat> dst, Dictionary additional_parameters);
	Ref<CVMat> pow(Ref<CVMat> src, float power);
	Ref<CVMat> reduce(Ref<CVMat> src, int dim, int rtype, Dictionary additional_parameters);
	Ref<CVMat> repeat(Ref<CVMat> src, int ny, int nx);
	Ref<CVMat> repeat(Ref<CVMat> src, int ny, int nx);
	Ref<CVMat> rotate(Ref<CVMat> src, int rotateCode);
	void setIdentity(Ref<CVMat> mtx, Dictionary additional_parameters);
	Array split(Ref<CVMat> m);
	Ref<CVMat> sqrt(Ref<CVMat> src);
	Ref<CVMat> subtract(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	Ref<CVMat> transpose(Ref<CVMat> src);
	Ref<CVMat> vconcat(Ref<CVMat> src1, Ref<CVMat> src2);
	int countNonZero(Ref<CVMat> src);
	Ref<CVMat> flip(Ref<CVMat> src, int flipCode);
	Dictionary invert(Ref<CVMat> src, Dictionary additional_parameters);
	Ref<CVMat> LUT(Ref<CVMat> src, Ref<CVMat> lut);
	Color mean(Ref<CVMat> src, Dictionary additional_parameters);
	Ref<CVMat> merge(Array mv);
	Color sum(Ref<CVMat> src);
	Color trace(Ref<CVMat> mtx);
	Ref<CVMat> transform(Ref<CVMat> src, Ref<CVMat> m);
};

} //namespace godot

#endif