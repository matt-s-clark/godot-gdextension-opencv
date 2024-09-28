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
			D_METHOD("set_image", "image"),
			&CVMat::set_image);

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
	ClassDB::bind_method(
			D_METHOD("row", "y"),
			&CVMat::row);
	ClassDB::bind_method(
			D_METHOD("col", "x"),
			&CVMat::col);
	ClassDB::bind_method(
			D_METHOD("copy"),
			&CVMat::copy);
	ClassDB::bind_method(
			D_METHOD("depth"),
			&CVMat::depth);
	ClassDB::bind_method(
			D_METHOD("set_texture", "texture"),
			&CVMat::set_texture);
	ClassDB::bind_method(
			D_METHOD("get_texture"),
			&CVMat::get_texture);
	ClassDB::bind_method(
			D_METHOD("get_array"),
			&CVMat::get_array);
	ClassDB::bind_method(
			D_METHOD("set_array", "array", "columns", "type"),
			&CVMat::set_array);
	ClassDB::bind_method(
			D_METHOD("dump"),
			&CVMat::dump);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "cols"), "set_read_only", "get_cols");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "rows"), "set_read_only", "get_rows");

	ClassDB::bind_method(
			D_METHOD("multiply", "value"),
			&CVMat::multiply);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("zeros", "rows", "cols", "type"),
			&CVMat::zeros);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("ones", "rows", "cols", "type"),
			&CVMat::ones);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("eye", "rows", "cols", "type"),
			&CVMat::eye);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("from_image", "image"),
			&CVMat::from_image);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("from_texture", "image"),
			&CVMat::from_texture);
	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("from_array", "array", "columns", "type"),
			&CVMat::from_array);
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

void CVMat::set_image(Ref<Image> image) {
	cv::Mat output;

	ERR_FAIL_NULL_V_MSG(image, , "image should not be null.");

	PackedByteArray data = image->get_data();

	rawMat = cv::Mat(image->get_width(), image->get_height(), CV_8UC4, data.ptrw());
}

