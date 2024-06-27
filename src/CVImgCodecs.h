#ifndef CV_IMGCODECS_H
#define CV_IMGCODECS_H

#include "CVMat.h"
#include "Macros.h"
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
protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVImgCodecs();
	~CVImgCodecs();

	static Ref<CVMat> imread(const String filename, Dictionary additional_parameters);
	static bool imwrite(const String filename, Ref<CVMat> img, Dictionary additional_parameters);
};

} //namespace godot

#endif