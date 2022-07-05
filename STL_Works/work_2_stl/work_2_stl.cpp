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

class team
{
public:
	string name = "";
	uint16_t win = 0;
	uint16_t lose = 0;
	double draw = 0.0; 
	double sum = 0;
	team();
	void team_print();
};

team::team()
{
	cout << "Enter team name: ";
	cin >> name;
	cout << "Enter win stat: ";
	cin >> win;
	cout << "Enter lose stat: ";
	cin >> lose;
	cout << "Enter draw stat: ";
	cin >> draw;
	sum = ((win * 2) + (draw*1.5)) - lose;
}

void team::team_print() 
{
	cout << "\n...Team name: " << name << endl;
	cout << "...Win stat: " << win << endl;
	cout << "...lose stat: " << lose << endl;
	cout << "...draw stat: " << draw << endl;
	cout << "...rate: " << sum << endl;
}


class champ
{
protected:
	vector<team> tmp_champ = {};
public:
	champ();
	void team_search();
	void team_add();
	void team_delete();
	void _print();
};

champ::champ()
{
	uint16_t tmp = 0;
	system("cls");
	cout << "Enter team amount: ";
	cin >> tmp;
	for (uint16_t i = 0; i < tmp; ++i)
	{
		tmp_champ.emplace_back();
	}
	cout << "...Ready!..." << endl;
}

void champ::team_search()
{
	uint16_t tmp = 0;
	system("cls");
	cout << "Enter search win stat: ";
	cin >> tmp;
	for (size_t i = 0; i < tmp_champ.size(); ++i)
	{
		if (tmp_champ[i].win == tmp)
		{
			system("cls");
			cout << "... Your finded team: " << endl;
			tmp_champ[i].team_print();
		}
	}
	cout << "...Ready!..." << endl;
}

void champ::team_add()
{
	uint16_t tmp = 0;
	system("cls");
	cout << "Enter add amount: ";
	cin >> tmp;
	for (uint16_t i = 0; i < tmp; ++i)
	{
		tmp_champ.emplace_back();
	}
	cout << "...Ready!..." << endl;
}

void champ::team_delete()
{
	string tmp;
	system("cls");
	cout << "Enter delete name team: ";
	cin >> tmp;
	for (size_t i = 0; i < tmp_champ.size(); ++i)
	{
		if (tmp_champ[i].name == tmp)
		{
			tmp_champ.erase(tmp_champ.begin() + i);
		}
	}
	cout << "...Ready!..." << endl;
}

void champ::_print()
{
	for (size_t i = 0; i < tmp_champ.size(); ++i)
	{
		tmp_champ[i].team_print();
	}
	cout << "...Ready!..." << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	champ rus;
	uint16_t choise = 0;
	while (choise != 5)
	{
		cout << "...menu..." << endl;
		cout << "...1 - add new team" << endl;
		cout << "...2 - delete team" << endl;
		cout << "...3 - search team with win stat" << endl;
		cout << "...4 - print teams" << endl;
		cout << "...5 - exit" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
			rus.team_add();
			break;
		case 2:
			rus.team_delete();
			break;
		case 3:
			rus.team_search();
			break;
		case 4:
			rus._print();
			break;
		case 5:
			cout << "...Exit..." << endl;
			break;
		default:
			cout << "Error choise!" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}