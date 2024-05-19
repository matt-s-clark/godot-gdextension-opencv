#ifndef GDCASCADECLASSIFIER_H
#define GDCASCADECLASSIFIER_H

#include "CVMat.h"
#include "CVRect.h"
#include "Macros.h"
#include "opencv2/objdetect.hpp"
#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

namespace godot {

class CVCascadeClassifier : public RefCounted {
	GDCLASS(CVCascadeClassifier, RefCounted)

private:
	cv::CascadeClassifier rawClassifier;

protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVCascadeClassifier();
	~CVCascadeClassifier();

	Dictionary detect_multi_scale(Ref<CVMat> image, Dictionary additional_parameters);
	bool empty() const;
	int get_feature_type() const;
	bool load(const String filename);
};

} //namespace godot

#endif