Variant CVMat::get_at(int row, int col) {
	Variant output = 0;

	if (row >= rawMat.rows || col >= rawMat.cols) {
		UtilityFunctions::push_error("Value out of bounds");
		return output;
	}

	try {
		switch (rawMat.type()) {
			case CV_8U: {
				output = rawMat.at<uchar>(row, col);
				break;
			}
			case CV_8S: {
				output = rawMat.at<schar>(row, col);
				break;
			}
			case CV_16U: {
				output = rawMat.at<ushort>(row, col);
				break;
			}
			case CV_16S: {
				output = rawMat.at<short>(row, col);
				break;
			}
			case CV_32S: {
				output = rawMat.at<int>(row, col);
				break;
			}
			case CV_32F: {
				output = rawMat.at<float>(row, col);
				break;
			}
			case CV_64F: {
				output = rawMat.at<double>(row, col);
				break;
			}

			case CV_8UC2: {
				cv::Vec2b tmp = rawMat.at<cv::Vec2b>(row, col);
				output = Vector2i(tmp[0], tmp[1]);
				break;
			}
			case CV_8SC2: {
				cv::Vec<schar, 2> tmp = rawMat.at<cv::Vec<schar, 2>>(row, col);
				output = Vector2i(tmp[0], tmp[1]);
				break;
			}
			case CV_16UC2: {
				cv::Vec2w tmp = rawMat.at<cv::Vec2w>(row, col);
				output = Vector2i(tmp[0], tmp[1]);
				break;
			}
			case CV_16SC2: {
				cv::Vec2s tmp = rawMat.at<cv::Vec2s>(row, col);
				output = Vector2i(tmp[0], tmp[1]);
				break;
			}
			case CV_32SC2: {
				cv::Vec2i tmp = rawMat.at<cv::Vec2i>(row, col);
				output = Vector2i(tmp[0], tmp[1]);
				break;
			}
			case CV_32FC2: {
				cv::Vec2f tmp = rawMat.at<cv::Vec2f>(row, col);
				output = Vector2(tmp[0], tmp[1]);
				break;
			}
			case CV_64FC2: {
				cv::Vec2d tmp = rawMat.at<cv::Vec2d>(row, col);
				output = Vector2(tmp[0], tmp[1]);
				break;
			}

			case CV_8UC3: {
				cv::Vec3b tmp = rawMat.at<cv::Vec3b>(row, col);
				output = Vector3i(tmp[0], tmp[1], tmp[2]);
				break;
			}
			case CV_8SC3: {
				cv::Vec<schar, 3> tmp = rawMat.at<cv::Vec<schar, 3>>(row, col);
				output = Vector3i(tmp[0], tmp[1], tmp[2]);
				break;
			}
			case CV_16UC3: {
				cv::Vec3w tmp = rawMat.at<cv::Vec3w>(row, col);
				output = Vector3i(tmp[0], tmp[1], tmp[2]);
				break;
			}
			case CV_16SC3: {
				cv::Vec3s tmp = rawMat.at<cv::Vec3s>(row, col);
				output = Vector3i(tmp[0], tmp[1], tmp[2]);
				break;
			}
			case CV_32SC3: {
				cv::Vec3i tmp = rawMat.at<cv::Vec3i>(row, col);
				output = Vector3i(tmp[0], tmp[1], tmp[2]);
				break;
			}
			case CV_32FC3: {
				cv::Vec3f tmp = rawMat.at<cv::Vec3f>(row, col);
				output = Vector3i(tmp[0], tmp[1], tmp[2]);
				break;
			}
			case CV_64FC3: {
				cv::Vec3d tmp = rawMat.at<cv::Vec3d>(row, col);
				output = Vector3(tmp[0], tmp[1], tmp[2]);
				break;
			}

			case CV_8UC4: {
				cv::Vec4b tmp = rawMat.at<cv::Vec4b>(row, col);
				output = Vector4i(tmp[0], tmp[1], tmp[2], tmp[3]);
				break;
			}
			case CV_8SC4: {
				cv::Vec<schar, 4> tmp = rawMat.at<cv::Vec<schar, 4>>(row, col);
				output = Vector4i(tmp[0], tmp[1], tmp[2], tmp[3]);
				break;
			}
			case CV_16UC4: {
				cv::Vec4w tmp = rawMat.at<cv::Vec4w>(row, col);
				output = Vector4i(tmp[0], tmp[1], tmp[2], tmp[3]);
				break;
			}
			case CV_16SC4: {
				cv::Vec4s tmp = rawMat.at<cv::Vec4s>(row, col);
				output = Vector4i(tmp[0], tmp[1], tmp[2], tmp[3]);
				break;
			}
			case CV_32SC4: {
				cv::Vec4i tmp = rawMat.at<cv::Vec4i>(row, col);
				output = Vector4i(tmp[0], tmp[1], tmp[2], tmp[3]);
				break;
			}
			case CV_32FC4: {
				cv::Vec4f tmp = rawMat.at<cv::Vec4f>(row, col);
				output = Vector4(tmp[0], tmp[1], tmp[2], tmp[3]);
				break;
			}
			case CV_64FC4: {
				cv::Vec4d tmp = rawMat.at<cv::Vec4d>(row, col);
				output = Vector4(tmp[0], tmp[1], tmp[2], tmp[3]);
				break;
			}
		}
	} catch (const std::exception &stde) {
		UtilityFunctions::push_error(stde.what());
	}

	return output;
}

