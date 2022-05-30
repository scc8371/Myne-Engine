#pragma once
#include <string>
enum class EntityType {Player, Enemy, Material, Weapon, Tool};
class Entity
{
public:
	Entity(std::string name);
	EntityType getType();
protected:
	std::string name;
	EntityType type;
};

