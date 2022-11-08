#include "Speciality.h"

MYns::Speciality::Speciality()
{
	std::cout << "Вызван конструктор Speciality по умолчанию\n";
	name_speciality = "no_spec";
}

MYns::Speciality::Speciality(std::string name_speciality)
{
	std::cout << "Вызван конструктор Speciality\n";
	this->name_speciality = name_speciality;
}

MYns::Speciality::~Speciality()
{
	std::cout << "Вызван деструктор Speciality\n";
}

std::string MYns::Speciality::GetName()
{
	return name_speciality;
}
