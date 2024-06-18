#ifndef GDEXAMPLE_REGISTER_TYPES_H
#define GDEXAMPLE_REGISTER_TYPES_H

#include "CVCascadeClassifier.h"
#include "CVCore.h"
#include "CVDnn.h"
#include "CVFaceDetectorYN.h"
#include "CVFaceRecognizerSF.h"
#include "CVImgCodecs.h"
#include "CVImgProc.h"
#include "CVMat.h"
#include "CVNet.h"
#include "CVRect.h"
#include "CVTrackerDaSiamRPN.h"
#include "CVTrackerGOTURN.h"
//#include "CVTrackerKCF.h"
#include "CVVideoCapture.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_opencv_module(ModuleInitializationLevel p_level);
void uninitialize_opencv_module(ModuleInitializationLevel p_level);

#endif // GDEXAMPLE_REGISTER_TYPES_H