void CVMat::set_at(int row, int col, Variant value) {
	if (row >= rawMat.rows || col >= rawMat.cols) {
		UtilityFunctions::push_error("Value out of bounds");
		return;
	}

	int t = value.get_type();
	int inputChannels =
			t == Variant::VECTOR4 || t == Variant::VECTOR4I	  ? 4
			: t == Variant::VECTOR3 || t == Variant::VECTOR3I ? 3
			: t == Variant::VECTOR2 || t == Variant::VECTOR2I ? 2
			: t == Variant::FLOAT || t == Variant::INT		  ? 1
															  : 0;

	if (rawMat.channels() != inputChannels) {
		UtilityFunctions::push_error("Mat channels and input mismatch: ", rawMat.channels(), " x ", inputChannels);
		return;
	}

	try {
		switch (rawMat.type()) {
			case CV_8U:
				rawMat.at<uchar>(row, col) = value;
				break;
			case CV_8S:
				rawMat.at<schar>(row, col) = value;
				break;
			case CV_16U:
				rawMat.at<ushort>(row, col) = value;
				break;
			case CV_16S:
				rawMat.at<short>(row, col) = value;
				break;
			case CV_32S:
				rawMat.at<int>(row, col) = value;
				break;
			case CV_32F:
				rawMat.at<float>(row, col) = value;
				break;
			case CV_64F:
				rawMat.at<double>(row, col) = value;
				break;

			case CV_8UC2: {
				cv::Vec2b tmp = cv::Vec2b(((Vector2)value).x, ((Vector2)value).y);
				rawMat.at<cv::Vec2b>(row, col) = tmp;
				break;
			}
			case CV_8SC2: {
				cv::Vec<schar, 2> tmp = cv::Vec<schar, 2>(((Vector2)value).x, ((Vector2)value).y);
				rawMat.at<cv::Vec<schar, 2>>(row, col) = tmp;
				break;
			}
			case CV_16UC2: {
				cv::Vec2w tmp = cv::Vec2w(((Vector2)value).x, ((Vector2)value).y);
				rawMat.at<cv::Vec2w>(row, col) = tmp;
				break;
			}
			case CV_16SC2: {
				cv::Vec2s tmp = cv::Vec2s(((Vector2)value).x, ((Vector2)value).y);
				rawMat.at<cv::Vec2s>(row, col) = tmp;
				break;
			}
			case CV_32SC2: {
				cv::Vec2i tmp = cv::Vec2i(((Vector2)value).x, ((Vector2)value).y);
				rawMat.at<cv::Vec2i>(row, col) = tmp;
				break;
			}
			case CV_32FC2: {
				cv::Vec2f tmp = cv::Vec2f(((Vector2)value).x, ((Vector2)value).y);
				rawMat.at<cv::Vec2f>(row, col) = tmp;
				break;
			}
			case CV_64FC2: {
				cv::Vec2d tmp = cv::Vec2d(((Vector2)value).x, ((Vector2)value).y);
				rawMat.at<cv::Vec2d>(row, col) = tmp;
				break;
			}

			case CV_8UC3: {
				cv::Vec3b tmp = cv::Vec3b(((Vector3)value).x, ((Vector3)value).y, ((Vector3)value).z);
				rawMat.at<cv::Vec3b>(row, col) = tmp;
				break;
			}
			case CV_8SC3: {
				cv::Vec<schar, 3> tmp = cv::Vec<schar, 3>(((Vector3)value).x, ((Vector3)value).y, ((Vector3)value).z);
				rawMat.at<cv::Vec<schar, 3>>(row, col) = tmp;
				break;
			}
			case CV_16UC3: {
				cv::Vec3w tmp = cv::Vec3w(((Vector3)value).x, ((Vector3)value).y, ((Vector3)value).z);
				rawMat.at<cv::Vec3w>(row, col) = tmp;
				break;
			}
			case CV_16SC3: {
				cv::Vec3s tmp = cv::Vec3s(((Vector3)value).x, ((Vector3)value).y, ((Vector3)value).z);
				rawMat.at<cv::Vec3s>(row, col) = tmp;
				break;
			}
			case CV_32SC3: {
				cv::Vec3i tmp = cv::Vec3i(((Vector3)value).x, ((Vector3)value).y, ((Vector3)value).z);
				rawMat.at<cv::Vec3i>(row, col) = tmp;
				break;
			}
			case CV_32FC3: {
				cv::Vec3f tmp = cv::Vec3f(((Vector3)value).x, ((Vector3)value).y, ((Vector3)value).z);
				rawMat.at<cv::Vec3f>(row, col) = tmp;
				break;
			}
			case CV_64FC3: {
				cv::Vec3d tmp = cv::Vec3d(((Vector3)value).x, ((Vector3)value).y, ((Vector3)value).z);
				rawMat.at<cv::Vec3d>(row, col) = tmp;
				break;
			}

			case CV_8UC4: {
				cv::Vec4b tmp = cv::Vec4b(((Vector4)value).x, ((Vector4)value).y, ((Vector4)value).z, ((Vector4)value).w);
				rawMat.at<cv::Vec4b>(row, col) = tmp;
				break;
			}
			case CV_8SC4: {
				cv::Vec<schar, 4> tmp = cv::Vec<schar, 4>(((Vector4)value).x, ((Vector4)value).y, ((Vector4)value).z, ((Vector4)value).w);
				rawMat.at<cv::Vec<schar, 4>>(row, col) = tmp;
				break;
			}
			case CV_16UC4: {
				cv::Vec4w tmp = cv::Vec4w(((Vector4)value).x, ((Vector4)value).y, ((Vector4)value).z, ((Vector4)value).w);
				rawMat.at<cv::Vec4w>(row, col) = tmp;
				break;
			}
			case CV_16SC4: {
				cv::Vec4s tmp = cv::Vec4s(((Vector4)value).x, ((Vector4)value).y, ((Vector4)value).z, ((Vector4)value).w);
				rawMat.at<cv::Vec4s>(row, col) = tmp;
				break;
			}
			case CV_32SC4: {
				cv::Vec4i tmp = cv::Vec4i(((Vector4)value).x, ((Vector4)value).y, ((Vector4)value).z, ((Vector4)value).w);
				rawMat.at<cv::Vec4i>(row, col) = tmp;
				break;
			}
			case CV_32FC4: {
				cv::Vec4f tmp = cv::Vec4f(((Vector4)value).x, ((Vector4)value).y, ((Vector4)value).z, ((Vector4)value).w);
				rawMat.at<cv::Vec4f>(row, col) = tmp;
				break;
			}
			case CV_64FC4: {
				cv::Vec4d tmp = cv::Vec4d(((Vector4)value).x, ((Vector4)value).y, ((Vector4)value).z, ((Vector4)value).w);
				rawMat.at<cv::Vec4d>(row, col) = tmp;
				break;
			}
		}
	} catch (const std::exception &stde) {
		UtilityFunctions::push_error(stde.what());
	}
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

void CVMat::set_pointer(cv::Mat _mat) {
	rawMat = _mat;
}

cv::Mat CVMat::get_pointer() {
	return rawMat;
}

void CVMat::multiply(Variant value) {
	if (value.get_type() == Variant::INT) {
		rawMat = rawMat * (int)value;
	} else if (value.get_type() == Variant::FLOAT) {
		rawMat = rawMat * (float)value;
	} else {
		UtilityFunctions::push_error("Type is not supported");
	}
}

void CVMat::set_read_only(int input) {
	UtilityFunctions::push_warning("This property is a read only");
}

Ref<CVMat> CVMat::ones(int rows, int cols, int type) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	SAFE_CALL(outMat = cv::Mat::ones(rows, cols, type));

	output->set_pointer(outMat);

	return output;
}

