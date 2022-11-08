#pragma once
#include <iostream>

namespace MYns
{
	class Workplace
	{
	public:
		Workplace();
		Workplace(std::string name_workplace);
		~Workplace();

		std::string GetName();
	private:
		std::string name_workplace;
	};
}

