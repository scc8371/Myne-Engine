#include "IHostile.h"

IHostile::IHostile(int attack)
{
	this->attack = attack;
}
/// <summary>
/// attacks another entity that can be damaged
/// </summary>
/// <param name="entity">damageable entity</param>
void IHostile::attackEntity(IDamageable entity)
{
	entity.takeDamage(attack);
}
