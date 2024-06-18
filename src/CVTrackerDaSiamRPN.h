#ifndef CVTRACKERDASIAMRPN_H
#define CVTRACKERDASIAMRPN_H

#include "CVMat.h"
#include "CVRect.h"
#include "Macros.h"
#include <godot_cpp/classes/image_texture.hpp>
#include <opencv2/core.hpp>
#include <opencv2/video/tracking.hpp>

namespace godot {

class CVTrackerDaSiamRPN : public RefCounted {
	GDCLASS(CVTrackerDaSiamRPN, RefCounted)

private:
	cv::Ptr<cv::TrackerDaSiamRPN> rawTracker;

protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVTrackerDaSiamRPN();
	~CVTrackerDaSiamRPN();

	void init(Ref<CVMat> image, Ref<CVRect> boundingBox);
	Ref<CVRect> update(Ref<CVMat> image);

	static Ref<CVTrackerDaSiamRPN> create(Dictionary additional_parameters);

	cv::Ptr<cv::TrackerDaSiamRPN>  get_pointer();
	void set_pointer(cv::Ptr<cv::TrackerDaSiamRPN>  value);
};

} //namespace godot

#endif