#include "CVMoments.h"

using namespace godot;

void CVMoments::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("get_m00"),
			&CVMoments::get_m00);
	ClassDB::bind_method(
			D_METHOD("get_m10"),
			&CVMoments::get_m10);
	ClassDB::bind_method(
			D_METHOD("get_m01"),
			&CVMoments::get_m01);
	ClassDB::bind_method(
			D_METHOD("get_m20"),
			&CVMoments::get_m20);
	ClassDB::bind_method(
			D_METHOD("get_m11"),
			&CVMoments::get_m11);
	ClassDB::bind_method(
			D_METHOD("get_m02"),
			&CVMoments::get_m02);
	ClassDB::bind_method(
			D_METHOD("get_m30"),
			&CVMoments::get_m30);
	ClassDB::bind_method(
			D_METHOD("get_m21"),
			&CVMoments::get_m21);
	ClassDB::bind_method(
			D_METHOD("get_m12"),
			&CVMoments::get_m12);
	ClassDB::bind_method(
			D_METHOD("get_m03"),
			&CVMoments::get_m03);
	ClassDB::bind_method(
			D_METHOD("get_mu20"),
			&CVMoments::get_mu20);
	ClassDB::bind_method(
			D_METHOD("get_mu11"),
			&CVMoments::get_mu11);
	ClassDB::bind_method(
			D_METHOD("get_mu02"),
			&CVMoments::get_mu02);
	ClassDB::bind_method(
			D_METHOD("get_mu30"),
			&CVMoments::get_mu30);
	ClassDB::bind_method(
			D_METHOD("get_mu21"),
			&CVMoments::get_mu21);
	ClassDB::bind_method(
			D_METHOD("get_mu12"),
			&CVMoments::get_mu12);
	ClassDB::bind_method(
			D_METHOD("get_mu03"),
			&CVMoments::get_mu03);
	ClassDB::bind_method(
			D_METHOD("get_nu20"),
			&CVMoments::get_nu20);
	ClassDB::bind_method(
			D_METHOD("get_nu11"),
			&CVMoments::get_nu11);
	ClassDB::bind_method(
			D_METHOD("get_nu02"),
			&CVMoments::get_nu02);
	ClassDB::bind_method(
			D_METHOD("get_nu30"),
			&CVMoments::get_nu30);
	ClassDB::bind_method(
			D_METHOD("get_nu21"),
			&CVMoments::get_nu21);
	ClassDB::bind_method(
			D_METHOD("get_nu12"),
			&CVMoments::get_nu12);
	ClassDB::bind_method(
			D_METHOD("get_nu03"),
			&CVMoments::get_nu03);

	ClassDB::bind_method(
			D_METHOD("set_m00", "value"),
			&CVMoments::set_m00);
	ClassDB::bind_method(
			D_METHOD("set_m10", "value"),
			&CVMoments::set_m10);
	ClassDB::bind_method(
			D_METHOD("set_m01", "value"),
			&CVMoments::set_m01);
	ClassDB::bind_method(
			D_METHOD("set_m20", "value"),
			&CVMoments::set_m20);
	ClassDB::bind_method(
			D_METHOD("set_m11", "value"),
			&CVMoments::set_m11);
	ClassDB::bind_method(
			D_METHOD("set_m02", "value"),
			&CVMoments::set_m02);
	ClassDB::bind_method(
			D_METHOD("set_m30", "value"),
			&CVMoments::set_m30);
	ClassDB::bind_method(
			D_METHOD("set_m21", "value"),
			&CVMoments::set_m21);
	ClassDB::bind_method(
			D_METHOD("set_m12", "value"),
			&CVMoments::set_m12);
	ClassDB::bind_method(
			D_METHOD("set_m03", "value"),
			&CVMoments::set_m03);
	ClassDB::bind_method(
			D_METHOD("set_mu20", "value"),
			&CVMoments::set_mu20);
	ClassDB::bind_method(
			D_METHOD("set_mu11", "value"),
			&CVMoments::set_mu11);
	ClassDB::bind_method(
			D_METHOD("set_mu02", "value"),
			&CVMoments::set_mu02);
	ClassDB::bind_method(
			D_METHOD("set_mu30", "value"),
			&CVMoments::set_mu30);
	ClassDB::bind_method(
			D_METHOD("set_mu21", "value"),
			&CVMoments::set_mu21);
	ClassDB::bind_method(
			D_METHOD("set_mu12", "value"),
			&CVMoments::set_mu12);
	ClassDB::bind_method(
			D_METHOD("set_mu03", "value"),
			&CVMoments::set_mu03);
	ClassDB::bind_method(
			D_METHOD("set_nu20", "value"),
			&CVMoments::set_nu20);
	ClassDB::bind_method(
			D_METHOD("set_nu11", "value"),
			&CVMoments::set_nu11);
	ClassDB::bind_method(
			D_METHOD("set_nu02", "value"),
			&CVMoments::set_nu02);
	ClassDB::bind_method(
			D_METHOD("set_nu30", "value"),
			&CVMoments::set_nu30);
	ClassDB::bind_method(
			D_METHOD("set_nu21", "value"),
			&CVMoments::set_nu21);
	ClassDB::bind_method(
			D_METHOD("set_nu12", "value"),
			&CVMoments::set_nu12);
	ClassDB::bind_method(
			D_METHOD("set_nu03", "value"),
			&CVMoments::set_nu03);

	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "m00"), "set_m00", "get_m00");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "m10"), "set_m10", "get_m10");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "m01"), "set_m01", "get_m01");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "m20"), "set_m20", "get_m20");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "m11"), "set_m11", "get_m11");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "m02"), "set_m02", "get_m02");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "m30"), "set_m30", "get_m30");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "m21"), "set_m21", "get_m21");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "m12"), "set_m12", "get_m12");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "m03"), "set_m03", "get_m03");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "mu20"), "set_mu20", "get_mu20");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "mu11"), "set_mu11", "get_mu11");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "mu02"), "set_mu02", "get_mu02");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "mu30"), "set_mu30", "get_mu30");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "mu21"), "set_mu21", "get_mu21");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "mu12"), "set_mu12", "get_mu12");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "mu03"), "set_mu03", "get_mu03");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "nu20"), "set_nu20", "get_nu20");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "nu11"), "set_nu11", "get_nu11");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "nu02"), "set_nu02", "get_nu02");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "nu30"), "set_nu30", "get_nu30");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "nu21"), "set_nu21", "get_nu21");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "nu12"), "set_nu12", "get_nu12");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "nu03"), "set_nu03", "get_nu03");

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("create", "m00", "m10", "m01", "m20", "m11", "m02", "m30", "m21", "m12", "m03"),
			&CVMoments::create);
}

