#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <windows.h>
#include <map>
#include <queue>
#include <fstream>
using namespace std;
random_device Rand;

class any_exception
{
protected: 
	int line = NULL;
	string happened = "";
	string noties = "";
public: 
	any_exception(int lne, string hpnd) : line(lne), happened(hpnd), noties("unknown error"s) {};
	any_exception(int lne, string fle, string nes) : line(lne), happened(fle), noties(nes) {};
	string what() const
	{
		return happened + ":" + to_string(line) 
			+ "(" + noties + ")";
	}
	string return_noties() const
	{
		return noties;
	}
};

class math_
{
protected: 
	double x = NULL;
	double y = NULL;
	double result = NULL;
public:
	math_()
	{
		cout << "Enter x: ";
		cin >> x;
		cout << "Enter y: ";
		cin >> y;
	}
	math_(double X, double Y) : x(X), y(Y) {};
	virtual double do_have_math() = 0;
	virtual double do_math(double X, double Y) = 0;
};

class math_multy:public math_
{
public:
	double do_have_math()
	{
		try
		{
			if (x == 0 || y == 0)
				throw - 1;
			else
			{
				result = x * y;
				if (result == 0)
					cout << "Impossible :o !!!";
				cout << "Res: " << result << endl;
				return result;
			}
		}
		catch (int)
		{
			cout << "Error '0'!?\nEnter new numbers: ";
			cin >> x >> y;
			if (x == 0 || y == 0)
				throw - 1;
			cout << "Res: " << x*y << endl;
			return (double)x * y;
		}
	}
	double do_math(double X, double Y)
	{
		try
		{
			if (X == 0 || Y == 0)
				throw - 1;
			else
			{
				result = X * Y;
				if (result == 0)
					cout << "Impossible :o !!!";
				cout << "Res: " << result << endl;
				return result;
			}
		}
		catch (int)
		{
			cout << "Error '0'!?\nEnter new numbers: ";
			cin >> x >> y;
			if (x == 0 || y == 0)
				throw - 1;
			cout << "Res: " << x*y << endl;
			return (double)x * y;
		}
	}
};

class math_share : public math_
{
public:
	double do_have_math()
	{
		try
		{
			if (x == 0 || y == 0)
				throw - 1;
			else
			{
				result = x / y;
				if (result == 0)
					cout << "Impossible :o !!!";
				cout << "Res: " << result << endl;
				return result;
			}
		}
		catch (int)
		{
			cout << "Error '0'!?\nEnter new numbers: ";
			cin >> x >> y;
			if (x == 0 || y == 0)
				throw - 1;
			cout << "Res: " << x/y << endl;
			return (double)x / y;
		}
	}
	double do_math(double X, double Y)
	{
		try
		{
			if (X == 0 || Y == 0)
				throw - 1;
			else
			{
				result = X / Y;
				if (result == 0)
					cout << "Impossible :o !!!";
				cout << "Res: " << result << endl;
				return result;
			}
		}
		catch (int)
		{
			cout << "Error '0'!?\nEnter new numbers: ";
			cin >> x >> y;
			if (x == 0 || y == 0)
				throw - 1;
			cout << "Res: " << result << endl;
			return (double)x / y;
		}
	}
};

void example(string file_name) {
	ifstream file;
	try {
		file.open(file_name);
		if (!file.is_open())
			throw any_exception(__LINE__, __FILE__, "not open file:" + file_name);
		while (!file.eof()) {
			string tmp;
			file >> tmp;
			cout << tmp << " ";
		}
	}
	catch (any_exception error) {
		cout << error.what() << endl;
		if (error.return_noties().find("not open") != std::string::npos) {
			string new_file;
			cout << "Enter file name:";
			cin >> new_file;
			example(new_file);
		}
		else 
		{
			throw;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	math_multy a;
	try
	{
		a.do_have_math();
	}
	catch (std::exception& expion)
	{
		cout << "Exception: " << expion.what() << endl;
	}
	catch(...)
	{
		cout << "I dont know what happened :(" << endl;
	}
	

	system("pause");
	return 0;
}