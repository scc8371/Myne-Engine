#include "IUsable.h"
IUsable::IUsable(int cost)
{
	alchemyCost = cost;
}

IUsable::IUsable()
	: IUsable(0) {}

void IUsable::use() {
	//nothing present here... will be different per item.
	//Does c++ have abstract methods??
}

/// <summary>
/// Changes the cost of an item
/// </summary>
/// <param name="newCost">cost that the item's cost is changed to</param>
void IUsable::changeCost(int newCost)
{
	alchemyCost = newCost;
}
