//task1
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

class Shape
{
protected:
	string color = "";
	int amount = 0;
	uint16_t* x_dots = new uint16_t[amount]{};
	uint16_t* y_dots = new uint16_t[amount]{};
public:
	Shape();
	virtual void dot_arr() = 0;
	virtual void draw()const = 0;
};

Shape::Shape()
{
	cout << "Enter color: ";
	cin >> color;
	cout << "Enter dots amount: ";
	cin >> amount;
}

class _Circle : public Shape
{
public:
	void dot_arr();
	void draw()const;
};

void _Circle::dot_arr()
{
	for (size_t i = 0; i < amount; ++i)
	{
		cout << "Enter x and y dot: ";
		cin >> x_dots[i] >> y_dots[i];
	}
}

void _Circle::draw() const
{
	for (size_t i = 0; i < amount; ++i)
	{
		cout << "X/Y: " << x_dots[i] << y_dots[i] << endl;
	}
	cout << "Rectangle:" << endl;
	cout << "Color: "<< color << endl;
	cout << "	      * * *\n" << "	    *       *\n" << "	   *         *\n"
		<< "	  *           *\n" << "	  *           *\n" << "	   *         *\n"
		<< "	    *       *\n" << "	      * * *\n";
}

class _Rectangle : public Shape
{
public:
	void dot_arr();
	void draw()const;
};

void _Rectangle::dot_arr()
{
	for (size_t i = 0; i < amount; ++i)
	{
		cout << "Enter x and y dot: ";
		cin >> x_dots[i] >> y_dots[i];
	}
}

void _Rectangle::draw() const
{
	for (size_t i = 0; i < amount; ++i)
	{
		cout << "X/Y: " << x_dots[i] << y_dots[i] << endl;
	}
	cout << "Rectangle:" << endl;
	cout << "Color: " << color << endl;
	for (int i = 0; i < 5; ++i)
	{
		cout << "\t";
		for (int j = 0; j < 15; ++j)
		{
			cout << "=";
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	_Circle test;
	test.dot_arr();
	test.draw();

	_Rectangle test2;
	test.dot_arr();
	test2.draw();
	
	system("pause");
	return 0;
}
//task2
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

class Student
{
protected:
	string FIO = "";
	string group = "";
	uint16_t date = 0;
public:
	Student()
	{
		cout << "Enter full name: ";
		cin >> FIO;
		cout << "Enter group name and number: ";
		cin >> group;
		cout << "Enter born date: ";
		cin >> date;
	}
	virtual void print_info();
};

void Student::print_info()
{
	cout << "Status: Just student" << endl;
	cout << "Full name: " << FIO << endl;
	cout << "Group num: " << group << endl;
	cout << "Born date: " << date << endl;
}

class Aspirant : public Student
{
protected:
	string work_status = "";
private:
	Aspirant()
	{
		cout << "Enter work status: ";
		cin >> work_status;
	}
	void print_info();
};

void Aspirant::print_info()
{
	cout << "Status: Aspirant" << endl;
	cout << "Full name: " << FIO << endl;
	cout << "Group num: " << group << endl;
	cout << "Born date: " << date << endl;
	cout << "Work status: " << work_status << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	
	system("pause");
	return 0;
}