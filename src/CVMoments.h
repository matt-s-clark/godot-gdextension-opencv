#ifndef CVMOMENTS_H
#define CVMOMENTS_H

#include "Macros.h"
#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>

namespace godot {

class CVMoments : public RefCounted {
	GDCLASS(CVMoments, RefCounted)

private:
	cv::Moments rawPointer;

protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVMoments();
	~CVMoments();

	float get_m00();
	float get_m10();
	float get_m01();
	float get_m20();
	float get_m11();
	float get_m02();
	float get_m30();
	float get_m21();
	float get_m12();
	float get_m03();
	float get_mu20();
	float get_mu11();
	float get_mu02();
	float get_mu30();
	float get_mu21();
	float get_mu12();
	float get_mu03();
	float get_nu20();
	float get_nu11();
	float get_nu02();
	float get_nu30();
	float get_nu21();
	float get_nu12();
	float get_nu03();

	void set_m00(float value);
	void set_m10(float value);
	void set_m01(float value);
	void set_m20(float value);
	void set_m11(float value);
	void set_m02(float value);
	void set_m30(float value);
	void set_m21(float value);
	void set_m12(float value);
	void set_m03(float value);
	void set_mu20(float value);
	void set_mu11(float value);
	void set_mu02(float value);
	void set_mu30(float value);
	void set_mu21(float value);
	void set_mu12(float value);
	void set_mu03(float value);
	void set_nu20(float value);
	void set_nu11(float value);
	void set_nu02(float value);
	void set_nu30(float value);
	void set_nu21(float value);
	void set_nu12(float value);
	void set_nu03(float value);

	cv::Moments get_pointer();
	void set_pointer(cv::Moments _pointer);

	static Ref<CVMoments> create(float m00, float m10, float m01, float m20, float m11, float m02, float m30, float m21, float m12, float m03);
};

} //namespace godot

#endif