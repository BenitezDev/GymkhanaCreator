
// ...

#pragma once


#include <vector>
#include "Monologue.hpp"


namespace backend
{
	class Dialogue 
	{

		//std::vector<Monologue> monologues;
		Monologue monologue;
	public:

		Dialogue(Monologue monologue) : monologue(monologue)
		{
		}
		
	public:
		
	/*	void add_monologue()
		{
			monologues.emplace_back();
		}*/

	};
}