Ref<CVMat> CVMat::zeros(int rows, int cols, int type) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	SAFE_CALL(outMat = cv::Mat::zeros(rows, cols, type));

	output->set_pointer(outMat);

	return output;
}

Ref<CVMat> CVMat::eye(int rows, int cols, int type) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	SAFE_CALL(outMat = cv::Mat::eye(rows, cols, type));

	output->set_pointer(outMat);

	return output;
}

Ref<CVMat> CVMat::col(int x) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	SAFE_CALL(outMat = rawMat.col(x));

	output->set_pointer(outMat);

	return output;
}

Ref<CVMat> CVMat::row(int y) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	SAFE_CALL(outMat = rawMat.row(y));

	output->set_pointer(outMat);

	return output;
}

Ref<CVMat> CVMat::copy() {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	SAFE_CALL(rawMat.copyTo(outMat));

	output->set_pointer(outMat);

	return output;
}

int CVMat::depth() {
	int output = -1;

	SAFE_CALL(output = rawMat.depth());

	return output;
}

Ref<CVMat> CVMat::from_image(Ref<Image> image) {
	Ref<CVMat> output;
	output.instantiate();

	ERR_FAIL_NULL_V_MSG(image, output, "image should not be null.");

	output->set_image(image);

	return output;
}

Ref<CVMat> CVMat::from_texture(Ref<Texture2D> texture) {
	Ref<CVMat> output;
	output.instantiate();

	ERR_FAIL_NULL_V_MSG(texture, output, "texture should not be null.");

	output->set_texture(texture);

	return output;
}

