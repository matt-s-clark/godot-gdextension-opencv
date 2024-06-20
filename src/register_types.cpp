#include "register_types.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_opencv_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<CVMat>();
	ClassDB::register_class<CVRect>();
	ClassDB::register_class<CVCore>();
	ClassDB::register_class<CVImgCodecs>();
	ClassDB::register_class<CVVideoCapture>();
	ClassDB::register_class<CVCascadeClassifier>();
	ClassDB::register_class<CVImgProc>();
	ClassDB::register_class<CVFaceDetectorYN>();
	ClassDB::register_class<CVFaceRecognizerSF>();
	ClassDB::register_class<CVNet>();
	ClassDB::register_class<CVDnn>();
	ClassDB::register_class<CVTrackerDaSiamRPN>();
	ClassDB::register_class<CVTrackerGOTURN>();
	ClassDB::register_class<CVTrackerKCF>();
	ClassDB::register_class<CVTrackerCSRT>();
}

void uninitialize_opencv_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT opencv_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_opencv_module);
	init_obj.register_terminator(uninitialize_opencv_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}