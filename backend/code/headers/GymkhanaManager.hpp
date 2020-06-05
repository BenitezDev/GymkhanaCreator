

#pragma once

#include <Linkage.hpp>
#include <model/Gymkhana.hpp>


namespace backend
{
	
	class GYMKHANA_API GymkhanaManager
	{
		Gymkhana gymkhana_;
		
	public:

		static GymkhanaManager& instance()
		{
			static GymkhanaManager instance;
			return instance;
		}
		
		void create_xml();

		Gymkhana get_gymkhana() const { return gymkhana_; }
	
		
		//static char* double2char(int value, rapidxml::xml_document<>* doc);
		
	};

}
