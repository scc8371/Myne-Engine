#pragma once
class IDamageable
{
public:
	IDamageable(int health);
	virtual void takeDamage(int amt);
	void remainActive();
	bool isActive();

protected:
	int health; 
	bool active;
};

