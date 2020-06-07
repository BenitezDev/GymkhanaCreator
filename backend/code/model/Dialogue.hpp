/**
* @file Dialogue.hpp
*
* @author Alejandro Benítez López
*
* @date 07/06/2020
*
* @brief Model data of a dialogue
*/

#pragma once

#include "Monologue.hpp"


namespace backend
{
	class Dialogue
	{
		//TODO: change to a vector<Monologue>

		Monologue monologue_;

	public:

		Dialogue(Monologue monologue) : monologue_(monologue)
		{
		}
	};
}
