#pragma once
#include "Entity.h"
#include "IDamageable.h"
#include "IHostile.h"
class LivingEntity : public Entity, public IDamageable, public IHostile
{
public:
	LivingEntity(std::string name, int health, int damage);
};

