#include "Player.h"

Player::Player(std::string name, int health, int attack)
	: LivingEntity(name, health, attack)
{
	currentAlchemyPoints = 0;
	totalAlchemyPoints = 100;
	type = EntityType::Player;

	//probably a vector inventory of resources will go here.
}

/// <summary>
/// attacks another entity using one of the player's options
/// </summary>
/// <param name="enemy">enemy that is attacked</param>
void Player::attackEntity(IDamageable enemy)
{
	//temp
	IHostile::attackEntity(enemy);

	//Idea -- probably make this a private method, and another that specifies how many enemies are being attacked.
}

/// <summary>
/// player takes damage
/// </summary>
/// <param name="amt">amount of damage taken</param>
void Player::takeDamage(int amt)
{
	IDamageable::takeDamage(amt);
}
