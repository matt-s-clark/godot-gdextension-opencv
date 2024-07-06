#ifndef CVBACKGROUNDSUBTRACTORMOG2_H
#define CVBACKGROUNDSUBTRACTORMOG2_H

#include "CVMat.h"
#include "Macros.h"
#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>
#include <opencv2/video.hpp>

namespace godot {

class CVBackgroundSubtractorMOG2 : public RefCounted {
	GDCLASS(CVBackgroundSubtractorMOG2, RefCounted)

private:
	cv::Ptr<cv::BackgroundSubtractorMOG2> rawPointer;

protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVBackgroundSubtractorMOG2();
	~CVBackgroundSubtractorMOG2();

	Ref<CVMat> apply(Ref<CVMat> image, Dictionary additional_parameters);
	Ref<CVMat> get_background_image();

	static Ref<CVBackgroundSubtractorMOG2> create(Dictionary additional_parameters); // <Helper>

	cv::Ptr<cv::BackgroundSubtractorMOG2> get_pointer();
	void set_pointer(cv::Ptr<cv::BackgroundSubtractorMOG2> value);
};

} //namespace godot

#endif