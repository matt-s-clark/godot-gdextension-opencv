#ifndef CVBACKGROUNDSUBTRACTORKNN_H
#define CVBACKGROUNDSUBTRACTORKNN_H

#include "CVMat.h"
#include "Macros.h"
#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>
#include <opencv2/video.hpp>

namespace godot {

class CVBackgroundSubtractorKNN : public RefCounted {
	GDCLASS(CVBackgroundSubtractorKNN, RefCounted)

private:
	cv::Ptr<cv::BackgroundSubtractorKNN> rawPointer;

protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVBackgroundSubtractorKNN();
	~CVBackgroundSubtractorKNN();

	Ref<CVMat> apply(Ref<CVMat> image, Dictionary additional_parameters);
	Ref<CVMat> get_background_image();

	static Ref<CVBackgroundSubtractorKNN> create(Dictionary additional_parameters); // <Helper>

	cv::Ptr<cv::BackgroundSubtractorKNN> get_pointer();
	void set_pointer(cv::Ptr<cv::BackgroundSubtractorKNN> value);
};

} //namespace godot

#endif