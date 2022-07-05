#include <iostream>
#include <random>
#include <string.h>
#include <vector>
#include <windows.h>
#include <map>
using namespace std;
random_device Rand;

template<typename T>
class matrix
{
private:
	const int row;
	const int col;
	T** mas = new T * [col];

public:
	matrix();
	void add_num();
	void add_key();
	void print();
	void find_max();
	void find_min();
	matrix(const matrix&) = delete;
	~matrix();


};
template<typename T>
matrix<T>::matrix()
{
	for (int i = 0; i < col; i++)
	{
		mas[i] = new T[row];
	}
}

template<typename T>
void matrix<T>::add_num()
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0 ; j < row; j++)
		{
			mas[i][j] = Rand() % 10;
		}
	}
}

template<typename T>
void matrix<T>::add_key()
{
	system("cls");
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cout << i << "-line) "<<"Enter num : ";
			cin >> mas[i][j];
			cout << endl;
		}
	}
}

template<typename T>
void matrix<T>::print()
{
	system("cls");
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
}

template<typename T>
void matrix<T>::find_max()
{
	T* max = new T(mas[0][0]);
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (mas[i][j] > max)
			{
				max = mas[i][j];
			}
		}
	}
	cout << "Max number: " << max << endl;
	delete max;
}

template<typename T>
void matrix<T>::find_min()
{
	T* min = new T(mas[0][0]);
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (mas[i][j] < min)
			{
				min = mas[i][j];
			}
		}
	}
	cout << "Max number: " << min << endl;
	delete min;
}

template<typename T>
matrix<T>::~matrix()
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			mas[i][j] = nullptr;
		}
	}
	delete[] mas;
}

int main()
{
	setlocale(LC_ALL, "Rus");



	system("pause");
	return 0;
}