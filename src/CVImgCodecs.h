#ifndef CV_IMGCODECS_H
#define CV_IMGCODECS_H

#include <godot_cpp/classes/ref_counted.hpp>
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

	static PackedByteArray imread(const String &filename, const int flags);
};

} //namespace godot

#endif