Ref<Texture> CVMat::get_texture() {
	Ref<Texture> output;
	output.instantiate();

	Ref<Image> im = get_image();

	if (im->is_empty())
		return output;

	SAFE_CALL(output = ImageTexture::create_from_image(im));

	return output;
}

void CVMat::set_texture(Ref<Texture2D> texture) {
	ERR_FAIL_NULL_V_MSG(texture, , "texture should not be null.");

	Ref<Image> im = texture->get_image();

	if (im->is_empty())
		return;

	set_image(im);
}

Ref<CVMat> CVMat::from_array(Array array, int columns, int type) {
	Ref<CVMat> output;
	output.instantiate();

	output->set_array(array, columns, type);

	return output;
}

Array CVMat::get_array() {
	Array output;

	int sizear = rawMat.cols * rawMat.rows * rawMat.channels();

	PackedByteArray bytes;
	bytes.resize(sizear);
	memcpy(bytes.ptrw(), rawMat.data, sizear);

	output = Array(bytes);

	return output;
}

void CVMat::set_array(Array array, int columns, int type) {
	int channels = 1 + type / 8;

	if (type % 8 == 4) {
		PackedInt32Array data = PackedInt32Array(array);
		rawMat = cv::Mat(array.size() / (columns * channels), columns, type, data.ptrw());
	} else if (type % 8 == 5) {
		PackedFloat32Array data = PackedFloat32Array(array);
		rawMat = cv::Mat(array.size() / (columns * channels), columns, type, data.ptrw());
	} else if (type % 8 == 6) {
		PackedFloat64Array data = PackedFloat64Array(array);
		rawMat = cv::Mat(array.size() / (columns * channels), columns, type, data.ptrw());
	} else {
		UtilityFunctions::push_error("Type is not supported by godot Variant.");
	}
}

String CVMat::dump() {
	String output = "";

	for (size_t i = 0; i < MIN(rawMat.rows, 11); i++) {
		for (size_t j = 0; j < MIN(rawMat.cols, 11); j++) {
			if(i == 10 || j == 10)
				output = UtilityFunctions::str(output, "...", "\t");
			else
				output = UtilityFunctions::str(output, get_at(i, j), "\t");
		}
		output = UtilityFunctions::str(output, "\n");
	}

	return output;
}

String CVMat::_to_string() const {
	String sizes = "";
	for (size_t i = 0; i < rawMat.size.dims(); i++) {
		String separator = (i == 0) ? "" : ", ";
		sizes = UtilityFunctions::str(sizes, separator, rawMat.size[i]);
	}
	return UtilityFunctions::str("[ CVMat instance (", sizes, ") ]");
}
