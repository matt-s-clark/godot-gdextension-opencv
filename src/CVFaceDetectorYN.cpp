#include "CVFaceDetectorYN.h"

using namespace godot;

void CVFaceDetectorYN::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("detect", "image"),
			&CVFaceDetectorYN::detect);
	ClassDB::bind_method(
			D_METHOD("detect_simplified", "image"),
			&CVFaceDetectorYN::detect_simplified);
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

	ERR_FAIL_NULL_V_MSG(image, output, "image should not be null.");

	SAFE_CALL(rawDetector->detect(image->get_pointer(), outMat));

	output->set_pointer(outMat);

	return output;
}

Array CVFaceDetectorYN::detect_simplified(Ref<CVMat> image) {
	Array output;

	ERR_FAIL_NULL_V_MSG(image, output, "image should not be null.");

	Ref<CVMat> mat = detect(image);
	cv::Mat outMat = mat->get_pointer();

	for (size_t i = 0; i < outMat.rows; i++) {
		Ref<CVRect> out;
		out.instantiate();
		Dictionary face;
		cv::Rect outRect = cv::Rect(
				outMat.at<float>(i, 0),
				outMat.at<float>(i, 1),
				outMat.at<float>(i, 2),
				outMat.at<float>(i, 3));

		Vector2 right_eye = Vector2(
				outMat.at<float>(i, 4),
				outMat.at<float>(i, 5));

		Vector2 left_eye = Vector2(
				outMat.at<float>(i, 6),
				outMat.at<float>(i, 7));

		Vector2 nose_tip = Vector2(
				outMat.at<float>(i, 8),
				outMat.at<float>(i, 9));

		Vector2 right_mouth = Vector2(
				outMat.at<float>(i, 10),
				outMat.at<float>(i, 11));

		Vector2 left_mouth = Vector2(
				outMat.at<float>(i, 12),
				outMat.at<float>(i, 13));

		out->set_rect(outRect);

		face["rect"] = out;
		face["right_eye"] = right_eye;
		face["left_eye"] = left_eye;
		face["nose_tip"] = nose_tip;
		face["right_mouth"] = right_mouth;
		face["left_mouth"] = left_mouth;
		face["face_score"] = outMat.at<float>(i, 14);
		face["face_mat"] = mat->row(i);

		output.push_back(face);
	}

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