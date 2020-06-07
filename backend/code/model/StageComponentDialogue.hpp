
// ...

#pragma once

#include <utility>
#include "StageComponent.hpp"
#include "Monologue.hpp"


namespace backend
{
	class StageComponentDialogue : public StageComponent
	{
	private:
		Monologue monologue_;
		
	public:
		StageComponentDialogue() = default;
		
		StageComponentDialogue(Monologue m) : monologue_(m)
		{
		}
		
		void save_in_xml(xml_node<>* parent) override
		{

			xml_node<>* node = parent->document()->allocate_node(node_element, "dialogue_component");
			parent->append_node(node);

			char* character = parent->document()->allocate_string(monologue_.get_character().c_str());
			xml_node<>* node2 = parent->document()->allocate_node(node_element, "character", character);
			node->append_node(node2);

			char* side = parent->document()->allocate_string(monologue_.get_side().c_str());
			xml_node<>* node3 = parent->document()->allocate_node(node_element, "side", side);
			node->append_node(node3);

			for(int i = 0; i < monologue_.get_sentences().size(); ++i)
			{
				char* sentence = parent->document()->allocate_string(monologue_.get_sentences()[i].c_str());
				xml_node<>* node4 = parent->document()->allocate_node(node_element, "sentence", sentence);
				node->append_node(node4);
			}

		}
	
	};
}
