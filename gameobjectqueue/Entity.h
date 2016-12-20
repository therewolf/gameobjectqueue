#pragma once

#include "Object.h"

class Entity : public Object
{
public:
	Entity(const std::string& objID, const int& state);
	virtual ~Entity();

	void Update() override;
	const int& getState() override;

private:
	int state_;
};