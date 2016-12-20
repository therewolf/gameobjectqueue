#pragma once

#include<string>

class Object
{
public:
	Object(const std::string& objID);
	virtual ~Object();

	virtual void Update() = 0;

	const std::string& getName();
	virtual const int& getState() = 0;

private:
	std::string objID_;
};
