#include "Boss.h"

MYns::Boss::Boss()
{
	std::cout << "Вызван конструктор Boss по умолчанию\n";
	company_name = "Noname";
	wrk = nullptr;
}

MYns::Boss::Boss(std::string company_name, Worker* wrk)
{
	std::cout << "Вызван конструктор Boss\n";
	this->company_name = company_name;
	this->wrk = wrk;
}

MYns::Boss::~Boss()
{
	std::cout << "Вызван деструктор Boss\n";
}

void MYns::Boss::ShowInfo()
{
	wrk->ShowInfo();
	std::cout << "Имя компании: " << company_name << std::endl;
}
