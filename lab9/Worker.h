#pragma once
#include "Human.h"
#include "Speciality.h"
#include "Position.h"
#include "Workplace.h"

namespace MYns
{
	class Worker : public Human
	{
	public:
		Worker();
		Worker(double salary, std::string name, int age, Speciality* sp, Position* pos, Workplace* wpl);
		~Worker();

		void ShowInfo();
		double GetSalary();
		Speciality* GetSp();
		Position* GetPos();
		Workplace* GetWpl();

	protected:
		double salary;
		Speciality* sp;
		Position* pos;
		Workplace* wpl;
	};
}

