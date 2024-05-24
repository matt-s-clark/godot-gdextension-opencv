#include "CVMat.h"
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/imgproc.hpp>

using namespace godot;

void CVMat::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("get_image"),
			&CVMat::get_image);

	ClassDB::bind_method(
			D_METHOD("get_rows"),
			&CVMat::get_rows);

	ClassDB::bind_method(
			D_METHOD("get_cols"),
			&CVMat::get_cols);

	ClassDB::bind_method(
			D_METHOD("convert_to", "rtype"),
			&CVMat::convert_to);
	ClassDB::bind_method(
			D_METHOD("get_at", "row", "col"),
			&CVMat::get_at);
	ClassDB::bind_method(
			D_METHOD("set_at", "row", "col", "value"),
			&CVMat::set_at);
	ClassDB::bind_method(
			D_METHOD("channels"),
			&CVMat::channels);
	ClassDB::bind_method(
			D_METHOD("type"),
			&CVMat::type);
	ClassDB::bind_method(
			D_METHOD("set_read_only"),
			&CVMat::set_read_only);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "cols"), "set_read_only", "get_cols");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rows"), "set_read_only", "get_rows");

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("zeros", "rows", "cols", "type"),
			&CVMat::zeros);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("ones", "rows", "cols", "type"),
			&CVMat::ones);
}

CVMat::CVMat() {
	image.instantiate();
}

CVMat::~CVMat() {
	SAFE_CALL(rawMat.release());
}

Ref<Image> CVMat::get_image() {
	if (rawMat.rows == 0 || rawMat.cols == 0) {
		UtilityFunctions::push_error("Mat is empty, returning empty image");
		return image;
	}
	if (image.is_null() || image->is_empty()) {
		cv::Mat rgbMat;

		SAFE_CALL(cv::cvtColor(rawMat, rgbMat, cv::COLOR_BGR2RGB));
		rgbMat.convertTo(rgbMat, CV_8U);

		int sizear = rgbMat.cols * rgbMat.rows * rgbMat.channels();

		// TODO: Conversion to image should depend on type

		PackedByteArray bytes;
		bytes.resize(sizear);
		memcpy(bytes.ptrw(), rgbMat.data, sizear);

		image = Image::create_from_data(rgbMat.cols, rgbMat.rows, false,
				Image::Format::FORMAT_RGB8, bytes);
	}

	return image;
}

Variant CVMat::get_at(int row, int col) {
	Variant output = 0;

	SAFE_CALL(
			switch (rawMat.type() % 8) {
				case CV_8U:
					output = rawMat.at<uchar>(row, col);
					break;
				case CV_8S:
					output = rawMat.at<schar>(row, col);
					break;
				case CV_16U:
					output = rawMat.at<ushort>(row, col);
					break;
				case CV_16S:
					output = rawMat.at<short>(row, col);
					break;
				case CV_32S:
					output = rawMat.at<int>(row, col);
					break;
				case CV_32F:
					output = rawMat.at<float>(row, col);
					break;
				case CV_64F:
					output = rawMat.at<double>(row, col);
					break;
			})

	return output;
}

void CVMat::set_at(int row, int col, Variant value) {
	Variant output;

	SAFE_CALL(
			switch (rawMat.type() % 8) {
				case CV_8U:
					output = rawMat.at<uchar>(row, col) = value;
					break;
				case CV_8S:
					output = rawMat.at<schar>(row, col) = value;
					break;
				case CV_16U:
					output = rawMat.at<ushort>(row, col) = value;
					break;
				case CV_16S:
					output = rawMat.at<short>(row, col) = value;
					break;
				case CV_32S:
					output = rawMat.at<int>(row, col) = value;
					break;
				case CV_32F:
					output = rawMat.at<float>(row, col) = value;
					break;
				case CV_64F:
					rawMat.at<double>(row, col) = value;
					break;
			})
}

int CVMat::channels() const {
	int output = -1;

	SAFE_CALL(output = rawMat.channels());

	return output;
}

int CVMat::type() const {
	int output = -1;

	SAFE_CALL(output = rawMat.type());

	return output;
}

void CVMat::convert_to(int rtype) {
	SAFE_CALL(rawMat.convertTo(rawMat, rtype));
}

int CVMat::get_rows() {
	return rawMat.rows;
}

int CVMat::get_cols() {
	return rawMat.cols;
}

void CVMat::set_mat(cv::Mat _mat) {
	rawMat = _mat;
}

cv::Mat CVMat::get_mat() {
	return rawMat;
}

void CVMat::set_read_only(int input) {
	UtilityFunctions::push_warning("This property is a read only");
}

Ref<CVMat> CVMat::ones(int rows, int cols, int type) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	SAFE_CALL(outMat = cv::Mat::ones(rows, cols, type));

	output->set_mat(outMat);

	return output;
}

Ref<CVMat> CVMat::zeros(int rows, int cols, int type) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	SAFE_CALL(outMat = cv::Mat::zeros(rows, cols, type));

	output->set_mat(outMat);

	return output;
}

String CVMat::_to_string() const {
	return UtilityFunctions::str("[ CVMat instance (", String((Variant)rawMat.cols), ", ", String((Variant)rawMat.rows), ") ]");
}
