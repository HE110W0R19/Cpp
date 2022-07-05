#include <iostream>
#include <random>
#include <string.h>
#include <windows.h>
#include <fstream>
using namespace std;
random_device Rand;

class overcoat
{
	string type;
	unsigned int price;
public: 
	overcoat();
	bool operator==(overcoat&);
	string operator=(string);
	bool operator<(overcoat&);
	void print();
	~overcoat();
}; 

overcoat::overcoat()
{
	cout << "Enter type: ";
	cin >> type;
	cout << "Enter price: ";
	cin >> price;
	cout << endl;
}

void overcoat::print()
{
	cout << "Type: " << type << endl;
	cout << "Price: " << price << endl << endl;;
}

bool overcoat::operator==(overcoat& other)
{
	if (type == other.type)
	{
		cout << "Одинаковый тип!" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

string overcoat::operator=(string other)
{
	if (type != other)
	{
		type = "";
		type += other;
		return type;
	}
	else if (type == other)
	{
		return type;
	}
}

bool overcoat::operator<(overcoat& other)
{
	if (price < other.price)
	{
		cout << "Ваше пальто дешевле!" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

overcoat::~overcoat()
{
	type = "";
	price = 0;
}

int main() 
{
	setlocale(LC_ALL, "Rus");

	overcoat user1, user2;
	user1.print();
	user2.print();
	string type;
	cout << "Enter type: ";
	cin >> type;
	user1 = type;
	user1.print();
	system("pause");
	return 0;
}