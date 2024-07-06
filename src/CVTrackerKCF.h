#ifndef CVTRACKERKCF_H
#define CVTRACKERKCF_H

#include "CVMat.h"
#include "CVRect.h"
#include "Macros.h"
#include <godot_cpp/classes/image_texture.hpp>
#include <opencv2/core.hpp>
#include <opencv2/tracking.hpp>

namespace godot {

class CVTrackerKCF : public RefCounted {
	GDCLASS(CVTrackerKCF, RefCounted)

private:
	cv::Ptr<cv::TrackerKCF> rawTracker;

protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVTrackerKCF();
	~CVTrackerKCF();

	void init(Ref<CVMat> image, Ref<CVRect> boundingBox);
	Ref<CVRect> update(Ref<CVMat> image);

	static Ref<CVTrackerKCF> create(Dictionary additional_parameters);

	cv::Ptr<cv::TrackerKCF> get_pointer();
	void set_pointer(cv::Ptr<cv::TrackerKCF> value);
};

} //namespace godot

#endif