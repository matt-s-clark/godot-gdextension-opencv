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
	std::vector<int> numDetections, rejectLevels;
	std::vector<double> levelWeights;
	cv::Mat mat;
	double scaleFactor = 1.1;
	int minNeighbors = 3, flags = 0;
	cv::Size minSize = cv::Size(), maxSize = cv::Size();
	bool outputRejectLevels = false;

	if (aditional_parameters.has("scale_factor")) {
		if (aditional_parameters["scale_factor"].get_type() == Variant::Type::FLOAT) {
			scaleFactor = aditional_parameters["scale_factor"];
		} else {
			UtilityFunctions::push_warning("scale_factor expected to be of type FLOAT, ignoring property");
		}
	}

	if (aditional_parameters.has("min_neighbors")) {
		if (aditional_parameters["min_neighbors"].get_type() == Variant::Type::INT) {
			minNeighbors = aditional_parameters["min_neighbors"];
		} else {
			UtilityFunctions::push_warning("min_neighbors expected to be of type INT, ignoring property");
		}
	}

	if (aditional_parameters.has("flags")) {
		if (aditional_parameters["flags"].get_type() == Variant::Type::INT) {
			flags = aditional_parameters["flags"];
		} else {
			UtilityFunctions::push_warning("flags expected to be of type INT, ignoring property");
		}
	}

	if (aditional_parameters.has("min_size")) {
		if (aditional_parameters["min_size"].get_type() == Variant::Type::VECTOR2) {
			Vector2 temp = aditional_parameters["min_size"];
			minSize = cv::Size(temp.x, temp.y);
		} else {
			UtilityFunctions::push_warning("min_size expected to be of type VECTOR2, ignoring property");
		}
	}

	if (aditional_parameters.has("max_size")) {
		if (aditional_parameters["max_size"].get_type() == Variant::Type::VECTOR2) {
			Vector2 temp = aditional_parameters["max_size"];
			maxSize = cv::Size(temp.x, temp.y);
		} else {
			UtilityFunctions::push_warning("max_size expected to be of type VECTOR2, ignoring property");
		}
	}

	if (aditional_parameters.has("output_reject_levels")) {
		if (aditional_parameters["output_reject_levels"].get_type() == Variant::Type::BOOL) {
			outputRejectLevels = aditional_parameters["output_reject_levels"];
		} else {
			UtilityFunctions::push_warning("output_reject_levels expected to be of type BOOL, ignoring property");
		}
	}

	SAFECALL(cv::cvtColor(image->get_mat(), mat, cv::COLOR_BGR2GRAY));
	SAFECALL(cv::equalizeHist(mat, mat));

	if (outputRejectLevels) {
		SAFECALL(rawClassifier.detectMultiScale(mat,
				objects,
				rejectLevels,
				levelWeights,
				scaleFactor,
				minNeighbors,
				flags,
				minSize,
				maxSize,
				outputRejectLevels));
	} else {
		SAFECALL(rawClassifier.detectMultiScale(mat,
				objects,
				numDetections,
				scaleFactor,
				minNeighbors,
				flags,
				minSize,
				maxSize));
	}

	Array objectsOut;
	for (cv::Rect obj : objects) {
		Ref<CVRect> tempRect;
		tempRect.instantiate();
		tempRect->set_rect(obj);
		objectsOut.push_back(tempRect);

		cv::Mat temp = image->get_mat();
		cv::rectangle(temp, obj, cv::Scalar(0, 255, 0));
		image->set_mat(temp);
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