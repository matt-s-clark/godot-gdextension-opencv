#include "CVScalar.h"

using namespace godot;

void CVScalar::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("get_vector4"),
			&CVScalar::get_vector4);
	ClassDB::bind_method(
			D_METHOD("get_vector4i"),
			&CVScalar::get_vector4i);
	ClassDB::bind_method(
			D_METHOD("get_vector3"),
			&CVScalar::get_vector3);
	ClassDB::bind_method(
			D_METHOD("get_vector3i"),
			&CVScalar::get_vector3i);
	ClassDB::bind_method(
			D_METHOD("get_vector2"),
			&CVScalar::get_vector2);
	ClassDB::bind_method(
			D_METHOD("get_vector2i"),
			&CVScalar::get_vector2i);
	ClassDB::bind_method(
			D_METHOD("get_float"),
			&CVScalar::get_float);
	ClassDB::bind_method(
			D_METHOD("get_int"),
			&CVScalar::get_int);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("create", "value"),
			&CVScalar::create);
}

CVScalar::CVScalar() {
}

CVScalar::~CVScalar() {
}

Vector4 CVScalar::get_vector4() {
	return Vector4(rawScalar[0], rawScalar[1], rawScalar[2], rawScalar[3]);
}

Vector4i CVScalar::get_vector4i() {
	return Vector4i(rawScalar[0], rawScalar[1], rawScalar[2], rawScalar[3]);
}

Vector3 CVScalar::get_vector3() {
	return Vector3(rawScalar[0], rawScalar[1], rawScalar[2]);
}

Vector3i CVScalar::get_vector3i() {
	return Vector3i(rawScalar[0], rawScalar[1], rawScalar[2]);
}

Vector2 CVScalar::get_vector2() {
	return Vector2(rawScalar[0], rawScalar[1]);
}

Vector2i CVScalar::get_vector2i() {
	return Vector2i(rawScalar[0], rawScalar[1]);
}

float CVScalar::get_float() {
	return rawScalar[0];
}

int CVScalar::get_int() {
	return rawScalar[0];
}

void CVScalar::set(Variant value) {
	switch (value.get_type()) {
		case Variant::VECTOR4: {
			Vector4 tmp = value;
			rawScalar = cv::Scalar(tmp.x, tmp.y, tmp.z, tmp.w);
			break;
		}
		case Variant::VECTOR4I: {
			Vector4i tmp = value;
			rawScalar = cv::Scalar(tmp.x, tmp.y, tmp.z, tmp.w);
			break;
		}
		case Variant::VECTOR3: {
			Vector3 tmp = value;
			rawScalar = cv::Scalar(tmp.x, tmp.y, tmp.z);
			break;
		}
		case Variant::VECTOR3I: {
			Vector3i tmp = value;
			rawScalar = cv::Scalar(tmp.x, tmp.y, tmp.z);
			break;
		}
		case Variant::VECTOR2: {
			Vector2 tmp = value;
			rawScalar = cv::Scalar(tmp.x, tmp.y);
			break;
		}
		case Variant::VECTOR2I: {
			Vector2i tmp = value;
			rawScalar = cv::Scalar(tmp.x, tmp.y);
			break;
		}
		case Variant::FLOAT: {
			rawScalar = cv::Scalar((float)value);
			break;
		}
		case Variant::INT: {
			rawScalar = cv::Scalar((int)value);
			break;
		}
		case Variant::COLOR: {
			Color tmp = value;
			rawScalar = 255 * cv::Scalar(tmp.b, tmp.g, tmp.r, tmp.a);
			break;
		}
		default:
			UtilityFunctions::push_error("Type ", value.get_type_name, " can't be converted to CVScalar");
			break;
	}
}

cv::Scalar CVScalar::get_pointer() {
	return rawScalar;
}

void CVScalar::set_pointer(cv::Scalar _scalar) {
	rawScalar = _scalar;
}

Ref<CVScalar> CVScalar::create(Variant value) {
	Ref<CVScalar> output;
	output.instantiate();

	output->set(value);

	return output;
}

String CVScalar::_to_string() const {
	return UtilityFunctions::str("[ CVScalar instance (", ") ]");
}
