#include "Entity.h"
Entity::Entity(std::string name)
{
	this->name = name;
	this->type = EntityType::Player;
}

EntityType Entity::getType()
{
	return type;
}
