#pragma once
#include <iostream>
#include <string>

namespace MYns
{
	class Human
	{
	public:
		Human();
		Human(std::string name, int age);
		~Human();

		void ShowInfo();
	protected:
		std::string name;
		int age;
	};
}


