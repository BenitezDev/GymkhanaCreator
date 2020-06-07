
// ...

#pragma once
#include <string>
#include <vector>
#include <model/StageComponent.hpp>
#include "../../libraries/rapidxml/rapidxml.hpp"
#include <model/StateComponentAR.hpp>
#include <memory>

namespace backend
{
	class Stage
	{
	private:
		std::string name_;
		
		double latitude;
		double longitude;


		std::vector<std::shared_ptr<StageComponent>> components;
		
	public:
		Stage() = default;
		Stage(const std::string& name) : name_(name)
		{
		}
		
	public:
		 void add_component(std::shared_ptr<StageComponent> comp)
		 {
			 components.push_back(comp);
		 }

		 void save_in_xml(rapidxml::xml_node<>* parent)
		 {
			 using namespace rapidxml;

			 
			 xml_node<>* node = parent->document()->allocate_node(node_element, "Stage");
			 parent->append_node(node);

			 char* name = parent->document()->allocate_string(name_.c_str());
			 xml_attribute<>* attr = parent->document()->allocate_attribute("name",name);
			 node->append_attribute(attr);
		 	
		

			 for (auto component : components)
			 {
				 
				if(auto ar = static_cast<StageComponentAR*>(component.get()))
			 	{
					ar->save_in_xml(node);
			 	}
				

			 }

		 }


	};
}
