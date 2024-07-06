#ifndef CVFACEDETECTORYN_H
#define CVFACEDETECTORYN_H

#include "CVMat.h"
#include "CVRect.h"
#include "Macros.h"
#include <godot_cpp/classes/image_texture.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/objdetect/face.hpp>

namespace godot {

class CVFaceDetectorYN : public RefCounted {
	GDCLASS(CVFaceDetectorYN, RefCounted)

private:
	cv::Ptr<cv::FaceDetectorYN> rawDetector;

protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVFaceDetectorYN();
	~CVFaceDetectorYN();

	Ref<CVMat> detect(Ref<CVMat> image);
	Array detect_simplified(Ref<CVMat> image); // <Helper>
	Vector2 get_input_size();
	float get_nms_threshold();
	float get_score_threshold();
	int get_top_k();
	void set_input_size(Vector2 input_size);
	void set_nms_threshold(float nms_threshold);
	void set_score_threshold(float score_threshold);
	void set_top_k(int top_k);

	cv::Ptr<cv::FaceDetectorYN> get_pointer();
	void set_pointer(cv::Ptr<cv::FaceDetectorYN> pointer);

	static Ref<CVFaceDetectorYN> create(String model, String config, Vector2 input_size, Dictionary additional_parameters);
};

} //namespace godot

#endif