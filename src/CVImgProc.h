#ifndef CV_IMGPROC_H
#define CV_IMGPROC_H

#include "CVMat.h"
#include "CVRect.h"
#include "Macros.h"
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

namespace godot {

class CVImgProc : public Object {
	GDCLASS(CVImgProc, Object)

private:
protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVImgProc();
	~CVImgProc();

	static Ref<CVMat> cvt_color(Ref<CVMat> src, int code, int dstCn);
	static Ref<CVMat> equalize_hist(Ref<CVMat> src);
	static void rectangle(Ref<CVMat> img, Dictionary aditional_parameters);
};

} //namespace godot

#endif