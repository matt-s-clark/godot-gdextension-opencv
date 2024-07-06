#include "CVFileStorage.h"

using namespace godot;

void CVFileStorage::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("write", "name", "val"),
			&CVFileStorage::write);
	ClassDB::bind_method(
			D_METHOD("isOpened"),
			&CVFileStorage::isOpened);
	ClassDB::bind_method(
			D_METHOD("open", "filename", "flags", "additional_parameters"),
			&CVFileStorage::open);
	ClassDB::bind_method(
			D_METHOD("release"),
			&CVFileStorage::release);
	ClassDB::bind_method(
			D_METHOD("read", "name"),
			&CVFileStorage::read);
}

CVFileStorage::CVFileStorage() {
}

CVFileStorage::~CVFileStorage() {
}

bool CVFileStorage::isOpened() const {
	bool output;

	SAFE_CALL(output = rawFile.isOpened());

	return output;
}

bool CVFileStorage::open(String filename, int flags, Dictionary additional_parameters) {
	bool output;

	String encoding = "";
	cv::String encodingIn = cv::String();
	cv::String filenameIn(filename.utf8());

	GET_ADITIONAL_PROPERTY(additional_parameters, encoding, "encoding", Variant::STRING, "STRING");

	if (encoding != "") {
		cv::String tmp(encoding.utf8());
		encodingIn = tmp;
	}

	SAFE_CALL(output = rawFile.open(filenameIn, flags, encodingIn));

	return output;
}

void CVFileStorage::release() {
	SAFE_CALL(rawFile.release());
}

void CVFileStorage::write(const String name, Variant val) {
	cv::String nameIn(name.utf8());
	cv::String valIn(((String)val).utf8());

	Ref<CVMat> mat = Ref<CVMat>(val);

	switch (val.get_type()) {
		case Variant::INT:
			rawFile.write(nameIn, (int)val);
			break;
		case Variant::FLOAT:
			rawFile.write(nameIn, (float)val);
			break;
		case Variant::STRING:
			rawFile.write(nameIn, valIn);
			break;
		case Variant::OBJECT:
			if (!mat.is_null()) {
				rawFile.write(nameIn, mat->get_mat());
			} else {
				UtilityFunctions::printerr("Type not supported");
			}
			break;
		default:
			UtilityFunctions::printerr("Type not supported");
			break;
	}
}

Variant CVFileStorage::read(const String name) {
	Variant output;
	cv::String nameIn(name.utf8());
	cv::FileNode filenode = rawFile[nameIn];

	int tmpInt;
	float tmpFloat;
	cv::String tmpStr;
	Ref<CVMat> tmpMat;
	tmpMat.instantiate();

	switch (filenode.type()) {
		case cv::FileNode::NONE:
		case cv::FileNode::EMPTY:
			break;
		case cv::FileNode::INT:
			filenode >> tmpInt;
			output = tmpInt;
			break;
		case cv::FileNode::FLOAT:
			filenode >> tmpFloat;
			output = tmpFloat;
			break;
		case cv::FileNode::STRING:
			filenode >> tmpStr;
			output = tmpStr.c_str();
			break;
		case cv::FileNode::MAP:
			tmpMat->set_mat(filenode.mat());
			output = tmpMat;
			break;
		default:
			UtilityFunctions::print(filenode.type());
			UtilityFunctions::printerr("Type not supported");
			break;
	}

	return output;
}

/*
Ref<CVFileNode> CVFileStorage::root(Dictionary additional_parameters) {
	return Ref<CVFileNode>();
}
*/

cv::FileStorage CVFileStorage::get_file() {
	return rawFile;
}

void CVFileStorage::set_file(cv::FileStorage value) {
	rawFile = value;
}

String CVFileStorage::_to_string() const {
	return UtilityFunctions::str("[ CVFileStorage instance ]");
}
