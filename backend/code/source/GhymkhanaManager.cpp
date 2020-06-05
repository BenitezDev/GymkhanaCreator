
#include <GymkhanaManager.hpp>
#include <iostream>


#include <rapidxml.hpp>


#include <rapidxml_print.hpp>
#include <fstream>


#include <model/Monologue.hpp>
#include <sstream>


using namespace rapidxml;



namespace backend
{
	
    void GymkhanaManager::create_xml()
    {
        //Character c;
        
	auto m = new Monologue
		{	
        	{"primera frase", "segunda fraseee", "tercera fraseeee"},
        	Monologue::FaceSide::LEFT
        };


        xml_document<> doc;
		
        xml_node<>* node = doc.allocate_node(node_doctype, "", "");
        doc.append_node(node);
        node = doc.allocate_node(node_element, "Monologues", "");
        doc.append_node(node);
		
        m->save_in_xml(node);

        

		
        // Create and open a text file
        std::ofstream MyFile("filename.xml");

        // Write to the file
        MyFile << doc;

        // Close the file
        MyFile.close();

        delete m;



        std::cout << doc << std::endl;
    }

	
}
