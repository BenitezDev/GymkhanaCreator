
#include <GymkhanaManager.hpp>

#include <rapidxml_print.hpp>


namespace backend
{
	GymkhanaManager& GymkhanaManager::instance()
	{
		static GymkhanaManager instance;
		return instance;
	}

	void GymkhanaManager::create_xml()
	{
		gymkhana_.save_in_xml();
	}

	void GymkhanaManager::create_gymkhana(const std::string& name)
	{
		gymkhana_ = Gymkhana(name);
	}
}
