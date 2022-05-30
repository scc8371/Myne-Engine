#include "IDamageable.h"

/// <summary>
/// Creates a damageable object
/// </summary>
/// <param name="health">amount of health</param>
IDamageable::IDamageable(int health)
{
	this->health = health;
	active = true;
}

/// <summary>
/// simulates something taking damage
/// </summary>
/// <param name="amt">amount of damage</param>
void IDamageable::takeDamage(int amt)
{
	if (active) {
		health -= amt;
		remainActive();
	}	
}

/// <summary>
/// checks if an entity remains active after taking damage
/// </summary>
void IDamageable::remainActive()
{
	if (health <= 0) {
		active = false;
	}
}

/// <summary>
/// returns if the player is active or not
/// </summary>
/// <returns>true = active; false = inactive</returns>
bool IDamageable::isActive()
{
	return active;
}

