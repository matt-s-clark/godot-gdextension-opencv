#ifndef CV_HELPERFUNCTIONS_H
#define CV_HELPERFUNCTIONS_H

#include "CVMat.h"
#include <stdio.h>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>

using namespace cv;
using namespace godot;

class HelperFunctions {
public:
	HelperFunctions();
	~HelperFunctions();

	static Scalar convertScalar(Color input);
	static Point convertPoint(Vector2 input);
	static Point2f convertPoint2f(Vector2 input);
	static Size convertSize(Vector2 input);
};

#endif