CVMoments::CVMoments() {
}

CVMoments::~CVMoments() {
}

float CVMoments::get_m00() {
	return rawPointer.m00;
}
float CVMoments::get_m10() {
	return rawPointer.m10;
}
float CVMoments::get_m01() {
	return rawPointer.m01;
}
float CVMoments::get_m20() {
	return rawPointer.m20;
}
float CVMoments::get_m11() {
	return rawPointer.m11;
}
float CVMoments::get_m02() {
	return rawPointer.m02;
}
float CVMoments::get_m30() {
	return rawPointer.m30;
}
float CVMoments::get_m21() {
	return rawPointer.m21;
}
float CVMoments::get_m12() {
	return rawPointer.m12;
}
float CVMoments::get_m03() {
	return rawPointer.m03;
}
float CVMoments::get_mu20() {
	return rawPointer.mu20;
}
float CVMoments::get_mu11() {
	return rawPointer.mu11;
}
float CVMoments::get_mu02() {
	return rawPointer.mu02;
}
float CVMoments::get_mu30() {
	return rawPointer.mu30;
}
float CVMoments::get_mu21() {
	return rawPointer.mu21;
}
float CVMoments::get_mu12() {
	return rawPointer.mu12;
}
float CVMoments::get_mu03() {
	return rawPointer.mu03;
}
float CVMoments::get_nu20() {
	return rawPointer.nu20;
}
float CVMoments::get_nu11() {
	return rawPointer.nu11;
}
float CVMoments::get_nu02() {
	return rawPointer.nu02;
}
float CVMoments::get_nu30() {
	return rawPointer.nu30;
}
float CVMoments::get_nu21() {
	return rawPointer.nu21;
}
float CVMoments::get_nu12() {
	return rawPointer.nu12;
}
float CVMoments::get_nu03() {
	return rawPointer.nu03;
}

