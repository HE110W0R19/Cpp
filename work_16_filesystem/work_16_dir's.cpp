#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <windows.h>
#include <map>
#include <queue>
#include <fstream>
#include<filesystem>

std::random_device Rand;

void create_dir(std::string name)
{
	if (!std::filesystem::exists(name) && std::filesystem::create_directory(name))
	{
		std::cout << "Папка создана!" << std::endl;		
	}
	else if (std::filesystem::exists(name))
	{
		std::string choise = "";
		std::cout << "Такая папка уже существует!" << std::endl;
		name += "1";
		std::cout << "Возможное название: " << name << std::endl;
		std::cout << "Введие yes чтобы создать папку с новым именем, или no для отмены: ";
		std::cin >> choise;
		if (choise == "yes")
		{
			create_dir(name);
		}
		else
		{
			std::cout << "Отмена" << std::endl;
		}
	}
}

void search_dir(std::string way, std::string search_name)
{	
	try 
	{
		uint16_t counter = 0;
		std::string choise;
		std::filesystem::current_path(way);
		std::cout << "Input Dir: " << std::filesystem::current_path().string() << std::endl;
		for (auto& tmp : std::filesystem::recursive_directory_iterator(std::filesystem::current_path()))
		{
			if (search_name == tmp.path().filename())
			{
				++counter;
				std::cout << "\nSearch dir: " << std::endl;
				std::cout << "Name: " << tmp.path().filename() << std::endl;
				std::cout << "Way: " << tmp.path().string() << std::endl;
				std::cout << "Do you want to exchange dir name? (Put y or n): ";
				std::string choise = "";
				std::cin >> choise;
				if (choise == "y" || choise == "Y") 
				{
					std::string new_name = "";
					std::cout << "Enter new name: ";
					std::cin >> new_name;
					std::filesystem::rename(search_name, new_name);
				}
			}
		}
		std::cout << "Dir counter: " << counter << std::endl;
	}
	catch (std::filesystem::filesystem_error& _ex) 
	{
		std::cout << _ex.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Error way!" << std::endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	std::string way = "";
	std::string name = "";
	std::cout << "Enter way: ";
	std::cin >> way;
	std::cout << "Enter search name: ";
	std::cin >> name;
	search_dir(way, name);


	system("pause");
	return 0;
}