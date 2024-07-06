#ifndef CVFACERECOGNIZERSF_H
#define CVFACERECOGNIZERSF_H

#include "CVMat.h"
#include "CVRect.h"
#include "Macros.h"
#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/objdetect/face.hpp>

namespace godot {

class CVFaceRecognizerSF : public RefCounted {
	GDCLASS(CVFaceRecognizerSF, RefCounted)

private:
	cv::Ptr<cv::FaceRecognizerSF> rawDetector;

protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVFaceRecognizerSF();
	~CVFaceRecognizerSF();

	Ref<CVMat> align_crop(Ref<CVMat> src_img, Ref<CVMat> face_box);
	Ref<CVMat> feature(Ref<CVMat> aligned_img);
	float match(Ref<CVMat> face_feature1, Ref<CVMat> face_feature2, Dictionary additional_parameters);

	cv::Ptr<cv::FaceRecognizerSF> get_pointer();
	void set_pointer(cv::Ptr<cv::FaceRecognizerSF> pointer);

	static Ref<CVFaceRecognizerSF> create(String model, String config, Dictionary additional_parameters);
};

} //namespace godot

#endif