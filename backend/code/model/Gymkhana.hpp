
// ...

#pragma once

#include "Route.hpp"
#include <vector>
#include <string>
#include <fstream>

#include "../../libraries/rapidxml/rapidxml_print.hpp"
#include <iostream>

namespace backend
{
	class Gymkhana
	{
	private:
		std::string name;
		// std::string version;
		// std::string bundle_identifier;
		std::vector<Route> routes;
		
	public:
		Gymkhana() = default;
		
		Gymkhana (const std::string& name) : name(name)
		{
		}
		
		void add_route(Route route)
		{
			routes.push_back(route);
		}

		
		void        change_name(std::string& name)	{ this->name = name; }
		std::string get_name   () const				{ return  name	   ; }


		void save_in_xml()
		{
			using namespace rapidxml;
			
			xml_document<> doc;

			xml_node<>* node = doc.allocate_node(node_doctype, "", "");
			doc.append_node(node);
			node = doc.allocate_node(node_element, "Gymkhana", name.c_str());
			doc.append_node(node);

			for (Route route : routes)
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
