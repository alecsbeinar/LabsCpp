#include "Worker.h"
using namespace MYns;

Worker::Worker()
{
	std::cout << "Вызван конструктор Worker по умолчанию\n";
	salary = 0;
	sp = nullptr;
	pos = nullptr;
	wpl = nullptr;
}

Worker::Worker(double salary, std::string name, int age, Speciality* sp, Position* pos, Workplace* wpl) : Human::Human(name, age)
{
	std::cout << "Вызван конструктор Worker\n";
	this->salary = salary;
	this->sp = sp;
	this->pos = pos;
	this->wpl = wpl;
}

Worker::~Worker()
{
	std::cout << "Вызван деструктор Worker\n";
}

void Worker::ShowInfo()
{
	Human::ShowInfo();
	std::cout << "Зарплата: " << salary << std::endl;
	std::cout << "Специальность: " << sp->GetName() << std::endl;
	std::cout << "Должность: " << pos->GetName() << std::endl;
	std::cout << "Рабочее место: " << wpl->GetName() << std::endl;
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
