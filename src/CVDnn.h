#ifndef CV_DNN_H
#define CV_DNN_H

#include "CVMat.h"
#include "CVNet.h"
#include "Macros.h"
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>
#include <opencv2/dnn.hpp>

namespace godot {

class CVDnn : public Object {
	GDCLASS(CVDnn, Object)

private:
protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVDnn();
	~CVDnn();

	static Ref<CVMat> blobFromImage(Ref<CVMat> image, Dictionary additional_parameters);
	static Ref<CVNet> readNet(const String model, Dictionary additional_parameters);
};

} //namespace godot

#endif