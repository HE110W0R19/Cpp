#include <iostream>
#include <random>
#include <string.h>
#include <vector>
#include <windows.h>
#include <map>
#include <queue>

using namespace std;
random_device Rand;

struct elem
{
	elem* right = nullptr;
	elem* left = nullptr;
	vector<string> fals;
	string key_elem;
};

class police
{
	elem* root = nullptr;
public: 
	~police();
	void add_elem(const string& num, const string& fal);
	void print() const;
	void print_num(const string& num);
};

void police::add_elem(const string& num, const string& fal)
{
	elem* NewElem=nullptr;
	if (num == root->key_elem)
	{
		root->fals.emplace_back(fal);
	}
	else
	{
		elem* tmp = root;
		while (tmp)
		{
			if (tmp->key_elem == num)
			{
				tmp->fals.emplace_back(fal);
				delete NewElem;
				break;
			}
			else if (tmp->key_elem < num)
			{
				if (tmp->right)
				{
					tmp = tmp->right;
				}
				else
				{
					tmp->right = NewElem;
					NewElem->fals.emplace_back(fal);
					break;
				}
			}
			else if (tmp->key_elem > num)
			{
				if (tmp->left)
				{
					tmp = tmp->left;
				}
				else
				{
					tmp->left = NewElem;
					NewElem->fals.emplace_back(fal);
					break;
				}
			}
		}
	}
}

void police::print() const
{
	
}

void police::print_num(const string& num)
{

}

police::~police()
{

}

int main()
{
	setlocale(LC_ALL, "Rus");
	
	
	system("pause");
	return 0;
}