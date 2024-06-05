#include "CVFaceDetectorYN.h"

using namespace godot;

void CVFaceDetectorYN::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("detect", "image"),
			&CVFaceDetectorYN::detect);
	ClassDB::bind_method(
			D_METHOD("get_input_size"),
			&CVFaceDetectorYN::get_input_size);
	ClassDB::bind_method(
			D_METHOD("get_nms_threshold"),
			&CVFaceDetectorYN::get_nms_threshold);
	ClassDB::bind_method(
			D_METHOD("get_score_threshold"),
			&CVFaceDetectorYN::get_score_threshold);
	ClassDB::bind_method(
			D_METHOD("get_top_k"),
			&CVFaceDetectorYN::get_top_k);
	ClassDB::bind_method(
			D_METHOD("set_input_size", "input_size"),
			&CVFaceDetectorYN::set_input_size);
	ClassDB::bind_method(
			D_METHOD("set_nms_threshold", "nms_threshold"),
			&CVFaceDetectorYN::set_nms_threshold);
	ClassDB::bind_method(
			D_METHOD("set_score_threshold", "score_threshold"),
			&CVFaceDetectorYN::set_score_threshold);
	ClassDB::bind_method(
			D_METHOD("set_top_k", "top_k"),
			&CVFaceDetectorYN::set_top_k);

	ClassDB::bind_static_method(
			get_class_static(),
			D_METHOD("create", "model", "config", "input_size", "additional_parameters"),
			&CVFaceDetectorYN::create);
}

CVFaceDetectorYN::CVFaceDetectorYN() {
}

CVFaceDetectorYN::~CVFaceDetectorYN() {
}

Ref<CVMat> CVFaceDetectorYN::detect(Ref<CVMat> image) {
	cv::Mat outMat;
	Ref<CVMat> output;
	output.instantiate();

	SAFE_CALL(rawDetector->detect(image->get_mat(), outMat));

	output->set_mat(outMat);

	return output;
}

Ref<CVFaceDetectorYN> CVFaceDetectorYN::create(String model, String config, Vector2 input_size, Dictionary additional_parameters) {
	cv::Ptr<cv::FaceDetectorYN> outDetector;
	Ref<CVFaceDetectorYN> output;
	output.instantiate();

	cv::String modelIn(model.utf8());
	cv::String configIn(config.utf8());

	float score_threshold = 0.9, nms_threshold = 0.3;
	int top_k = 5000, backend_id = 0, target_id = 0;

	GET_ADITIONAL_PROPERTY(additional_parameters, score_threshold, "score_threshold", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, nms_threshold, "nms_threshold", Variant::FLOAT, "FLOAT");
	GET_ADITIONAL_PROPERTY(additional_parameters, top_k, "top_k", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, backend_id, "backend_id", Variant::INT, "INT");
	GET_ADITIONAL_PROPERTY(additional_parameters, target_id, "target_id", Variant::INT, "INT");

	outDetector = cv::FaceDetectorYN::create(modelIn, configIn,
			cv::Size(input_size.x, input_size.y), score_threshold,
			nms_threshold, top_k, backend_id, target_id);

	output->set_pointer(outDetector);

	return output;
}

Vector2 CVFaceDetectorYN::get_input_size() {
	cv::Size outVec;

	SAFE_CALL(outVec = rawDetector->getInputSize());

	Vector2 output = Vector2(outVec.width, outVec.height);

	return output;
}

float CVFaceDetectorYN::get_nms_threshold() {
	float output = false;

	SAFE_CALL(output = rawDetector->getNMSThreshold());

	return output;
}

float CVFaceDetectorYN::get_score_threshold() {
	float output = false;

	SAFE_CALL(output = rawDetector->getScoreThreshold());

	return output;
}

int CVFaceDetectorYN::get_top_k() {
	int output = false;

	SAFE_CALL(output = rawDetector->getTopK());

	return output;
}

void CVFaceDetectorYN::set_input_size(Vector2 input_size) {
	SAFE_CALL(rawDetector->setInputSize(cv::Size(input_size.x, input_size.y)));
}

void CVFaceDetectorYN::set_nms_threshold(float nms_threshold) {
	SAFE_CALL(rawDetector->setNMSThreshold(nms_threshold));
}

void CVFaceDetectorYN::set_score_threshold(float score_threshold) {
	SAFE_CALL(rawDetector->setScoreThreshold(score_threshold));
}

void CVFaceDetectorYN::set_top_k(int top_k) {
	SAFE_CALL(rawDetector->setTopK(top_k));
}

cv::Ptr<cv::FaceDetectorYN> CVFaceDetectorYN::get_pointer() {
	return rawDetector;
}

void CVFaceDetectorYN::set_pointer(cv::Ptr<cv::FaceDetectorYN> pointer) {
	rawDetector = pointer;
}

String CVFaceDetectorYN::_to_string() const {
	return "[ CVFaceDetectorYN Instance ]";
}