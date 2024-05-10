#include "CVMat.h"
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/imgproc.hpp>

using namespace godot;

void CVMat::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_image"), &CVMat::get_image);
	ClassDB::bind_method(D_METHOD("get_rows"), &CVMat::get_rows);
	ClassDB::bind_method(D_METHOD("get_cols"), &CVMat::get_cols);
	ClassDB::bind_method(D_METHOD("convert_to", "rtype"), &CVMat::convert_to);
}

// TODO: Determine if this class should be RefCounted

CVMat::CVMat() {
	image = Ref<Image>(memnew(Image));
}

CVMat::~CVMat() {
	try {
		rawMat.release();
	} catch (std::exception &stde) {
		UtilityFunctions::push_error(stde.what());
	}
}

Ref<Image> CVMat::get_image() {
	try {
		if (rawMat.rows == 0 || rawMat.cols == 0) {
			UtilityFunctions::push_error("Mat is empty, returning empty image");
			return image;
		}
		if (image.is_null() || image->is_empty()) {
			cv::Mat rgbMat;

			cv::cvtColor(rawMat, rgbMat, cv::COLOR_BGR2RGB);
			rgbMat.convertTo(rgbMat, CV_8U);

			int sizear = rgbMat.cols * rgbMat.rows * rgbMat.channels();

			// TODO: Conversion to image should depend on type

			PackedByteArray bytes;
			bytes.resize(sizear);
			memcpy(bytes.ptrw(), rgbMat.data, sizear);

			image = Image::create_from_data(rgbMat.cols, rgbMat.rows, false,
					Image::Format::FORMAT_RGB8, bytes);
		}
	} catch (std::exception &stde) {
		UtilityFunctions::push_error(stde.what());
	}

	return image;
}

void CVMat::convert_to(int rtype) {
	try {
		rawMat.convertTo(rawMat, rtype);
	} catch (std::exception &stde) {
		UtilityFunctions::push_error(stde.what());
	}
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
