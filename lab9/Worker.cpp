#include "Worker.h"
using namespace MYns;

Worker::Worker()
{
	std::cout << "������ ����������� Worker �� ���������\n";
	salary = 0;
	sp = nullptr;
	pos = nullptr;
	wpl = nullptr;
}

Worker::Worker(double salary, std::string name, int age, Speciality* sp, Position* pos, Workplace* wpl) : Human::Human(name, age)
{
	std::cout << "������ ����������� Worker\n";
	this->salary = salary;
	this->sp = sp;
	this->pos = pos;
	this->wpl = wpl;
}

Worker::~Worker()
{
	std::cout << "������ ���������� Worker\n";
}

void Worker::ShowInfo()
{
	Human::ShowInfo();
	std::cout << "��������: " << salary << std::endl;
	std::cout << "�������������: " << sp->GetName() << std::endl;
	std::cout << "���������: " << pos->GetName() << std::endl;
	std::cout << "������� �����: " << wpl->GetName() << std::endl;
}

double MYns::Worker::GetSalary()
{
	return salary;
}

Speciality* MYns::Worker::GetSp()
{
	return sp;
}

Position* MYns::Worker::GetPos()
{
	return pos;
}

Workplace* MYns::Worker::GetWpl()
{
	return wpl;
}
