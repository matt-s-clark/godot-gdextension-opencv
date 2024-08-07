#include "<ClassName>.h"

using namespace godot;
using namespace cv;

void <ClassName>::_bind_methods() {
<Bindings>
}

<ClassName>::<ClassName>() {
}

<ClassName>::~<ClassName>() {
}

<Implementation>

godot::String <ClassName>::_to_string() const {
	return "[ <ClassName> Module ]";
}
