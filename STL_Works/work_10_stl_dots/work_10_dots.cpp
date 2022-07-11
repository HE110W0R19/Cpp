#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <stack>
#include <windows.h>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <filesystem>

using namespace std;
random_device Rand;

class dot_creator
{
protected:
public:
	string file_way = "";
	string file1 = "";
	string file2 = "";
	vector<pair<int, int>> dots_file1{};
	vector<pair<int,int>> dots_file2{};
	vector<pair<int, int>> dots_new{};
public:
	dot_creator();
	void add_dots_to_arr(dot_creator& tmp);
	void find_file();
};

dot_creator::dot_creator()
{
	ifstream fin;
	cout << "Enter file way: "; cin >> file_way;
	cout << "Enter first file name: "; cin >> file1;
	cout << "Enter second file name: "; cin >> file2;
	std::filesystem::current_path(file_way);
}

void dot_creator::add_dots_to_arr(dot_creator& tmp)
{
	ifstream fin;
	fin.open(tmp.file1);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			string buff = "";
			getline(fin, buff);
			tmp.dots_file1.emplace_back(stoi(buff.substr(0, buff.find_first_of(" "))),
				stoi(buff.substr(buff.find_first_of(" ") + 1, buff.find_last_of(" "))));
			buff.erase();
		} fin.close();
	}
	else cout << "Error open" << endl;
	//пробовал запихнуть реализацию в отдельную фун-ию, но не работает
	fin.open(tmp.file2);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			string buff = "";
			getline(fin, buff);
			tmp.dots_file2.emplace_back(stoi(buff.substr(0, buff.find_first_of(" "))),
				stoi(buff.substr(buff.find_first_of(" ") + 1, buff.find_last_of(" "))));
			buff.erase();
		} fin.close();
	}
	else cout << "Error open" << endl;
}

void dot_creator::find_file()
{
	//сравнение двух файлов на количество совпадений 
	int min_size = dots_file1.size();
	if (min_size > dots_file2.size())
		min_size = dots_file2.size();
	int counter = 0;
	for (int i = 0; i < dots_file1.size(); ++i)
	{
		for (int j = 0; j < dots_file2.size(); ++j)
		{
			if (dots_file1[i].first == dots_file2[j].first 
				&& dots_file1[i].second == dots_file2[j].second)
				++counter;
		}
	}

	if (counter > min_size || counter == min_size)
	{
		cout << "File included!" << endl;
	}

	else
	{	
		//добавление всех элементов в новый вектор
		for (auto& tmp : dots_file1)
		{
			dots_new.emplace_back(tmp.first, tmp.second);
		}
		for (auto& tmp : dots_file2)
		{
			dots_new.emplace_back(tmp.first, tmp.second);
		}
		//удаление лишних схожих элементов
		for (int i = 0; i < dots_new.size(); ++i)
		{
			for (int j = 1; j < dots_new.size()-1; ++j)
			{
				if (dots_new[i].first == dots_new[j].first
					&& dots_new[i].second == dots_new[j].second)
					dots_new.erase(dots_new.begin() + j);
			}
		}
		cout << "Files not included!\nEnter new file name: ";
		cin >> file1;
		ofstream fout;
		fout.open(file1);
		for (auto& tmp : dots_new)
		{
			fout << tmp.first << " " << tmp.second << endl;
		} fout.close();
		cout << "File ready!" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	dot_creator test;
	test.add_dots_to_arr(test);
	test.find_file();

	system("pause");
	return 0;
}