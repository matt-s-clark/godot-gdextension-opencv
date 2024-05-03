#include "CVMat.h"
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace godot;

void CVMat::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_godot_image"), &CVMat::get_godot_image);
}

// TODO: Determine if this class should be RefCounted

CVMat::CVMat() {
	// Initialize any variables here.

	std::string image_path = "aruco-capture.png";
	std::cout << "Image Path: " << image_path << std::endl;
	rawMat = cv::imread(image_path, cv::IMREAD_COLOR);
}

CVMat::~CVMat() {
	// Add your cleanup here.
}

Ref<Image> CVMat::get_godot_image() {
	cv::Size size = rawMat.size();
	int height = size.height;
	int width = size.width;

	int sizear = width * height * rawMat.channels();

	UtilityFunctions::print(rawMat.channels());
	UtilityFunctions::print(sizear);

	PackedByteArray bytes;
	bytes.resize(sizear);
	memcpy(bytes.ptrw(), rawMat.data, sizear);

	Ref<Image> godotImg = Image::create_from_data(width, height, false, Image::FORMAT_RGB8, bytes);

	UtilityFunctions::print(bytes.decode_double(0));
	UtilityFunctions::print(godotImg->get_height());

	return godotImg;
}
