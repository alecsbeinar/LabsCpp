#include "Workplace.h"

MYns::Workplace::Workplace()
{
	std::cout << "������ ����������� Workpalce �� ���������\n";
	name_workplace = "no_workplace";
}

MYns::Workplace::Workplace(std::string name_workplace)
{
	std::cout << "������ ����������� Workplace\n";
	this->name_workplace = name_workplace;
}

MYns::Workplace::~Workplace()
{
	std::cout << "������ ���������� Workplace\n";
}

std::string MYns::Workplace::GetName()
{
	return name_workplace;
}
