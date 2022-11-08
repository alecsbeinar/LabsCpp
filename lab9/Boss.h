#pragma once
#include "Worker.h"

namespace MYns
{
    class Boss : public Worker
    {
	public:
		Boss();
		Boss(std::string company_name, Worker* wrk);
		~Boss();

		void ShowInfo();

	protected:
		std::string company_name;
		Worker* wrk;
    };
}

