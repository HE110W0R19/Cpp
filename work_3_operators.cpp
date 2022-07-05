#include <iostream>
#include <random>
#include <string.h>
#include <windows.h>
#include <fstream>

using namespace std;
random_device Rand;

class Drob
{
	int zn;
	double ch;
	double num;
public:
	Drob();
	double operator+(const Drob& new_num);
	double operator-(const Drob& new_num);
	double operator/(const Drob& new_num);
	double operator*(const Drob& new_num);
	~Drob();
};
Drob::Drob()
{
	ch = 0;
	zn = 0;
	num = ch / zn;
	cin >> ch; cout << "/"; cin >> zn;
	num = ch / zn;
}
double Drob::operator+(const Drob& new_num)
{
	ch += new_num.ch;
	zn += new_num.zn;
	cout << ch << "/" << zn;
	return 0.0;
}

double Drob::operator-(const Drob& new_num)
{
	ch -= new_num.ch;
	zn -= new_num.zn;
	cout << ch << "/" << zn;
	return 0.0;
}

double Drob::operator/(const Drob& new_num)
{
	num /= new_num.num;
	return num;
	cout << endl;
}

double Drob::operator*(const Drob& new_num)
{
	num *= new_num.num;
	return num;
	cout << endl;
}
Drob::~Drob()
{

}
int main()
{
	setlocale(LC_ALL, "Rus");
	Drob a;
	Drob b;
	cout << a * b;
	system("pause");
	return 0;
}

