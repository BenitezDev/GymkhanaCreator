
// ...

#pragma once
#include <string>
#include <vector>
#include "StageComponent.hpp"


namespace backend
{
	class Stage
	{
	private:
		std::string name;
		
		double latitude;
		double longitude;


		std::vector<StageComponent> components;
		
	public:
		Stage() = default;
		
	public:
		

	};
}
