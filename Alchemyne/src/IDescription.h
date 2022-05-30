#pragma once
#include <string>
class IDescription
{
public:
	IDescription();
	IDescription(std::string description);
	void setDescription(std::string description);
	void printDescription();

private:
	std::string description;
};

