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

struct _country
{
	string country = "";
	string city = "";

	_country(string Co, string Ci)
		: country(Co), city(Ci) {};

	bool operator=(const string& tmp)
	{
		city = tmp;
		return false;
	}

	bool operator=(const _country& tmp)
	{
		country = tmp.country;
		city = tmp.city;
		return false;
	}

	bool operator==(const string& tmp) const
	{
		return country == tmp;
	}

	friend ostream& operator<<(ostream& os, const _country& tmp)
	{
		os << tmp.country << " " << tmp.city << endl;
		return os;
	}
};

class world
{
protected:
	vector<_country> my_world{};
	string f_name = "";
	string buff = "";
public:
	world();
	void file_save(const string& file_way,const string& file_name);
	bool city_quant();
	bool city_search(const string& country_name);
	bool city_exchange(const string& old_name, const string& new_name);
	void country_print()const;
	bool country_delete(const string& country_name);
	bool country_add(const string& country_name, const string& city_name);
};

world::world()
{
	try
	{
		ifstream fin;
		cout << "Enter file way: "; cin >> buff;
		cout << "Enter file name: "; cin >> f_name;
		std::filesystem::current_path(buff); buff = "";
		fin.open(f_name);
		while (!fin.eof())
		{
			getline(fin, buff);
			my_world.emplace_back(buff.substr(0, buff.find_first_of(" ")),
				buff.substr(buff.find_last_of(" ")+1));
			buff.erase();
		}
		cout << "File was readed!" << endl;
		fin.close();
	}
	catch (std::exception& _ex) 
	{
		cout << "Error: " << _ex.what() << endl;
	};
}

void world::file_save(const string& file_way, const string& file_name)
{
	ofstream fout;
	std::filesystem::current_path(file_way);
	fout.open(file_name);
	for (auto& tmp : my_world)
	{
		fout << tmp;
	}
	fout.close();
	cout << "File saved!" << endl;
}

bool world::city_quant()
{
	uint16_t quantity = 0;
	for (auto& tmp : my_world)
	{
		if (tmp.city != " ")
		{
			++quantity;
		}
	}
	cout << "City quantity: " << quantity << endl;
	return false;
}

bool world::city_search(const string& country_name)
{
	string buff = country_name;
	find_if(my_world.begin(), my_world.end(),
		[buff](const _country& tmp) {
			if (tmp == buff)
			{
				cout <<"Finded: " << tmp;
				return false;
			}
		});
	return false;
}

bool world::city_exchange(const string& old_name, const string& new_name)
{
	string buff_old = old_name;
	replace_if(my_world.begin(), my_world.end(),
		[&buff_old](_country& tmp) {
			if (tmp.city == buff_old)
			{
				return true;
			}
		}, new_name); 
	return false;
}

void world::country_print() const
{
	for (auto& tmp : my_world)
	{
		cout << tmp;
	}
	cout << "Ready!" << endl;
}

bool world::country_delete(const string& country_name)
{
	auto rem = remove(my_world.begin(), my_world.end(), country_name);
	if (rem != my_world.end())
	{
		my_world.erase(rem, my_world.end());
	}
	return false;
}

bool world::country_add(const string& country_name, const string& city_name)
{
	my_world.emplace_back(country_name, city_name);
	cout << "Added!" << endl;
	return false;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	


	system("pause");
	return 0;
}