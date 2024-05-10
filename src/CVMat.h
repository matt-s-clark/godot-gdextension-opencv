#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/image_texture.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

namespace godot {

class CVMat : public RefCounted {
	GDCLASS(CVMat, RefCounted)

private:
	cv::Mat rawMat;

protected:
	static void _bind_methods();

public:
	CVMat();
	~CVMat();

	Ref<Image> image;
	Ref<Image> get_image();

	int get_rows();
	int get_cols();

	cv::Mat get_mat();
	void set_mat(cv::Mat _mat);

	void convert_to(int rtype);
};

} //namespace godot

#endif