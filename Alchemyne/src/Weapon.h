#pragma once
#include "Item.h"
#include "IUsable_Weapon.h"
class Weapon : public Item, public IUsable_Weapon
{
public:
	Weapon(std::string name, std::string description, unsigned int id, unsigned int value, int weaponPower, int starRating);
	Weapon(std::string name, unsigned int id, unsigned int value, int weaponPower, int starRating);
	Weapon(std::string name, unsigned int id, unsigned int value, int weaponPower);
	Weapon(std::string name, unsigned int id, int weaponPower);
private:
	std::string description;
	float durability;
	int starRating;
};

