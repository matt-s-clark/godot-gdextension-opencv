#ifndef CV_IMGCODECS_H
#define CV_IMGCODECS_H

#include "CVMat.h"
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

namespace godot {

class CVImgCodecs : public Object {
	GDCLASS(CVImgCodecs, Object)

private:
	// double time_passed;
	// Ref<Image> godotImg;

protected:
	static void _bind_methods();

public:
	CVImgCodecs();
	~CVImgCodecs();

	static Ref<CVMat> imread(const String &filename, const int flags);
};

} //namespace godot

#endif