#include "IDescription.h"

IDescription::IDescription()
{
	description = "";
}

IDescription::IDescription(std::string description)
{
	this->description = description;
}

void IDescription::setDescription(std::string description)
{
	this->description = description;
}

void IDescription::printDescription()
{
	//will eventually print descriptions when graphical elements are functional.
}
