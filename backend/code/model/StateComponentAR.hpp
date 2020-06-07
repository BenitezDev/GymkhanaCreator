
// ...

#pragma once

#include <model/StageComponent.hpp>
#include <string>
#include "../../libraries/rapidxml/rapidxml.hpp"


using namespace rapidxml;

namespace backend
{
	class StageComponentAR : public StageComponent
	{
	private:
		std::string image_path;
		std::string  game_path;

	public:
		StageComponentAR() = default;
		
		StageComponentAR(const std::string& img_path, const std::string& game_path)
			: image_path(img_path) , game_path(game_path)
		{
		}
		
	public:
		void set_image_path(std::string& img_path)
		{
			this->image_path = img_path;
		}

		void set_game_path(std::string& game_path)
		{
			this->game_path = game_path;
		}

		void save_in_xml(xml_node<>* parent) override
		{

			xml_node<>* node = parent->document()->allocate_node(node_element, "ar_component");
			parent->append_node(node);

			char* img = parent->document()->allocate_string(image_path.c_str());
			xml_node<>* node2 = parent->document()->allocate_node(node_element, "image_path", img);
			node->append_node(node2);

			char* game = parent->document()->allocate_string(game_path.c_str());
			xml_node<>* node3 = parent->document()->allocate_node(node_element, "game_path", game);
			node->append_node(node3);

		}
	};
}
