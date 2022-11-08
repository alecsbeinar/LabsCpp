#include "Human.h"

namespace MYns
{
	Human::Human()
	{
		std::cout << "������ ����������� Human �� ���������\n";
		age = 0;
		name = "Ivanov Ivan";
	}

	Human::Human(std::string name, int age)
	{
		std::cout << "������ ����������� Human\n";
		this->name = name;
		this->age = age;
	}

	void Human::ShowInfo()
	{
		std::cout << "���: " << name << "; �������: " << age << std::endl;
	}

	Human::~Human()
	{
		std::cout << "������ ���������� Human\n";
	}
}