#include "CVCascadeClassifier.h"

using namespace godot;

void CVCascadeClassifier::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("detect_multi_scale",
					"image",
					"additional_parameters"),
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
		Dictionary additional_parameters) {
	Dictionary output;
	std::vector<cv::Rect> objects;
	std::vector<int> numDetections, rejectLevels;
	std::vector<double> levelWeights;
	double scaleFactor = 1.1;
	int minNeighbors = 3, flags = 0;
	Vector2 minSize = Vector2(-1, -1), maxSize = Vector2(-1, -1);
	cv::Size minSizeSize = cv::Size(), maxSizeSize = cv::Size();
	bool outputRejectLevels = false;

	GETADITIONALPROPERTY(additional_parameters, scaleFactor, "scale_factor", Variant::FLOAT, "FLOAT");
	GETADITIONALPROPERTY(additional_parameters, minNeighbors, "min_neighbors", Variant::INT, "INT");
	GETADITIONALPROPERTY(additional_parameters, flags, "flags", Variant::INT, "INT");
	GETADITIONALPROPERTY(additional_parameters, minSize, "min_size", Variant::VECTOR2, "VECTOR2");
	GETADITIONALPROPERTY(additional_parameters, maxSize, "max_size", Variant::VECTOR2, "VECTOR2");
	GETADITIONALPROPERTY(additional_parameters, outputRejectLevels, "output_reject_levels", Variant::BOOL, "Bool");

	if (minSize.x >= 0 && minSize.y >= 0) {
		minSizeSize = cv::Size(minSize.x, minSize.y);
	} else if (!(minSize.x == -1 && minSize.y == -1)) {
		UtilityFunctions::push_warning("min_size expected to have positive values, ignoring property");
	}

	if (maxSize.x >= 0 && maxSize.y >= 0) {
		maxSizeSize = cv::Size(maxSize.x, maxSize.y);
	} else if (!(maxSize.x == -1 && maxSize.y == -1)) {
		UtilityFunctions::push_warning("max_size expected to have positive values, ignoring property");
	}

	if (outputRejectLevels) {
		SAFECALL(rawClassifier.detectMultiScale(
				image->get_mat(),
				objects,
				rejectLevels,
				levelWeights,
				scaleFactor,
				minNeighbors,
				flags,
				minSizeSize,
				maxSizeSize,
				outputRejectLevels));
	} else {
		SAFECALL(rawClassifier.detectMultiScale(
				image->get_mat(),
				objects,
				numDetections,
				scaleFactor,
				minNeighbors,
				flags,
				minSizeSize,
				maxSizeSize));
	}

	Array objectsOut;
	for (cv::Rect obj : objects) {
		Ref<CVRect> tempRect;
		tempRect.instantiate();
		tempRect->set_rect(obj);
		objectsOut.push_back(tempRect);
	}

	if (outputRejectLevels) {
		Array rejectLevelsOut;
		for (int rl : rejectLevels) {
			rejectLevelsOut.push_back(rl);
		}

		output["reject_levels"] = rejectLevelsOut;

		Array levelWeightsOut;
		for (float lw : levelWeights) {
			levelWeightsOut.push_back(lw);
		}

		output["level_weights"] = levelWeightsOut;
	} else {
		Array numDetectionsOut;
		for (int nd : numDetections) {
			numDetectionsOut.push_back(nd);
		}

		output["num_detections"] = numDetectionsOut;
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