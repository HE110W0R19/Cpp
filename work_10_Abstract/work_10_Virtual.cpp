
#include <iostream>
#include <random>
#include <string.h>
#include <vector>
#include <windows.h>
#include <map>
#include <queue>

using namespace std;
random_device Rand;

class equal
{
protected:
	double x1 = 0.0;
	double x2 = 0.0;
public: 
	equal();
	virtual void root_eq() = 0;
	virtual void print() = 0;
};

equal::equal()
{
	x1 = x2 = 0;
}

class line_eq : public equal
{
protected:
	double ax;
	double b;
	char _do;
public:
	line_eq() : ax{ 0 }, b{ 0 }, _do{ ' ' }{};
	line_eq(double AX, char D, double B)
		:ax{ AX }, _do{ D }, b{ B }{};
	void root_eq()
	{
		if (_do == '-')
		{
			x1 = b / ax;
		}
		else if (_do == '+')
		{
			double tmp = b - (b * 2);
			x1 = tmp / ax;
		}
	}	
	void print()
	{
		if (_do == '-')
		{
			cout << ax << "x - " << b << " = 0" << endl;
			cout << "X = " << x1 << endl;
		}
		else if (_do == '+')
		{
			cout << ax << "x + " << b << " = 0" << endl;
			cout << "X = " << x1 << endl;
		}
	}
};

class square_eq : public equal
{
protected:
	short int a;
	short int b;
	short int D;
public:
	square_eq() :a{ 0 }, b{ 0 }, D{ 0 }{};
	square_eq(short int A, short int B, short int d)
		:a{ A }, b{ B }, D{ d }{};
	void root_eq()
	{
		short int tmp = b - (b * 2);
		x1 = (tmp + sqrt(D)) / (a * 2);
		x2 = (tmp - sqrt(D)) / (a * 2);
	}
	void print()
	{
		cout << "X1 = (" << b << " + sqrt(" << D
			<< ") / (" << a << " * 2)" << endl;
		cout << "X2 = (" << b << " - sqrt(" << D
			<< ") / (" << a << " * 2)" << endl;
		cout << "X1 = " << x1 << endl;
		cout << "X2 = " << x2 << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	
	line_eq l(6, '-', 24);
	l.root_eq();
	l.print();

	square_eq S(4,14, 256);
	S.root_eq();
	S.print();

	system("pause");
	return 0;
}

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
Задача №2
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
#include <iostream>
#include <random>
#include <string.h>
#include <vector>
#include <windows.h>
#include <map>
#include <queue>

using namespace std;
random_device Rand;

class home_animal
{
protected:
	string name;
	uint16_t age;
	uint16_t weight;
	string voice;
public:
	home_animal();
	home_animal(string N, uint16_t A, uint16_t W, string V) 
		: name{ N }, age{ A }, weight{ W }, voice{ V }{};
	virtual void Sound();
	virtual void Show();
	~home_animal() = default;
};

home_animal::home_animal()
{
	cout << "Enter name: "; cin >> name;
	cout << "Enter age: "; cin >> age;
	cout << "Enter weight: "; cin >> weight;
	cout << "Enter voice: "; cin >> voice;
	
}

void home_animal::Sound()
{
	cout << "Sound: " << voice << endl;;
}
void home_animal::Show()
{
	cout << "Name: " << name << endl;
}

class dog : public home_animal
{
public:
	uint16_t run_speed;
	dog()
	{
		cout << "Enter speed: " << endl;
		cin >> run_speed;
	}
	virtual void Speed()
	{
		cout << "Run speed: " << run_speed << endl;
	}
	void Type()
	{
		cout << "Type: canids" << endl;
	}
};

class cat : public dog
{
public:
	void Type()
	{
		cout << "Type: feline" << endl;
	}
};

class parrot : public home_animal
{
public:
	uint16_t fly_speed;
	parrot()
	{
		cout << "Enter fly speed: ";
		cin >> fly_speed;
	}
	void Type()
	{
		cout << "Type: bird" << endl;
	}
};

class hams : public cat
{
public:
	void Type()
	{
		cout << "Type: hamsters"<<endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	
	cat a;
	a.Show();
	a.Sound();
	a.Speed();
	a.Type();
	
	system("pause");
	return 0;
}
