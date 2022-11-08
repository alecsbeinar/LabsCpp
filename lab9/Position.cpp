#include "Position.h"

MYns::Position::Position()
{
	std::cout << "Вызван конструктор Position по умолчанию\n";
	name_position = "no_position";
}

MYns::Position::Position(std::string name_position)
{
	std::cout << "Вызван конструктор Position\n";
	this->name_position = name_position;
}

MYns::Position::~Position()
{
	std::cout << "Вызван деструктор Position\n";
}

std::string MYns::Position::GetName()
{
	return name_position;
}
