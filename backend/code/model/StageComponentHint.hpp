/**
* @file StageComponentHint.hpp
*
* @author Alejandro Benítez López
*
* @date 07/06/2020
*
* @brief Model data of a hint in a minigame
*/

#pragma once

#include <vector>
#include "Monologue.hpp"


/*
 * Al final no se ha implementado el sistema de personajes que se tenía previsto
 */


namespace backend
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
