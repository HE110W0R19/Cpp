#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <filesystem>
#include <functional>

std::random_device Rand;
using namespace std;

auto coment = [](int tmp)
{
	switch (tmp)
	{
	case 1:
		cout << "Open error!\nPleas, check dir way!" << endl;
		break;
	case 2:
		cout << "Unknown name!\nPleas< check file name!" << endl;
		break;
	default:
		cout << "Unknown error! (" << endl;
		break;
	}
};

class file_work
{
public: 
	string way = "C:/Users/TuF/Desktop/Новая папка";
	string name = "test.txt";
	string file = "";
	file_work();
	bool str_find();
	bool str_exchange();
	void str_print();
	void str_rotate();
	
};
file_work::file_work()
{
	/*cout << "Enter file way: ";
	cin >> way;
	cout << "Enter file name: ";
	cin >> name;*/
	std::filesystem::current_path(way);
}

bool file_work::str_find()
{
	try 
	{
		string search_str = "";
		string buff = "";
		cout << "Enter search word: ";
		cin >> search_str;
		ifstream fin;
		if (std::filesystem::exists(name))
		{
			fin.open(name);
			if (!fin.is_open())
			{
				coment(1);
				return false;
			}
			while (!fin.eof())
			{
				fin >> file;
				buff += (file + " ");
				if (file == search_str)
				{
					getline(fin, file);
					cout << "Find row: " << buff << file << endl;
					break;
				}
			}
			fin.close();
			return true;
		}
		else
		{
			coment(2);
			return false;
		}
	}
	catch (std::exception& _ex)
	{
		cout << "Error: " << _ex.what() << endl;
		return false;
	}
}

bool file_work::str_exchange()
{
	try
	{
		string search_str = "";
		string exchange_str = "";
		cout << "Enter search word: ";
		cin >> search_str;
		cout << "Enter exchange word: ";
		cin >> exchange_str;
		string buff = "";
		ifstream fin;
		if (std::filesystem::exists(name))
		{
			fin.open(name);
			if (!fin.is_open())
			{
				coment(1);
				return false;
			}
			while (!fin.eof())
			{
				getline(fin, file);
				buff += (file+"\n");
			}
			for (size_t i = 0; i < buff.size(); i++)
			{
				if (buff[i] == search_str[0])
				{
					buff[i] = exchange_str[0];
					break;
				}
			}
			cout << "Buffer: " << buff << endl;
			fin.close();
			ofstream fout;
			fout.open(name);
			fout << buff;
			fout.close();
			return true;
		}
		else 
		{
			coment(2);
			return false;
		}
	}
	catch (std::exception& _ex)
	{
		cout << "Error: " << _ex.what() << endl;
		return false;
	}
	return false;
}

void file_work::str_print()
{
	try {
		ifstream fin;
		if (std::filesystem::exists(name))
		{
			fin.open(name);
			if (!fin.is_open())
			{
				coment(1);
			}
			while (!fin.eof())
			{
				getline(fin, file);
				cout << file << endl;
			}
			fin.close();
		}
		else
		{
			coment(2);
		}
	}
	catch (std::exception& _ex)
	{
		cout << "Error: " << _ex.what() << endl;
	}
}

void file_work::str_rotate()
{
	try {
		ifstream fin;
		ofstream fout;
		string buff = "";
		if (std::filesystem::exists(name))
		{
			fout.open(name, ofstream::app);
			fin.open(name);
			if (!fin.is_open() && !fout.is_open())
			{
				coment(1);
			}
			while (!fin.eof())
			{
				getline(fin, file);
				reverse(file.begin(), file.end());
				buff += (file + "\n");
			}		
			cout << buff << endl;
			fout << endl << buff;
			fout.close();
			fin.close();
		}
		else
		{
			coment(2);
		}
	}
	catch (std::exception& _ex)
	{
		cout << "Error: " << _ex.what() << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
		
	file_work my_test;
	
	

	system("pause");
	return 0;
}