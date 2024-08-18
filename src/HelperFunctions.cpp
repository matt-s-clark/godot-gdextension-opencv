#include "HelperFunctions.h"
 
using namespace cv;
using namespace godot;

HelperFunctions::HelperFunctions() {
}

HelperFunctions::~HelperFunctions() {
}

Scalar HelperFunctions::convertScalar(Color input) {
	return Scalar(input.b, input.g, input.r);
}

Point HelperFunctions::convertPoint(Vector2 input) {
	return Point(input.x, input.y);
}

Point2f HelperFunctions::convertPoint2f(Vector2 input) {
	return Point2f(input.x, input.y);
}

Size HelperFunctions::convertSize(Vector2 input) {
	return Size(input.width, input.height);
}