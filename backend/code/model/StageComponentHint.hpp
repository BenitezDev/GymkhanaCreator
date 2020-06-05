
// ...

#pragma once

#include <string>
#include <vector>
#include "Monologue.hpp"


namespace benitezdev
{
	class StageComponentHint
	{

	private:
		std::vector<Monologue> dialogue;

	public:
		void add_sentence()
		{
			dialogue.emplace_back();
		}

		void remove_sentence(int index)
		{
			dialogue.erase(dialogue.begin() + index);
		}

	};
}
