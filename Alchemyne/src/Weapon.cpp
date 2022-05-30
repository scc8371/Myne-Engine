#include "Weapon.h"

Weapon::Weapon(std::string name, std::string description, unsigned int id, unsigned int value, int weaponPower, int starRating)
	: Item(name, id, value, description), IUsable_Weapon(weaponPower)
{
	this->starRating = starRating;
	durability = 100.0f;
	type = EntityType::Weapon;
}

Weapon::Weapon(std::string name, unsigned int id, unsigned int value, int weaponPower)
	: Weapon(name, "", id, value, weaponPower, 1) {}

Weapon::Weapon(std::string name, unsigned int id, int weaponPower)
	: Weapon(name, "", id, 0, weaponPower, 1) {}

