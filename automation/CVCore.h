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
	Dictionary batchDistance(Ref<CVMat> src1, Ref<CVMat> src2, int dtype, Dictionary additional_parameters);
	Ref<CVMat> bitwise_and(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	Ref<CVMat> bitwise_not(Ref<CVMat> src, Dictionary additional_parameters);
	Ref<CVMat> bitwise_or(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	Ref<CVMat> bitwise_xor(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	int borderInterpolate(int p, int len, int borderType);
	Ref<CVMat> calcCovarMatrix(Ref<CVMat> samples, Ref<CVMat> mean, int flags, Dictionary additional_parameters);
	Dictionary cartToPolar(Ref<CVMat> x, Ref<CVMat> y, Dictionary additional_parameters);
	Ref<CVMat> compare(Ref<CVMat> src1, Ref<CVMat> src2, int cmpop);
	void completeSymm(Ref<CVMat> m, Dictionary additional_parameters);
	Ref<CVMat> convertFp16(Ref<CVMat> src);
	Ref<CVMat> convertScaleAbs(Ref<CVMat> src, Dictionary additional_parameters);
	Ref<CVMat> copyTo(Ref<CVMat> src, Ref<CVMat> mask);
	int countNonZero(Ref<CVMat> src);
	Ref<CVMat> dct(Ref<CVMat> src, Dictionary additional_parameters);
	float determinant(Ref<CVMat> mtx);
	Ref<CVMat> dft(Ref<CVMat> src, Dictionary additional_parameters);
	Ref<CVMat> divide(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	Dictionary eigen(Ref<CVMat> src);
	Dictionary eigenNonSymmetric(Ref<CVMat> src);
	Ref<CVMat> exp(Ref<CVMat> src);
	Ref<CVMat> extractChannel(Ref<CVMat> src, int coi);
	Ref<CVMat> findNonZero(Ref<CVMat> src);
	Ref<CVMat> flip(Ref<CVMat> src, int flipCode);
	Ref<CVMat> gemm(Ref<CVMat> src1, Ref<CVMat> src2, float alpha, Ref<CVMat> src3, float beta, Dictionary additional_parameters);
	int getOptimalDFTSize(int vecsize);
	Ref<CVMat> hconcat(Ref<CVMat> src1, Ref<CVMat> src2);
	Ref<CVMat> idct(Ref<CVMat> src, Dictionary additional_parameters);
	Ref<CVMat> idft(Ref<CVMat> src, Dictionary additional_parameters);
	Ref<CVMat> inRange(Ref<CVMat> src, Ref<CVMat> lowerb, Ref<CVMat> upperb);
	void insertChannel(Ref<CVMat> src, Ref<CVMat> dst, int coi);
	Dictionary invert(Ref<CVMat> src, Dictionary additional_parameters);
	Ref<CVMat> log(Ref<CVMat> src);
	Ref<CVMat> LUT(Ref<CVMat> src, Ref<CVMat> lut);
	Ref<CVMat> magnitude(Ref<CVMat> x, Ref<CVMat> y);
	float Mahalanobis(Ref<CVMat> v1, Ref<CVMat> v2, Ref<CVMat> icovar);
	Ref<CVMat> max(Ref<CVMat> src1, Ref<CVMat> src2);
	Color mean(Ref<CVMat> src, Dictionary additional_parameters);
	Dictionary meanStdDev(Ref<CVMat> src, Dictionary additional_parameters);
	Ref<CVMat> min(Ref<CVMat> src1, Ref<CVMat> src2);
	Ref<CVMat> mulSpectrums(Ref<CVMat> a, Ref<CVMat> b, int flags, Dictionary additional_parameters);
	Ref<CVMat> multiply(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	Ref<CVMat> mulTransposed(Ref<CVMat> src, bool aTa, Dictionary additional_parameters);
	float norm(Ref<CVMat> src1, Dictionary additional_parameters);
	void normalize(Ref<CVMat> src, Ref<CVMat> dst, Dictionary additional_parameters);
	void patchNaNs(Ref<CVMat> a, Dictionary additional_parameters);
	Ref<CVMat> PCABackProject(Ref<CVMat> data, Ref<CVMat> mean, Ref<CVMat> eigenvectors);
	Ref<CVMat> PCACompute(Ref<CVMat> data, Ref<CVMat> mean, float retainedVariance);
	Ref<CVMat> PCAProject(Ref<CVMat> data, Ref<CVMat> mean, Ref<CVMat> eigenvectors);
	Ref<CVMat> perspectiveTransform(Ref<CVMat> src, Ref<CVMat> m);
	Ref<CVMat> phase(Ref<CVMat> x, Ref<CVMat> y, Dictionary additional_parameters);
	Dictionary polarToCart(Ref<CVMat> magnitude, Ref<CVMat> angle, Dictionary additional_parameters);
	Ref<CVMat> pow(Ref<CVMat> src, float power);
	float PSNR(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	void randn(Ref<CVMat> dst, Ref<CVMat> mean, Ref<CVMat> stddev);
	void randu(Ref<CVMat> dst, Ref<CVMat> low, Ref<CVMat> high);
	Ref<CVMat> reduce(Ref<CVMat> src, int dim, int rtype, Dictionary additional_parameters);
	Ref<CVMat> repeat(Ref<CVMat> src, int ny, int nx);
	Ref<CVMat> rotate(Ref<CVMat> src, int rotateCode);
	Ref<CVMat> scaleAdd(Ref<CVMat> src1, float alpha, Ref<CVMat> src2);
	void setIdentity(Ref<CVMat> mtx, Dictionary additional_parameters);
	void setRNGSeed(int seed);
	Dictionary solve(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	Dictionary solveCubic(Ref<CVMat> coeffs);
	Dictionary solvePoly(Ref<CVMat> coeffs, Dictionary additional_parameters);
	Ref<CVMat> sort(Ref<CVMat> src, int flags);
	Ref<CVMat> sortIdx(Ref<CVMat> src, int flags);
	Ref<CVMat> sqrt(Ref<CVMat> src);
	Ref<CVMat> subtract(Ref<CVMat> src1, Ref<CVMat> src2, Dictionary additional_parameters);
	Color sum(Ref<CVMat> src);
	Ref<CVMat> SVBackSubst(Ref<CVMat> w, Ref<CVMat> u, Ref<CVMat> vt, Ref<CVMat> rhs);
	Dictionary SVDecomp(Ref<CVMat> src, Dictionary additional_parameters);
	Color trace(Ref<CVMat> mtx);
	Ref<CVMat> transform(Ref<CVMat> src, Ref<CVMat> m);
	Ref<CVMat> transpose(Ref<CVMat> src);
	Ref<CVMat> vconcat(Ref<CVMat> src1, Ref<CVMat> src2);
};

} //namespace godot

#endif