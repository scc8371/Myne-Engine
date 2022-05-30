#include "LivingEntity.h"

LivingEntity::LivingEntity(std::string name, int health, int damage)
	: Entity(name), IDamageable(health), IHostile(damage) {}
