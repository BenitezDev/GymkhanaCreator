
// ...

#pragma once

#include "StageComponent.hpp"
#include <string>


namespace backend
{
	class StageComponentAR : StageComponent
	{
	private:
		std::string image_path;
		std::string  game_path;

	public:

		void set_image_path(std::string& img_path)
		{
			this->image_path = img_path;
		}

		void set_game_path(std::string& game_path)
		{
			this->game_path = game_path;
		}
	};
}
