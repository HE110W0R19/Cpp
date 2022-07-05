#include <iostream>
#include <random>
#include <string.h>
#include <windows.h>
#include <fstream>

using namespace std;
random_device Rand;


class users
{
public:
	char full_name[30];
	char mobile_phone[12];
	char home_phone[12];
	char work_phone[12];
public:
	users()
	{
		*full_name = 0;
		*mobile_phone = 0;
		*home_phone = 0;
		*work_phone = 0;
	}
};

class book
{
	int add_poz = 0;
	int rm_poz = 0;
public:
	int page_col = 20;
	int people_col = 0;
	users* phone_book = new users[page_col]{};
	book();
	void book_print(users* mas, size_t people_col);
	void add_user();
	void rm_user();
};

book::book()
{
	cout << "Enter first amount: ";
	cin >> people_col;
	for (int i = 0; i < people_col; i++)
	{
		cout << "-----Person " << i << "-----" << endl;
		cout << "Enter full name: " << endl;
		cin >> phone_book[i].full_name;
		cout << "Enter mob number: " << endl;
		cin >> phone_book[i].mobile_phone;
		cout << "Enter home number: " << endl;
		cin >> phone_book[i].home_phone;
		cout << "Enter work number: " << endl;
		cin >> phone_book[i].work_phone;
	}
}

void book::book_print(users* mas, size_t pages)
{
	for (int i = 0; i < pages; i++)
	{
		cout << "-----Person " << i << "-----" << endl;
		cout << "Full name: " << mas[i].full_name << endl;
		cout << "Mob phone: " << mas[i].mobile_phone << endl;
		cout << "Home phone: " << mas[i].home_phone << endl;
		cout << "Work phone: " << mas[i].work_phone << endl << endl;
	}
}

void book::add_user()
{
	cout << "Enter add pozition: ";
	cin >> add_poz;

	cout << "-----Person " << add_poz << "-----" << endl;
	cout << "Enter full name: " << endl;
	cin >> phone_book[add_poz].full_name;
	cout << "Enter mob number: " << endl;
	cin >> phone_book[add_poz].mobile_phone;
	cout << "Enter home number: " << endl;
	cin >> phone_book[add_poz].home_phone;
	cout << "Enter work number: " << endl;
	cin >> phone_book[add_poz].work_phone;

	book_print(phone_book, page_col);
}

void book::rm_user()
{
	cout << "Enter remove pozition: ";
	cin >> rm_poz;
	users* rm_book = new users[page_col];
	for (int i = 0; i < rm_poz; i++)
	{
		rm_book[i] = phone_book[i];
	}
	for (int i = rm_poz, j = rm_poz + 1; i < page_col; i++, j++)
	{
		rm_book[i] = phone_book[j];
		if (j > page_col)
		{
			break;
		}
	}
	for (int i = 0; i < page_col; i++)
	{
		phone_book[i] = rm_book[i];
	}
	delete[] rm_book;
	book_print(phone_book, page_col);
}

int main()
{
	setlocale(LC_ALL, "Rus");

	book one;
	int choise;
	while (true)
	{
		cout << "-------Menu-------\n1-print book"
			"\n2-add user\n3-del user\n4-exit" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
			system("cls");
			one.book_print(one.phone_book, one.page_col);
			break;
		case 2:
			system("cls");
			one.add_user();
			break;
		case 3:
			system("cls");
			one.rm_user();
			break;
		case 4:
			system("cls");
			cout << "Good bye!" << endl;
			return 0;
			break;
		default:
			system("cls");
			cout << "Wrong choise! ;(" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}