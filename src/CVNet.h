#ifndef CVNET_H
#define CVNET_H

#include "CVMat.h"
#include "Macros.h"
#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>
#include <opencv2/dnn.hpp>

namespace godot {

class CVNet : public RefCounted {
	GDCLASS(CVNet, RefCounted)

private:
	cv::dnn::Net rawNet;

protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVNet();
	~CVNet();

	String dump();
	bool empty();
	Ref<CVMat> forward();
	void setInput(Ref<CVMat> blob, Dictionary additional_parameters);

	cv::dnn::Net get_net();
	void set_net(cv::dnn::Net value);
};

} //namespace godot

#endif