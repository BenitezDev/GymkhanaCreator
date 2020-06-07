
// ...

#pragma once
#include "Stage.hpp"
#include <vector>



namespace backend
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
		std::string name;
		std::vector<Stage> stages;
		//Difficulty difficulty;
		//Target target;

	public:
		Route() = default;
		Route(const std::string& name) : name(name)
		{
		}
	public:
		
		void add_stage(Stage stage)
		{
			stages.push_back(stage);
		}

		void remove_stage(int index)
		{
			stages.erase(stages.begin() + index);
		}


		void save_in_xml(rapidxml::xml_node<>* parent)
		{
			using namespace rapidxml;

			xml_node<>* node = parent->document()->allocate_node(node_element, "Route");
			parent->append_node(node);

			char* name = parent->document()->allocate_string(this->name.c_str());
			xml_attribute<>* attr = parent->document()->allocate_attribute("name", name);
			node->append_attribute(attr);
			
			for (auto stage : stages)
			{
				stage.save_in_xml(node);
			}
		}
	};
}
