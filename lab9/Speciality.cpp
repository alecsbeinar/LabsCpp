#include "Speciality.h"

MYns::Speciality::Speciality()
{
	std::cout << "������ ����������� Speciality �� ���������\n";
	name_speciality = "no_spec";
}

MYns::Speciality::Speciality(std::string name_speciality)
{
	std::cout << "������ ����������� Speciality\n";
	this->name_speciality = name_speciality;
}

MYns::Speciality::~Speciality()
{
	std::cout << "������ ���������� Speciality\n";
}

std::string MYns::Speciality::GetName()
{
	return name_speciality;
}
