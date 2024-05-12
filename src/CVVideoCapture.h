#ifndef CV_VIDEOCAPTURE_H
#define CV_VIDEOCAPTURE_H

#include "CVMat.h"
#include "Macros.h"
#include <stdio.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

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

	float get(int propId);
	String getBackendName();
	bool getExceptionMode();
	bool grab();
	bool is_opened();
	void open(Variant source, int api, Variant parameters);
	Ref<CVMat> read();
	void release();
	Ref<CVMat> retrieve(int flag);
	bool set(int propId, float value);
	void setExceptionMode(bool enable);
};

} //namespace godot

#endif