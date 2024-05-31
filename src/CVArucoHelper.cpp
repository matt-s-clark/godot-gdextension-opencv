#include "CVArucoHelper.h"

using namespace godot;

void CVArucoHelper::_bind_methods() {
	ClassDB::bind_static_method(get_class_static(), D_METHOD("getMarkerPosition"), &CVArucoHelper::getMarkerPosition);
}

CVArucoHelper::CVArucoHelper() {
}

CVArucoHelper::~CVArucoHelper() {
}

Array CVArucoHelper::getMarkerPosition() {
	cv::Mat img = cv::imread("aruco-capture.png", cv::IMREAD_COLOR);

	std::vector<int> markerIds;
	std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;
	cv::aruco::DetectorParameters detectorParams = cv::aruco::DetectorParameters();
	cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
	cv::aruco::ArucoDetector detector(dictionary, detectorParams);
	detector.detectMarkers(img, markerCorners, markerIds, rejectedCandidates);

	Array gdMarkerArray = Array();

	for (int i = 0; i < markerCorners.size(); i++) {
		Vector2 marker = Vector2();
		marker.x = markerCorners[i][0].x;
		marker.y = markerCorners[i][0].y;

		gdMarkerArray.append(marker);
		for (int j = 0; j < markerCorners[i].size(); j++) {
			UtilityFunctions::print("Marker [", i, ",", j, "] - ", markerCorners[i][j].x, ", ", markerCorners[i][j].y);
		}
	}

	return gdMarkerArray;
}