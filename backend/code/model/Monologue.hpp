
// ...

#pragma once

#include <string>

#include <utility>
#include <vector>
#include "Character.hpp"

#include <rapidxml.hpp>
#include <sstream>

using namespace rapidxml;
namespace backend
{
	class Monologue 
	{
	public:
		enum FaceSide
		{
			LEFT,
			RIGHT
		};

		std::vector<std::string> FadeSideString{ "LEFT", "RIGHT" };
		
	private:
		////Character character;
		std::string charactrer;
		std::vector<std::string> sentences;
		FaceSide side;
		


	public:
		Monologue() = default;
		
		
		Monologue(/*Character& character,*/ std::vector<std::string> sentences, FaceSide side)
		: /*character(character), *//*sentences(sentences),*/ side(side)
		{
			this->sentences = sentences;
		}

		
	public:
	/*	void change_character(Character& character)
		{
			this->character = character;
		}*/

		void add_sentence()
		{
			sentences.emplace_back();
		}

		void remove_sentence(int index)
		{
			sentences.erase(sentences.begin() + index);
		}

		void change_side(FaceSide side)
		{
			this->side = side;
		}

	public:
		void save_in_xml(rapidxml::xml_node<>* parent)
		{
			
			
			xml_node<>* node = parent->document()->allocate_node(node_element, "monologue_test");
			parent->append_node(node);


			
			xml_node<>* node1 = parent->document()->allocate_node(node_element, "side", FadeSideString[side].c_str());
			node->append_node(node1);
		
		
			xml_node<>* node2 = parent->document()->allocate_node(node_element, "character", "TODO");
			node->append_node(node2);
		
		
			xml_node<>* node3 = parent->document()->allocate_node(node_element, "sentences");
			node->append_node(node3);

			for(size_t i = 0; i < sentences.size(); ++i)
			{
				
				xml_node<>* sentence = parent->document()->allocate_node(node_element, "sentence", sentences[i].c_str());
				node3->append_node(sentence);
				std::string index_string;


				
				xml_attribute<>* attr = parent->document()->allocate_attribute("index", int2char(i,parent->document()));
				sentence->append_attribute(attr);
			}
			

	
			/*xml_attribute<>* attr = parent.document()->allocate_attribute("href", "google.com");
			node->append_attribute(attr);*/
		}

		char* int2char(int value, xml_document<>* doc)
		{
			char tmpval[64];
			sprintf_s(tmpval, "%i", value);
			return doc->allocate_string(tmpval);
		}
	};
}
