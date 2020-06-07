/**
* @file Gymkhana.hpp
*
* @author Alejandro Benítez López
*
* @date 07/06/2020
*
* @brief Model data of a dialogue
*/

#pragma once

#include "Route.hpp"
#include <vector>
#include <string>
#include <fstream>
#include "../../libraries/rapidxml/rapidxml_print.hpp" // I dont know why vs dont detect the path
#include <iostream>

namespace backend
{
	class Gymkhana
	{
	private:
		std::string name_;
		std::vector<Route> routes_;


		// std::string version_;
		// std::string bundle_identifier_;


	public:
		Gymkhana() = default;

		Gymkhana(const std::string& name) : name_(name)
		{
		}

	public:

		void add_route(Route route)
		{
			routes_.push_back(route);
		}

		void change_name(std::string& name)
		{
			this->name_ = name;
		}

		std::string get_name() const
		{
			return name_;
		}


		void save_in_xml()
		{
			using namespace rapidxml;

			xml_document<> doc;

			xml_node<>* node = doc.allocate_node(node_element, "Gymkhana");
			doc.append_node(node);

			char* name = doc.allocate_string(this->name_.c_str());
			xml_attribute<>* attr = doc.allocate_attribute("name", name);
			node->append_attribute(attr);

			for (Route route : routes_)
			{
				route.save_in_xml(node);
			}

			// Create and open a text file
			std::ofstream MyFile("gymkhana.xml");

			// Write to the file
			MyFile << doc;

			std::cout << doc << std::endl;
			
			// Close the file
			MyFile.close();
		}
	};
}
