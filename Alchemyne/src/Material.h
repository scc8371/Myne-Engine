#pragma once
#include "IUsable.h"
#include "Item.h"
class Material : public IUsable, public Item
{
public:
	Material(std::string name, std::string description, int cost, int id, int value);
	Material(std::string name, int cost, int id, int value);
	void combine(Item combinationItem);
};

