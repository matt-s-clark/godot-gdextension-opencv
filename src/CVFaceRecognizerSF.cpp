#include "CVFaceRecognizerSF.h"

using namespace godot;

void CVFaceRecognizerSF::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("align_crop", "src_img", "face_box"),
			&CVFaceRecognizerSF::align_crop);
	ClassDB::bind_method(
			D_METHOD("feature", "aligned_img"),
			&CVFaceRecognizerSF::feature);
	ClassDB::bind_method(
			D_METHOD("match", "face_feature1", "face_feature2", "additional_parameters"),
			&CVFaceRecognizerSF::match);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("create", "model", "config", "additional_parameters"),
			&CVFaceRecognizerSF::create);
}

CVFaceRecognizerSF::CVFaceRecognizerSF() {
}

CVFaceRecognizerSF::~CVFaceRecognizerSF() {
}

Ref<CVMat> CVFaceRecognizerSF::align_crop(Ref<CVMat> src_img, Ref<CVMat> face_box) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	ERR_FAIL_NULL_V_MSG(src_img, output, "src_img should not be null.");
	ERR_FAIL_NULL_V_MSG(face_box, output, "face_box should not be null.");

	SAFE_CALL(rawDetector->alignCrop(src_img->get_mat(), face_box->get_mat(), outMat));

	output->set_mat(outMat);

	return output;
}

Ref<CVMat> CVFaceRecognizerSF::feature(Ref<CVMat> aligned_img) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	ERR_FAIL_NULL_V_MSG(aligned_img, output, "aligned_img should not be null.");

	SAFE_CALL(rawDetector->feature(aligned_img->get_mat(), outMat));

	output->set_mat(outMat);

	return output;
}

float CVFaceRecognizerSF::match(Ref<CVMat> face_feature1, Ref<CVMat> face_feature2, Dictionary additional_parameters) {
	float output = -1;
	int dis_type = 0;

	ERR_FAIL_NULL_V_MSG(face_feature1, output, "face_feature1 should not be null.");
	ERR_FAIL_NULL_V_MSG(face_feature2, output, "face_feature2 should not be null.");

	GET_ADITIONAL_PROPERTY(additional_parameters, dis_type, "dis_type", Variant::INT, "INT");

	SAFE_CALL(output = rawDetector->match(face_feature1->get_mat(), face_feature2->get_mat(), dis_type))

	return output;
}

cv::Ptr<cv::FaceRecognizerSF> CVFaceRecognizerSF::get_pointer() {
	return rawDetector;
}

void CVFaceRecognizerSF::set_pointer(cv::Ptr<cv::FaceRecognizerSF> pointer) {
	rawDetector = pointer;
}

Ref<CVFaceRecognizerSF> CVFaceRecognizerSF::create(String model, String config, Dictionary additional_parameters) {
	cv::Ptr<cv::FaceRecognizerSF> outDetector;
	Ref<CVFaceRecognizerSF> output;
	output.instantiate();

	int backend_id = 0, target_id = 0;

	cv::String modelIn(model.utf8());
	cv::String configIn(config.utf8());

	GET_ADITIONAL_PROPERTY(additional_parameters, backend_id, "backend_id", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, target_id, "target_id", Variant::INT, "INT");

	SAFE_CALL(outDetector = cv::FaceRecognizerSF::create(modelIn, configIn));

	output->set_pointer(outDetector);

	return output;
}

String CVFaceRecognizerSF::_to_string() const {
	return "[ CVFaceRecognizerSF Instance ]";
}