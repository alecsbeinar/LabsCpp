#pragma once
#include <iostream>
namespace MYns
{
	class Position
	{
	public:
		Position();
		Position(std::string name_position);
		~Position();

		std::string GetName();
	private:
		std::string name_position;
	};
}
