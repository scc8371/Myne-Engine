#include "Material.h"

Material::Material(std::string name, std::string description, int cost, int id, int value)
	: Item(name, id, value, description), IUsable(cost) {
	type = EntityType::Material;
}

Material::Material(std::string name, int cost, int id, int value)
	: Item(name, id, value), IUsable(cost) {
	type = EntityType::Material;
}

void Material::combine(Item combinationItem)
{
	//combination will be implemented when I get to that section of the combat section...
	//this MAY want to be implemeneted in a manager of some sort, maybe an inventory manager?
}
