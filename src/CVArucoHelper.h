#ifndef CV_ARUCO_HELPER_H
#define CV_ARUCO_HELPER_H

#include "CVMat.h"
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/objdetect/aruco_detector.hpp>
#include <opencv2/objdetect/aruco_dictionary.hpp>

namespace godot {

class CVArucoHelper : public Object {
	GDCLASS(CVArucoHelper, Object)

private:
protected:
	static void _bind_methods();

public:
	CVArucoHelper();
	~CVArucoHelper();

	static Array getMarkerPosition();
};
} //namespace godot

#endif