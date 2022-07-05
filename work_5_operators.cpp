#include <iostream>
#include <random>
#include <string.h>
#include <windows.h>
#include <fstream>
using namespace std;
random_device Rand;

class date
{
	uint16_t day;
	uint16_t mon;
	uint32_t wer;
public:
	date() : day{ 1 }, mon{ 1 }, wer{ 1900 }{}
	date(uint16_t dayP, uint16_t monP, uint32_t werP)
		:day{ dayP }, mon{ monP }, wer{ werP }{}

	bool operator!=(const date& tmp) 
	{
		if (day != tmp.day && mon != tmp.mon && wer != tmp.wer)
		{
			cout << "Не равны!" << endl;
			return true;
		}
	}
	bool operator==(const date& tmp) 
	{
		if (day == tmp.day && mon == tmp.mon && wer == tmp.wer)
		{
			cout << "Равны!" << endl;
			return true;
		}
	}
	bool operator>(const date& tmp) 
	{
		if (day > tmp.day && mon > tmp.mon && wer > tmp.wer)
		{
			cout << "Больше" << endl;
			return true;
		}
	}
	bool operator<(const date& tmp) 
	{
		if (day < tmp.day && mon < tmp.mon && wer < tmp.wer)
		{
			cout << "Меньше" << endl;
			return true;
		}
	}
	void operator>>(int) 
	{
		cin >> day >> mon >> wer;
	}
	void operator<<(int) 
	{
		cout << day << "." << mon << "." << wer;
	}
	void operator=(date& tmp) 
	{
		day = tmp.day;
		mon = tmp.mon;
		wer = tmp.wer;
	}
	void operator+=(date& tmp) 
	{
		day += tmp.day;
		mon += tmp.mon;
		wer += tmp.wer;
	}
	void operator-=(date& tmp) 
	{
		day -= tmp.day;
		mon -= tmp.mon;
		wer -= tmp.wer;
	}
	date operator++()
	{
		++day;
	}
	date operator--() 
	{
		--day;
	}
	void operator()(date& tmp) 
	{
		
	}
	~date() = default;
};

int main() 
{
	setlocale(LC_ALL, "Rus");

	
	
	system("pause");
	return 0;
}