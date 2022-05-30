#pragma once
#include "LivingEntity.h"
class Player : public LivingEntity
{
public:
	Player(std::string name, int health, int attack);
	//attack will be implemented after attack options are available for the player!
	//other attack methods will be created in the future as well. for now, it is just the base method for testing.
	void attackEntity(IDamageable enemy) override;
	void takeDamage(int amt) override;

private: 
	int totalAlchemyPoints;
	int currentAlchemyPoints;
	//inventory of resources
};

