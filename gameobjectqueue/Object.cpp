#include"Object.h"

#include<string>

Object::Object(const std::string& objID) :
	objID_(objID) {}

Object::~Object() {}

const std::string& Object::getName() { return objID_; }