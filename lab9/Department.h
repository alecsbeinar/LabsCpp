#pragma once
#include <vector>
#include "Worker.h"

namespace MYns
{
	class Department
	{
	public:
		Department();
		Department(std::vector<Worker*> workers);
		~Department();

		std::vector<Worker*> GetWorkers();
	private:
		std::vector<Worker*> workers;
	};
}


