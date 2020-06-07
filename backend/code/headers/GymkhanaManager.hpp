

#pragma once

#include <Linkage.hpp>
#include <model/Gymkhana.hpp>


namespace backend
{
	
	class GYMKHANA_API GymkhanaManager
	{
		/**
		 * The gymkhana that will be fill with data
		 */
		Gymkhana gymkhana_;

	private:
		
		GymkhanaManager() = default;

	public:

		/**
		 * Singleton
		 */
		static GymkhanaManager& instance();

		/**
		 * Create and safe the gymkhana data
		 */
		void create_xml();

		/**
		 * Create the gymkhana
		 */
		void create_gymkhana(const std::string& name);

		/**
		 * Getter for gymkhana
		 */
		Gymkhana get_gymkhana()
		{
			return gymkhana_;
		}

		/**
		 * Add a route to the gymkhana
		 */
		void add_route(Route route)
		{
			gymkhana_.add_route(route);
		}
		
	};

	
}
