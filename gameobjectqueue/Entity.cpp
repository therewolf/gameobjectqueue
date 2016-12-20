#include "Entity.h"

Entity::Entity(const std::string& objID, const int& state) :
		Object(objID), state_(state) {}

Entity::~Entity() {}

// Update performing "game logic"
void Entity::Update() { ++this->state_; }

const int& Entity::getState() { return state_; }