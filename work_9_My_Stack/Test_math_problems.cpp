#include <iostream>
#include <random>
#include <string.h>
#include "Stack.h"
#include <vector>
#include <windows.h>
#include <map>
#include <queue>


using namespace std;
random_device Rand;


int main()
{
	setlocale(LC_ALL, "Rus");
	
	string test1 = "({x-y-z}*[x+2y]-(z+4x));";
	string test2 = "([x-y-z}*[x+2y)-{z+4x)];";
	Stack<char> simbols(30);
	for (auto& sim : test1)
	{
		if (sim == '{' || sim == '(' || sim == '[' || sim == '<')
			simbols.push(sim);
		else if (sim == '}')
		{
			if (!simbols.empty() && simbols.show() == '{')
				simbols.pop();
		}
		else if (sim == ')') {
			if (!simbols.empty() && simbols.show() == '(')
				simbols.pop();
		}
		else if (sim == ']') {
			if (!simbols.empty() && simbols.show() == '[')
				simbols.pop();
		}
		else if (sim == '>') {
			if (!simbols.empty() && simbols.show() == '<')
				simbols.pop();
		}
	}
	cout << (!simbols.empty() ? " alarm" : "good") << endl;

	system("pause");
	return 0;
}