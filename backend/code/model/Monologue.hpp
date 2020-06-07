/**
* @file Monologue.hpp
*
* @author Alejandro Benítez López
*
* @date 07/06/2020
*
* @brief Model data of a monologue
*/

#pragma once

#include <string>
#include <vector>
#include "../../libraries/rapidxml/rapidxml.hpp"
#include <sstream>

using namespace rapidxml;

namespace backend
{
	class Monologue
	{
		
	private:
		
		std::string character_;
		std::vector<std::string> sentences_;
		std::string side_;

	public:
		Monologue() = default;

		Monologue(const std::string character, std::vector<std::string> sentences, std::string side)
			: character_(character), sentences_(sentences), side_(side)
		{
		}


	public:

		void add_sentence()
		{
			sentences_.emplace_back();
		}

		void remove_sentence(int index)
		{
			sentences_.erase(sentences_.begin() + index);
		}

		std::string get_character() { return character_; }
		std::string get_side()		{ return side_; }
		std::vector<std::string> get_sentences() { return sentences_; }
		
	public:
		
		void save_in_xml(rapidxml::xml_node<>* parent)
		{
			xml_node<>* node = parent->document()->allocate_node(
				node_element, "monologue_test");
			parent->append_node(node);


			char* side = parent
			             ->document()->allocate_string(this->side_.c_str());
			xml_node<>* node1 = parent->document()->allocate_node(
				node_element, "side", side);
			node->append_node(node1);


			xml_node<>* node2 = parent->document()->allocate_node(
				node_element, "character", "TODO");
			node->append_node(node2);


			xml_node<>* node3 = parent->document()->allocate_node(
				node_element, "sentences");
			node->append_node(node3);

			for (size_t i = 0; i < sentences_.size(); ++i)
			{
				xml_node<>* sentence = parent->document()->allocate_node(
					node_element, "sentence",
					sentences_[i].c_str());
				node3->append_node(sentence);
				std::string index_string;


				xml_attribute<>* attr = parent->document()->allocate_attribute("index",int2char(i, parent->document()));
				sentence->append_attribute(attr);
			}

		}

		char* int2char(int value, xml_document<>* doc)
		{
			char tmpval[64];
			sprintf_s(tmpval, "%i", value);
			return doc->allocate_string(tmpval);
		}
	};
}
