#include "CVFileNode.h"

using namespace godot;

void CVFileNode::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("empty"),
			&CVFileNode::empty);
	ClassDB::bind_method(
			D_METHOD("read"),
			&CVFileNode::read);
	ClassDB::bind_method(
			D_METHOD("write", "val"),
			&CVFileNode::write);
}

CVFileNode::CVFileNode() {
}

CVFileNode::~CVFileNode() {
}

bool CVFileNode::empty() const {
	bool output;

	SAFE_CALL(output = rawNode.empty());

	return output;
}

Variant CVFileNode::read() {
	Variant output;

	Ref<CVMat> tmpMat;
	tmpMat.instantiate();

	switch (rawNode.type()) {
		case cv::FileNode::NONE:
			break;
		case cv::FileNode::INT:
		case cv::FileNode::FLOAT:
			output = rawNode.real();
			break;
		case cv::FileNode::STR:
			output = rawNode.string().c_str();
			break;
		case cv::FileNode::MAP:
			tmpMat->set_mat(rawNode.mat()); // Fix: There are other maps.
			output = tmpMat;
			break;
		default:
			UtilityFunctions::printerr("Not implemented: ", rawNode.type());
			break;
	}

	return output;
}

void CVFileNode::write(Variant val) {

	cv::String valIn(((String)val).utf8());
	
	switch (val.get_type()) {
		case cv::FileNode::NONE:
			break;
		case Variant::INT:
			rawNode << (int)val;
			break;
		/*case Variant::FLOAT:
			rawNode << (float)val;
			break;
		case Variant::STRING:
			rawNode << valIn;
			break;

			Fix: write other types.
			*/
		default:
			UtilityFunctions::printerr("Not implemented: ", val.get_type());
			break;
	}
}

cv::FileNode CVFileNode::get_node() {
	return rawNode;
}

void CVFileNode::set_node(cv::FileNode value) {
	rawNode = value;
}

String CVFileNode::_to_string() const {
	return UtilityFunctions::str("[ CVFileNode instance ]");
}
