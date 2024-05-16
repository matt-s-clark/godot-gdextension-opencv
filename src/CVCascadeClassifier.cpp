#include "CVCascadeClassifier.h"

using namespace godot;

void CVCascadeClassifier::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("detect_multi_scale",
					"image",
					"aditional_parameters"),
			&CVCascadeClassifier::detect_multi_scale);
	ClassDB::bind_method(
			D_METHOD("empty"),
			&CVCascadeClassifier::empty);
	ClassDB::bind_method(
			D_METHOD("get_feature_type"),
			&CVCascadeClassifier::get_feature_type);
	ClassDB::bind_method(
			D_METHOD("load", "filename"),
			&CVCascadeClassifier::load);
}

CVCascadeClassifier::CVCascadeClassifier() {
}

CVCascadeClassifier::~CVCascadeClassifier() {
}

Dictionary CVCascadeClassifier::detect_multi_scale(
		Ref<CVMat> image,
		Dictionary aditional_parameters) {
	Dictionary output;
	std::vector<cv::Rect> objects;

	SAFECALL(rawClassifier.detectMultiScale(image->get_mat(), objects));

	Array objectsOut;
	for (cv::Rect o : objects) {
		Ref<CVRect> oo;
		oo->set_rect(o);
		objectsOut.push_back(oo);
	}

	output["objects"] = objectsOut;
	return output;
}

bool CVCascadeClassifier::empty() const {
	bool output;

	SAFECALL(output = rawClassifier.empty());

	return output;
}

int CVCascadeClassifier::get_feature_type() const {
	int output;

	SAFECALL(output = rawClassifier.getFeatureType());

	return output;
}

bool CVCascadeClassifier::load(const String filename) {
	bool output;

	cv::String path(filename.utf8());

	SAFECALL(output = rawClassifier.load(path));

	return output;
}

String CVCascadeClassifier::_to_string() const {
	return "[ CVCascadeClassifier instance ]";
}