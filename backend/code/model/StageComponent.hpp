// ...

#pragma once
#include "../../libraries/rapidxml/rapidxml.hpp"


namespace backend
{
	class StageComponent
	{
	public:
		//virtual ~StageComponent() = default;
		StageComponent() = default;

	public:
		virtual void save_in_xml(rapidxml::xml_node<>* parent)
		{
		}
	};
}
