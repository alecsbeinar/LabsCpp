#include "Position.h"

MYns::Position::Position()
{
	std::cout << "������ ����������� Position �� ���������\n";
	name_position = "no_position";
}

MYns::Position::Position(std::string name_position)
{
	std::cout << "������ ����������� Position\n";
	this->name_position = name_position;
}

MYns::Position::~Position()
{
	std::cout << "������ ���������� Position\n";
}

std::string MYns::Position::GetName()
{
	return name_position;
}
