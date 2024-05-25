#ifndef GDRECT_H
#define GDRECT_H

#include "Macros.h"
#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>

namespace godot {

class CVRect : public RefCounted {
	GDCLASS(CVRect, RefCounted)

private:
	cv::Rect rawRect;

protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVRect();
	~CVRect();

	Variant area() const;
	Vector2 br();
	bool contains(Vector2 point);
	bool empty();
	Variant get_height();
	cv::Rect get_rect();
	Variant get_width();
	Variant get_x();
	Variant get_y();
	void set_height(Variant value);
	void set_rect(cv::Rect rect);
	void set_width(Variant value);
	void set_x(Variant value);
	void set_y(Variant value);
	Vector2 tl();
};

} //namespace godot

#endif