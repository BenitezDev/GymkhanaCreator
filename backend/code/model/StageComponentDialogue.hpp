
// ...

#pragma once

#include "StageComponent.hpp"
#include "Monologue.hpp"


namespace backend
{
	class StageComponentDialogue : StageComponent
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
