#include <iostream>
#include <random>
#include <string.h>
#include <vector>
#include <windows.h>
#include <fstream>
using namespace std;
random_device Rand;

class train
{
	string number;
	string out_time;
	string finish_station;
public: 
	train();
	void print()
	{
		cout << "Train num: " << number << endl;
		cout << "Out time: " << out_time << endl;
		cout << "End ststion: " << finish_station << endl;
	}
	train(const train&) = default;
	~train() = default;
};

train::train()
{
	string num;
	string time;
	string finish;

	cout << "Номер: ";
	cin >> num;
	number += num;
	num = "";

	cout << "Время: ";
	cin >> time;
	out_time += time;
	time = "";

	cout << "Место: ";
	cin >> finish;
	finish_station += finish;
	finish = "";
}

class railway
{
public:
	vector<train> station;
public: 
	void add_train(train& test)
	{
		station.push_back(test);
	}
};

int main() 
{
	setlocale(LC_ALL, "Rus");
	railway moscow;
	//Ввод информации
	int col = 0;
	cout << "Enter col: ";
	cin >> col;
	for (int i = 0; i < col; i++)
	{
		train test;
		moscow.add_train(test);
	}
	//Вывод инфрмации о всех поездах
	for (int i = 0; i < col; i++)
	{
		moscow.station[i].print();
	}
	//Вывод информации о нужном поезде 
	cout << "Enter train num: ";
	cin >> col;
	moscow.station[col].print();
	system("pause");
	return 0;
}

