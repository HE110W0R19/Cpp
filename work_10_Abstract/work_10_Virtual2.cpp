
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
