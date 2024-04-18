#include "gdexample.h"
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>


using namespace godot;

void GDExample::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_godot_image"), &GDExample::get_godot_image);
}

GDExample::GDExample() {
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

	std::cout << "Before Set Texture" << std::endl;
	set_texture(ImageTexture::create_from_image(godotImg));
	std::cout << "After Set Texture" << std::endl;

	UtilityFunctions::print("GDExample Initialised - has the image/texture been applied?");
}

GDExample::~GDExample() {
	// Add your cleanup here.
}

Ref<Image> GDExample::get_godot_image() {
	return godotImg;
}

void GDExample::_process(double delta) {
	time_passed += delta;

	Vector2 new_position = Vector2(10.0 + (10.0 * sin(time_passed * 2.0)), 10.0 + (10.0 * cos(time_passed * 1.5)));

	set_position(new_position);

	// std::cout << "Moving: " << time_passed << std::endl;
}