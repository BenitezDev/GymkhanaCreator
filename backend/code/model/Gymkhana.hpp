
// ...

#pragma once

#include "Route.hpp"
#include <vector>
#include <string>

namespace backend
{
	class Gymkhana
	{
	private:
		std::string name;
		// std::string version;
		// std::string bundle_identifier;
		std::vector<Route> routes;
		
	public:
		void add_route()
		{
			routes.emplace_back();
		}

		
		void        change_name(std::string& name)	{ this->name = name; }
		std::string get_name   () const				{ return  name	   ; }
		
	};
}
