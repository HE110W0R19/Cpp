#include <iostream>
#include <random>
#include <string.h>
#include <vector>
#include <windows.h>
#include <fstream>
#include <map>
using namespace std;
random_device Rand;

class student
{
private: 
	string name;
	string date;
	string phone_num;
	string group_num;
	string country;
	string scool_name;
	string scool_country;
public:
	student();
	student(string na, string da, string ph, string gr,
		string co, string scN, string scC)
		: name{ na }, date{ da }, phone_num{ ph }, group_num{ gr },
		country{ co }, scool_name{ scN }, scool_country{ scC }{};
	void add_student();
	void print_student();
	student(const student&) = default;
	~student();
};
student::student()
{
	name = ""; date = ""; phone_num = "";
	group_num = ""; country = "";
	scool_name = ""; scool_country = "";
}

void student::add_student()
{
	cout << "\n Enter name: ";
	cin >> name;
	cout << "\n Ener date to burn: ";
	cin >> date;
	cout << "\n Enter phone number: ";
	cin >> phone_num;
	cout << "\n Enter group number: ";
	cin >> group_num;
	cout << "\n Enter country: ";
	cin >> country;
	cout << "\n Enter scool name: ";
	cin >> scool_name;
	cout << "\n Enter scool country: ";
	cin >> scool_country;
}

void student::print_student()
{
	cout << " Name: " << name << endl;
	cout << " Burn date: " << date << endl;
	cout << " Phone number: " << phone_num << endl;
	cout << " Group: " << group_num << endl;
	cout << " Country: " << country << endl;
	cout << " Scool name: " << scool_name<< endl;
	cout << " Scool country: " << scool_country << endl;
}

student::~student()
{
	name = ""; date = ""; phone_num = "";
	group_num = ""; country = "";
	scool_name = ""; scool_country = "";
}

class univer 
{
public:
	vector<student> group_7v;
public:
	void create_univer(student& test)
	{
		group_7v.push_back(test);
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	univer moscow;
	uint16_t col = 0;
	cout << "How many students?: ";
	cin >> col;
	for (int i = 0; i < col; i++)
	{
		student test;
		moscow.create_univer(test);
	}

	for (int i = 0; i < col; i++)
	{
		moscow.group_7v[i].print_student();
	}

	system("pause");
	return 0;
}