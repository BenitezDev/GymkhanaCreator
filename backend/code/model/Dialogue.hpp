
// ...

#pragma once


#include <vector>
#include "Monologue.hpp"


namespace backend
{
	class Dialogue 
	{

		std::vector<Monologue> monologues;


	public:
		void add_monologue()
		{
			monologues.emplace_back();
		}

	};
}
