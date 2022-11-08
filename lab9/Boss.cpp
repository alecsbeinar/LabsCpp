#include "Boss.h"

MYns::Boss::Boss()
{
	std::cout << "������ ����������� Boss �� ���������\n";
	company_name = "Noname";
	wrk = nullptr;
}

MYns::Boss::Boss(std::string company_name, Worker* wrk)
{
	std::cout << "������ ����������� Boss\n";
	this->company_name = company_name;
	this->wrk = wrk;
}

MYns::Boss::~Boss()
{
	std::cout << "������ ���������� Boss\n";
}

void MYns::Boss::ShowInfo()
{
	wrk->ShowInfo();
	std::cout << "��� ��������: " << company_name << std::endl;
}
