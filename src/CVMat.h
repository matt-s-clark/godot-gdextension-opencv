#ifndef GDMAT_H
#define GDMAT_H

#include "Macros.h"
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
	String _to_string() const;

public:
	CVMat();
	~CVMat();

	int channels() const;
	Ref<CVMat> col(int x);
	void convert_to(int rtype);
	Ref<CVMat> copy();
	int depth();
	Variant get_at(int row, int col);
	Ref<Image> get_image(); // <Helper>
	int get_rows();
	int get_cols();
	cv::Mat get_mat();
	void multiply(Variant value); // <Helper>
	Ref<CVMat> row(int y);
	Ref<Image> image;
	void set_at(int row, int col, Variant value);
	void set_image(Ref<Image> image); // <Helper>
	void set_read_only(int input);
	void set_mat(cv::Mat _mat);
	int type() const;

	static Ref<CVMat> eye(int rows, int cols, int type);
	static Ref<CVMat> from_image(Ref<Image> image); // <Helper>
	static Ref<CVMat> ones(int rows, int cols, int type);
	static Ref<CVMat> zeros(int rows, int cols, int type);
};

} //namespace godot

#endif