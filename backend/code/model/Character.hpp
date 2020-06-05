
// ...

#pragma once

#include <string>
#include <vector>


namespace backend
{

	class Image
	{
		typedef int Pixel; // TODO pixel class

	public:
		std::vector<Pixel> image;

	public:
		Image() = default;
		

	};

	
	class Character
	{
		
		
	public:
		enum Feelings
		{
			IDLE_1,
			IDLE_2,
			HAPPY_1,
			HAPPY_2,
			THINKING_1,
			THINKING_2,
			DOUBTING_1,
			DOUBTING_2
			
			// ...
		};
		
	private:
		std::vector <Image> images;
		std::string name;

	public:
		Character(std::vector<Image>& images, std::string& name)
		:images(images), name(name)
		{	
		}

		Character() = default;
		
		
	public:

		void change_name(std::string& name)
		{
			this->name = name;
		}

		void change_image(Image& image, int index)
		{
			images[index] = image;
		}

		void add_image(Image& image)
		{
			images.push_back(image);
		}

		void remove_image(int index)
		{
			images.erase(images.begin() + index);
		}
		
		
	};

	
}