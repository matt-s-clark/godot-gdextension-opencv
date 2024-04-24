#include "CVMat.h"
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace godot;

void CVMat::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_godot_image"), &CVMat::get_godot_image);
}

CVMat::CVMat() {
	// Initialize any variables here.
	time_passed = 0.0;

	std::string image_path = "aruco-capture.png";
	std::cout << "Image Path: " << image_path << std::endl;
	cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);

	cv::Size size = img.size();
	int height = size.height;
	int width = size.width;

	int sizear = width * height * img.channels();

	UtilityFunctions::print(img.channels());
	UtilityFunctions::print(sizear);

	PackedByteArray bytes;
	bytes.resize(sizear);
	memcpy(bytes.ptrw(), img.data, sizear);

	// Ref<Image> godotImg;
	godotImg = Image::create_from_data(width, height, false, Image::FORMAT_RGB8, bytes);

	UtilityFunctions::print(bytes.decode_double(0));
	UtilityFunctions::print(godotImg->get_height());
}

CVMat::~CVMat() {
	// Add your cleanup here.
}

Ref<Image> CVMat::get_godot_image() {
	return godotImg;
}
