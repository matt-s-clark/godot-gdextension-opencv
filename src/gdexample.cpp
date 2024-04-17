#include "gdexample.h"
#include <godot_cpp/core/class_db.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace godot;

void GDExample::_bind_methods()
{
}

GDExample::GDExample()
{
    // Initialize any variables here.
    time_passed = 0.0;

    std::string image_path = "aruco-capture.png";
    std::cout << "Image Path: " << image_path << std::endl;
    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);

    // this->set_texture(img);
    // ImageTexture.create_from_image(img);

    if (img.empty())
    {
        std::cout << "Could not read image" << std::endl;
    }

    std::cout << "DEBUG: " << img << std::endl;
}

GDExample::~GDExample()
{
    // Add your cleanup here.
}

void GDExample::_process(double delta)
{
    time_passed += delta;

    Vector2 new_position = Vector2(10.0 + (10.0 * sin(time_passed * 2.0)), 10.0 + (10.0 * cos(time_passed * 1.5)));

    set_position(new_position);
}