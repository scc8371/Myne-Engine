#pragma once
#include "LivingEntity.h"

class Enemy : public virtual LivingEntity
{
public:
	Enemy(std::string name, int health, int attack, std::string ability);
	void combine(Enemy* other);
private:
	//ability goes here!
	std::string ability;
};