void CVMoments::set_m00(float value) {
	rawPointer.m00 = value;
}
void CVMoments::set_m10(float value) {
	rawPointer.m10 = value;
}
void CVMoments::set_m01(float value) {
	rawPointer.m01 = value;
}
void CVMoments::set_m20(float value) {
	rawPointer.m20 = value;
}
void CVMoments::set_m11(float value) {
	rawPointer.m11 = value;
}
void CVMoments::set_m02(float value) {
	rawPointer.m02 = value;
}
void CVMoments::set_m30(float value) {
	rawPointer.m30 = value;
}
void CVMoments::set_m21(float value) {
	rawPointer.m21 = value;
}
void CVMoments::set_m12(float value) {
	rawPointer.m12 = value;
}
void CVMoments::set_m03(float value) {
	rawPointer.m03 = value;
}
void CVMoments::set_mu20(float value) {
	rawPointer.mu20 = value;
}
void CVMoments::set_mu11(float value) {
	rawPointer.mu11 = value;
}
void CVMoments::set_mu02(float value) {
	rawPointer.mu02 = value;
}
void CVMoments::set_mu30(float value) {
	rawPointer.mu30 = value;
}
void CVMoments::set_mu21(float value) {
	rawPointer.mu21 = value;
}
void CVMoments::set_mu12(float value) {
	rawPointer.mu12 = value;
}
void CVMoments::set_mu03(float value) {
	rawPointer.mu03 = value;
}
void CVMoments::set_nu20(float value) {
	rawPointer.nu20 = value;
}
void CVMoments::set_nu11(float value) {
	rawPointer.nu11 = value;
}
void CVMoments::set_nu02(float value) {
	rawPointer.nu02 = value;
}
void CVMoments::set_nu30(float value) {
	rawPointer.nu30 = value;
}
void CVMoments::set_nu21(float value) {
	rawPointer.nu21 = value;
}
void CVMoments::set_nu12(float value) {
	rawPointer.nu12 = value;
}
void CVMoments::set_nu03(float value) {
	rawPointer.nu03 = value;
}

cv::Moments CVMoments::get_pointer() {
	return rawPointer;
}

void CVMoments::set_pointer(cv::Moments _pointer) {
	rawPointer = _pointer;
}

Ref<CVMoments> CVMoments::create(
		float m00, float m10,
		float m01, float m20,
		float m11, float m02,
		float m30, float m21,
		float m12, float m03) {
	Ref<CVMoments> output;
	output.instantiate();

	output->set_pointer(
			cv::Moments(m00, m10, m01, m20, m11, m02, m30, m21, m12, m03));

	return output;
}

String CVMoments::_to_string() const {
	return UtilityFunctions::str("[ CVMoments instance (",
			rawPointer.m00, ", ",
			rawPointer.m10, ", ",
			rawPointer.m01, ", ",
			rawPointer.m20, ", ",
			rawPointer.m11, ", ",
			rawPointer.m02, ", ",
			rawPointer.m30, ", ",
			rawPointer.m21, ", ",
			rawPointer.m12, ", ",
			rawPointer.m03, ") ]");
}
