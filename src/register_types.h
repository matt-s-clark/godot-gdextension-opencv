#ifndef GDEXAMPLE_REGISTER_TYPES_H
#define GDEXAMPLE_REGISTER_TYPES_H

#include "CVArucoHelper.h"
#include "CVCore.h"
#include "CVImgCodecs.h"
#include "CVMat.h"
#include "CVVideoCapture.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_opencv_module(ModuleInitializationLevel p_level);
void uninitialize_opencv_module(ModuleInitializationLevel p_level);

#endif // GDEXAMPLE_REGISTER_TYPES_H