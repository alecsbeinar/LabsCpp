#pragma once
#include <iostream>

namespace MYns
{
	class Speciality
	{
	public:
		Speciality();
		Speciality(std::string name_speciality);
		~Speciality();

		std::string GetName();
	private:
		std::string name_speciality;
	};
}

