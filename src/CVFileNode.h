#ifndef CV_FILENODE_H
#define CV_FILENODE_H

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

class CVFileNode : public RefCounted {
	GDCLASS(CVFileNode, RefCounted)

private:
	cv::FileNode rawNode;

protected:
	static void _bind_methods();
	String _to_string() const;

public:
	CVFileNode();
	~CVFileNode();

	bool empty() const;
	Variant read();
	void write(Variant val);

	cv::FileNode get_node();
	void set_node(cv::FileNode value);
};

} //namespace godot

#endif