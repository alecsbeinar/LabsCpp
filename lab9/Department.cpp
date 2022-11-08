#include "Department.h"

MYns::Department::Department()
{
	std::cout << "������ ����������� Department �� ���������\n";
}

MYns::Department::Department(std::vector<Worker*> workers)
{
	std::cout << "������ ����������� Department\n";
	this->workers = workers;
}

MYns::Department::~Department()
{
	std::cout << "������ ���������� Department\n";
}

std::vector<MYns::Worker*> MYns::Department::GetWorkers()
{
	return workers;
}
