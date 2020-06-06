

#pragma once

#include <Linkage.hpp>
#include <model/Gymkhana.hpp>


namespace backend
{
	
	class GYMKHANA_API GymkhanaManager
	{
		Gymkhana gymkhana_;

	private:
		GymkhanaManager() = default;

	public:

		
		static GymkhanaManager& instance()
		{
			static GymkhanaManager instance;
			return instance;
		}
		
		void create_xml()
		{
			gymkhana_.save_in_xml();
		}

		void create_gymkhana(const std::string& name)
		{
			gymkhana_ = Gymkhana(name);
			
		}
		
		Gymkhana get_gymkhana() { return gymkhana_; }
		
		void add_route(Route route)
		{
			gymkhana_.add_route(route);
		}
		
		//static char* double2char(int value, rapidxml::xml_document<>* doc);
		
	};

}
