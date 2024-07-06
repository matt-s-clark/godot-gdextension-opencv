#ifndef CV_FILESTORAGE_H
#define CV_FILESTORAGE_H

#include "CVFileNode.h"
#include "CVMat.h"
#include "Macros.h"
#include <stdio.h>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <opencv2/core.hpp>

namespace godot {

class CVFileStorage : public RefCounted {
	GDCLASS(CVFileStorage, RefCounted)

private:
	cv::FileStorage rawFile;

protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVFileStorage();
	~CVFileStorage();

	bool isOpened() const;
	bool open(String filename, int flags, Dictionary additional_parameters);
	Variant read(const String name);
	void release();
	//Ref<CVFileNode> root(Dictionary additional_parameters);
	void write(const String name, Variant val);

	cv::FileStorage get_file();
	void set_file(cv::FileStorage value);
};

} //namespace godot

#endif