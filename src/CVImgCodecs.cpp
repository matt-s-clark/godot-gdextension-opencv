#include "CVImgCodecs.h"
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void CVImgCodecs::_bind_methods() {
	ClassDB::bind_static_method(get_class_static(), D_METHOD("imread", "filename", "flags"), &CVImgCodecs::imread);
}

CVImgCodecs::CVImgCodecs() {
}

CVImgCodecs::~CVImgCodecs() {
}

PackedByteArray CVImgCodecs::imread(const String &filename, const int flags) {
	// Default flags value = cv::IMREAD_COLOR

	cv::String image_path(filename.utf8());
	std::cout << "Image Path: " << image_path << std::endl;

	cv::Mat loadedImage = cv::imread(image_path, cv::IMREAD_COLOR);

	cv::Size size = loadedImage.size();
	int height = size.height;
	int width = size.width;

	int sizear = width * height * loadedImage.channels();

	PackedByteArray bytes;
	bytes.resize(sizear);
	memcpy(bytes.ptrw(), loadedImage.data, sizear);

	return bytes;
}