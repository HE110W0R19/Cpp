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

class company_book
{
public:
	string _name = "";
	string _boss = "";
	string _phone = "";
	string _addres = "";
	string _type = "";

	company_book()
	{
		cout << "\nEnter company name: "; cin >> _name;
		cout << "Enter company boss name: "; cin >> _boss;
		cout << "Enter company phone: "; cin >> _phone;
		cout << "Enter company addres: "; cin >> _addres;
		cout << "Enter company type: "; cin >> _type;
	}
	company_book(string N, string B, string P, string A, string T) :
		_name(N), _boss(B), _phone(P), _addres(A), _type(T) {};
	virtual void print_info();
	~company_book()
	{
		_name = ""; _boss = ""; _phone = ""; _addres = ""; _type = "";
	}
};

void company_book::print_info()
{
	cout << "\nComp-ny Name: " << _name << endl;
	cout << "Comp-ny Boss: " << _boss << endl;
	cout << "Comp_ny Phone: " << _phone << endl;
	cout << "Comp_ny Addres: " << _addres << endl;
	cout << "Comp_ny Type: " << _type << endl;
}

void _search(vector<company_book>& tmp, uint16_t _col)
{
	string _input = "";
	cout << "Enter search: ";
	cin >> _input;
	for (int i = 0; i < _col; ++i)
	{
		if (tmp[i]._name == _input || tmp[i]._boss == _input
			|| tmp[i]._phone == _input || tmp[i]._addres == _input
			|| tmp[i]._type == _input)
		{
			cout << i << ")";
			tmp[i].print_info();
		}
		else
		{
			cout << i <<")Not find! " << endl;
		}
	}
}

void _file_add(vector<company_book>& tmp, uint16_t _col)
{
	string file_name = "MyBook.txt";
	ofstream fout;
	fout.open(file_name);
	if (!fout.is_open())
	{
		cout << "Open error!" << endl;
	}
	else
	{
		for (int i = 0; i < _col; ++i)
		{
			fout << endl <<  i << "======================" << endl;
			fout << "\nComp-ny Name: " << tmp[i]._name << endl;
			fout << "Comp-ny Boss: " << tmp[i]._boss << endl;
			fout << "Comp_ny Phone: " << tmp[i]._phone << endl;
			fout << "Comp_ny Addres: " << tmp[i]._addres << endl;
			fout << "Comp_ny Type: " << tmp[i]._type << endl;
		}
	}
	fout.close();
}

void _add(vector<company_book>& tmp)
{
	tmp.emplace_back();
}

int main()
{
	setlocale(LC_ALL, "Rus");
	
	uint16_t col = 0;
	vector<company_book> test;

	cout << "Enter col: ";
	cin >> col;
	for (int i = 0; i < col; i++)
	{
		test.emplace_back();
	}

	_search(test, col);
	_add(test); ++col;
	_file_add(test, col);

	system("pause");
	return 0;
}