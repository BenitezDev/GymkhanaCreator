/**
* @file StageComponent.hpp
*
* @author Alejandro Benítez López
*
* @date 07/06/2020
*
* @brief Base class for Stage Components
*/

#pragma once
#include "../../libraries/rapidxml/rapidxml.hpp"


namespace backend
{
	class StageComponent
	{
	public:
		StageComponent() = default;

	public:
		virtual void save_in_xml(rapidxml::xml_node<>* parent)
		{
		}
	};
}
