#ifndef CVSCALAR_H
#define CVSCALAR_H

#include "Macros.h"
#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>

namespace godot {

class CVScalar : public RefCounted {
	GDCLASS(CVScalar, RefCounted)

private:
	cv::Scalar rawScalar;

protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVScalar();
	~CVScalar();

	Vector4 get_vector4();
	Vector4i get_vector4i();
	Vector3 get_vector3();
	Vector3i get_vector3i();
	Vector2 get_vector2();
	Vector2i get_vector2i();
	float get_float();
	int get_int();
	void set(Variant value);

	cv::Scalar get_pointer();
	void set_pointer(cv::Scalar _scalar);

	static Ref<CVScalar> create(Variant value);
};

} //namespace godot

#endif