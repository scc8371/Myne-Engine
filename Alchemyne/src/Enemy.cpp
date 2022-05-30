#include "Enemy.h"
#include <math.h>

Enemy::Enemy(std::string name, int health, int attack, std::string ability)
	: LivingEntity(name, health, attack)
{
	this->ability = ability;
	type = EntityType::Enemy;
}

/// <summary>
/// combines the health and attack of two enemies, replaces the ability of the target.
/// </summary>
/// <param name="other">other enemy to fuse</param>
void Enemy::combine(Enemy* other)
{
	this->health = (this->health + other->health) / 2;
	this->attack = (this->attack + other->attack) / 2;

	this->ability = other->ability;

	delete other;
	other = nullptr;

	//delete other enemy from enemy list here, probably.
}
