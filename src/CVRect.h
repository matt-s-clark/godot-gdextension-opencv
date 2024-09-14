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
	Variant get_width();
	Variant get_x();
	Variant get_y();
	void set_height(Variant value);
	void set_values(Variant x, Variant y, Variant width, Variant height); // <Helper>
	void set_width(Variant value);
	void set_x(Variant value);
	void set_y(Variant value);
	Vector2 tl();

	cv::Rect get_pointer();
	void set_pointer(cv::Rect rect);

	static Ref<CVRect> from_values(Variant x, Variant y, Variant width, Variant height); // <Helper>
};

} //namespace godot

#endif