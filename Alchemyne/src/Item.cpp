#include "Item.h"

Item::Item(std::string name, unsigned int id, unsigned int value, std::string description)
	:Entity(name), IDescription(description)
{
	this->id = id;
	this->value = value;
}

Item::Item(std::string name, unsigned int id, unsigned int value)
	: Entity(name)
{
	this->id = id;
	this->value = value;
}

Item::Item(std::string name, unsigned int id)
	: Item(name, id, 0) {}
