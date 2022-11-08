#include "Human.h"

namespace MYns
{
	Human::Human()
	{
		std::cout << "Вызван конструктор Human по умолчанию\n";
		age = 0;
		name = "Ivanov Ivan";
	}

	Human::Human(std::string name, int age)
	{
		std::cout << "Вызван конструктор Human\n";
		this->name = name;
		this->age = age;
	}

	void Human::ShowInfo()
	{
		std::cout << "Имя: " << name << "; Возраст: " << age << std::endl;
	}

	Human::~Human()
	{
		std::cout << "Вызван деструктор Human\n";
	}
}