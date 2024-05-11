#ifndef CV_VIDEOCAPTURE_H
#define CV_VIDEOCAPTURE_H

#include "CVMat.h"
#include "Macros.h"
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <stdio.h>

namespace godot {

class CVVideoCapture : public RefCounted {
	GDCLASS(CVVideoCapture, RefCounted)

private:
	cv::VideoCapture rawCap;

protected:
	static void _bind_methods();

public:
	CVVideoCapture();
	~CVVideoCapture();

	void open(Variant source, int api, Variant parameters);
	void release();
	Ref<CVMat> read();

	bool is_opened();
};

} //namespace godot

#endif