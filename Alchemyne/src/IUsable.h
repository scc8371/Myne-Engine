#pragma once
class IUsable
{
public:
	IUsable(int cost);
	IUsable();
	virtual void use();
	virtual void changeCost(int newCost);
protected:
	int alchemyCost;

};

