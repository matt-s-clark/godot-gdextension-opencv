#ifndef CVTRACKERGOTURN_H
#define CVTRACKERGOTURN_H

#include "CVMat.h"
#include "CVRect.h"
#include "Macros.h"
#include <godot_cpp/classes/image_texture.hpp>
#include <opencv2/core.hpp>
#include <opencv2/video/tracking.hpp>

namespace godot {

class CVTrackerGOTURN : public RefCounted {
	GDCLASS(CVTrackerGOTURN, RefCounted)

private:
	cv::Ptr<cv::TrackerGOTURN> rawTracker;

protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVTrackerGOTURN();
	~CVTrackerGOTURN();

	void init(Ref<CVMat> image, Ref<CVRect> boundingBox);
	Ref<CVRect> update(Ref<CVMat> image);

	static Ref<CVTrackerGOTURN> create(Dictionary additional_parameters);

	cv::Ptr<cv::TrackerGOTURN>  get_pointer();
	void set_pointer(cv::Ptr<cv::TrackerGOTURN>  value);
};

} //namespace godot

#endif