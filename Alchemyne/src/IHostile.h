#pragma once
#include "IDamageable.h"
class IHostile
{
public:
	IHostile(int attack);
	virtual void attackEntity(IDamageable entity);
protected:
	int attack;
};

