#ifndef CVTRACKERCSRT_H
#define CVTRACKERCSRT_H

#include "CVMat.h"
#include "CVRect.h"
#include "Macros.h"
#include <godot_cpp/classes/image_texture.hpp>
#include <opencv2/core.hpp>
#include <opencv2/tracking.hpp>

namespace godot {

class CVTrackerCSRT : public RefCounted {
	GDCLASS(CVTrackerCSRT, RefCounted)

private:
	cv::Ptr<cv::TrackerCSRT> rawTracker;

protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVTrackerCSRT();
	~CVTrackerCSRT();

	void init(Ref<CVMat> image, Ref<CVRect> boundingBox);
	Ref<CVRect> update(Ref<CVMat> image);

	static Ref<CVTrackerCSRT> create(Dictionary additional_parameters);

	cv::Ptr<cv::TrackerCSRT> get_pointer();
	void set_pointer(cv::Ptr<cv::TrackerCSRT> value);
};

} //namespace godot

#endif