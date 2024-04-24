#ifndef CV_IMGCODECS_H
#define CV_IMGCODECS_H

#include <godot_cpp/classes/ref_counted.hpp>
#include <opencv2/imgcodecs.hpp>

namespace godot {

class CVImgCodecs : public RefCounted {
	GDCLASS(CVImgCodecs, RefCounted)

private:
	// double time_passed;
	// Ref<Image> godotImg;

protected:
	static void _bind_methods();

public:
	// GDExample();
	// ~GDExample();

	Ref<cv::Mat> imread(String &filename, int flags = cv::IMREAD_COLOR);
};

} //namespace godot

#endif