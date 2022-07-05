#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <filesystem>
#include <map>

std::random_device Rand;
using namespace std;

class dictionary
{
protected:
	map<string, uint32_t> book;
	uint32_t num_word = 0;
	string add_word = "";
public:
	dictionary() { num_word = 0; add_word = ""; }
	bool word_find();
	void word_add();
	void word_delete();
	void word_exchange();
	void word_print();
	void file_read();
	void file_save();
};

bool dictionary::word_find()
{
	cout << "Enter find word: ";
	cin >> add_word;
	auto find_word = book.find(add_word);
	if (find_word != book.end())
	{
		cout << "Word find: " << add_word << endl;
		return true;
	}
	else
	{
		cout << "Not find" << endl;
		return false;
	}
}

void dictionary::word_add()
{
	int counter = 0;
	cout << "Enter word col: ";
	cin >> counter;
	for (uint16_t i = 0; i < counter; ++i)
	{
		++num_word;
		cout << "Enter word: ";
		cin >> add_word;
		book.emplace(add_word, num_word);
	}
}

void dictionary::word_delete()
{
	cout << "Enter delete word: ";
	cin >> add_word;
	book.erase(add_word);
	cout << "Deleted" << endl;
}

void dictionary::word_exchange()
{
	string e_word = "";
	cout << "Enter new word: ";
	cin >> add_word;
	cout << "Enter exchange word: ";
	cin >> e_word;
	for (auto& tmp : book)
	{
		if (tmp.first == e_word)
		{
			uint32_t buff = tmp.second;
			book.erase(tmp.first);
			book.emplace(add_word, buff);
		}
	}
	cout << "Exchanged" << endl;
}

void dictionary::word_print()
{
	for (auto& tmp : book)
	{
		cout << ".№" << tmp.second << ") " << tmp.first << endl;
	}
}

void dictionary::file_read()
{
	try 
	{
		ifstream fin;
		string f_way = "";
		string f_name = "";
		cout << "Enter file way: ";
		cin >> f_way;
		cout << "Enter file name: ";
		cin >> f_name;
		std::filesystem::current_path(f_way);
		fin.open(f_name);
		while (!fin.eof())
		{
			++num_word;
			getline(fin, add_word);
			book.emplace(add_word, num_word);
		}
		cout << "File readed" << endl;
	}
	catch (std::exception& _ex)
	{
		cout << "Error: " << _ex.what() << endl;
	}
}

void dictionary::file_save()
{
	try
	{
		ofstream fout;
		string f_way = "";
		string f_name = "";		
		cout << "Enter file way: ";
		cin >> f_way;
		cout << "Enter file name: ";
		cin >> f_name;
		std::filesystem::current_path(f_way);
		fout.open(f_name);
		for (auto & tmp:book)
		{
			fout << tmp.first << endl;
		}
		cout << "File save" << endl;
	}
	catch (std::exception& _ex)
	{
		cout << "Error: " << _ex.what() << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	dictionary my_book;
	//Все работает как по маслу
	//Проверено ;)
	system("pause");
	return 0;
}
