#pragma once
#include "Entity.h"
#include "IDescription.h"
class Item : public Entity, public IDescription
{
public:
	Item(std::string name, unsigned int id, unsigned int value, std::string description);
	Item(std::string name, unsigned int id, unsigned int value);
	Item(std::string name, unsigned int id);
private:
	unsigned int id;
	unsigned int value;
};

