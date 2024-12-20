#include "CVRect.h"

using namespace godot;

void CVRect::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("area"),
			&CVRect::area);
	ClassDB::bind_method(
			D_METHOD("empty"),
			&CVRect::empty);

	ClassDB::bind_method(
			D_METHOD("get_height"),
			&CVRect::get_height);
	ClassDB::bind_method(
			D_METHOD("get_width"),
			&CVRect::get_width);
	ClassDB::bind_method(
			D_METHOD("get_x"),
			&CVRect::get_x);
	ClassDB::bind_method(
			D_METHOD("get_y"),
			&CVRect::get_y);

	ClassDB::bind_method(
			D_METHOD("set_height", "value"),
			&CVRect::set_height);
	ClassDB::bind_method(
			D_METHOD("set_width", "value"),
			&CVRect::set_width);
	ClassDB::bind_method(
			D_METHOD("set_x", "value"),
			&CVRect::set_x);
	ClassDB::bind_method(
			D_METHOD("set_y", "value"),
			&CVRect::set_y);

	ADD_PROPERTY(PropertyInfo(Variant::INT, "x"), "set_x", "get_x");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "y"), "set_y", "get_y");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "width"), "set_width", "get_width");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "height"), "set_height", "get_height");

	ClassDB::bind_method(
			D_METHOD("contains", "point"),
			&CVRect::contains);
	ClassDB::bind_method(
			D_METHOD("br"),
			&CVRect::br);
	ClassDB::bind_method(
			D_METHOD("tl"),
			&CVRect::tl);

	ClassDB::bind_method(
			D_METHOD("set_values", "x", "y", "width", "height"),
			&CVRect::set_values);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("from_values", "x", "y", "width", "height"),
			&CVRect::from_values);
}

CVRect::CVRect() {
}

CVRect::~CVRect() {
}

Variant CVRect::area() const {
	Variant output;

	SAFE_CALL(output = rawRect.area());

	return output;
}

bool CVRect::empty() {
	bool output;

	SAFE_CALL(output = rawRect.empty());

	return output;
}

bool CVRect::contains(Vector2 point) {
	bool output;

	SAFE_CALL(output = rawRect.contains(cv::Point2i(point.x, point.y)));

	return output;
}

Vector2 CVRect::br() {
	cv::Point br = rawRect.br();

	return Vector2(br.x, br.y);
}

Vector2 CVRect::tl() {
	cv::Point tl = rawRect.tl();

	return Vector2(tl.x, tl.y);
}

void CVRect::set_values(Variant x, Variant y, Variant width, Variant height) {
	set_x(x);
	set_y(y);
	set_width(width);
	set_height(height);
}

Variant CVRect::get_height() {
	return rawRect.height;
}

cv::Rect CVRect::get_pointer() {
	return rawRect;
}

Variant CVRect::get_width() {
	return rawRect.width;
}

Variant CVRect::get_x() {
	return rawRect.x;
}

Variant CVRect::get_y() {
	return rawRect.y;
}

void CVRect::set_height(Variant value) {
	rawRect.height = value;
}

void CVRect::set_pointer(cv::Rect rect) {
	rawRect = rect;
}

void CVRect::set_width(Variant value) {
	rawRect.width = value;
}

void CVRect::set_x(Variant value) {
	rawRect.x = value;
}

void CVRect::set_y(Variant value) {
	rawRect.y = value;
}

Ref<CVRect> CVRect::from_values(Variant x, Variant y, Variant width, Variant height) {
	Ref<CVRect> output;
	output.instantiate();

	output->set_values(x, y, width, height);

	return output;
}

String CVRect::_to_string() const {
	return UtilityFunctions::str("[ CVRect (",
			String((Variant)rawRect.x), ", ",
			String((Variant)rawRect.y), ", ",
			String((Variant)rawRect.width), ", ",
			String((Variant)rawRect.height),
			") ]");
}