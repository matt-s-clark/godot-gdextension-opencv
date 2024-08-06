#ifndef <HeaderClassName>_H
#define <HeaderClassName>_H

#include "CVMat.h"
#include "Macros.h"
#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
<Includes>

namespace godot {

class <ClassName> : public Object {
	GDCLASS(<ClassName>, Object)

private:

protected:
	static void _bind_methods();
	String _to_string() const;

public:
	<ClassName>();
	~<ClassName>();

	<Headers>
};

} //namespace godot

#endif