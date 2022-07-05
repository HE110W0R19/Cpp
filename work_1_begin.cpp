#include <iostream>
#include <random>
#include <cmath>

using namespace std;
random_device Rand;


class fraction
{
	double numerator = 0;
	double denominator = 0;
	double num = 0;
	int integer = 0;
public:
	double user_n = 0;
	char do_what = 0;
	void create();
	void doing();
};
void fraction::create()
{
	cout << "Enter numerator: ";
	cin >> numerator;
	cout << "Enter denominator: ";
	cin >> denominator;
	num = numerator / denominator;
	cout << "Your num: " << numerator << "/" << denominator << " = " << num << endl;
}

void fraction::doing()
{
	cout << "What you want to do: (*,/,+,-)";
	cin >> do_what;
	cout << "Enter_num: ";
	cin >> user_n;
	if (do_what == '*')
	{
		num *= user_n;
	}
	else if (do_what == '/')
	{
		num /= user_n;
	}
	else if (do_what == '+')
	{
		num += user_n;
	}
	else if (do_what == '-')
	{
		num -= user_n;
	}
	cout << "Finish num: " << num << endl;

}
int main()
{
	setlocale(LC_ALL, "Rus");
	fraction user_num;
	user_num.create();
	user_num.doing();

	system("pause");
	return 0;
}