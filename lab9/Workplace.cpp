#include "Workplace.h"

MYns::Workplace::Workplace()
{
	std::cout << "Вызван конструктор Workpalce по умолчанию\n";
	name_workplace = "no_workplace";
}

MYns::Workplace::Workplace(std::string name_workplace)
{
	std::cout << "Вызван конструктор Workplace\n";
	this->name_workplace = name_workplace;
}

MYns::Workplace::~Workplace()
{
	std::cout << "Вызван деструктор Workplace\n";
}

std::string MYns::Workplace::GetName()
{
	return name_workplace;
}
