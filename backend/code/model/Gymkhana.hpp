
// ...

#pragma once

#include "Route.hpp"
#include <vector>
#include <string>

namespace benitezdev
{
	class Gymkhana
	{
	private:
		std::string name;
		// int version;
		// std::string bundle_identifier;
		std::vector<Route> routes;
		
	public:
		void add_route()
		{
			routes.emplace_back();
		}

		void change_name(std::string& name)
		{
			this->name = name;
		}
	};
}
