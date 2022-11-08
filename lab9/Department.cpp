#include "Department.h"

MYns::Department::Department()
{
	std::cout << "Вызван конструктор Department по умолчанию\n";
}

MYns::Department::Department(std::vector<Worker*> workers)
{
	std::cout << "Вызван конструктор Department\n";
	this->workers = workers;
}

MYns::Department::~Department()
{
	std::cout << "Вызван деструктор Department\n";
}

std::vector<MYns::Worker*> MYns::Department::GetWorkers()
{
	return workers;
}
