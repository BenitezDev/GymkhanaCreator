
// ...

#pragma once
#include "Stage.hpp"
#include <vector>



namespace benitezdev
{
	class Route
	{
		enum Difficulty
		{
			EASY,
			MEDIUM,
			HARD
		};

		enum Target
		{
			CHILDREN,
			TEENAGER,
			FAMILY
		};
		
	private:
		std::vector<Stage> stages;
		Difficulty difficulty;
		Target target;
		
	public:
		
		void add_stage()
		{
			stages.emplace_back();
		}

		void remove_stage(int index)
		{
			stages.erase(stages.begin() + index);
		}


		
	};
}
