#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <stack>
#include <windows.h>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <filesystem>

using namespace std;
random_device Rand;

class worker
{
public:
	string name = "";
	string function = "";
	int age = 0;
	int salary = 0;
	worker(string N, string F, uint16_t A, uint32_t S)
		: name(N), function(F), age(A), salary(S) {};

	friend ostream& operator<<(ostream& os, const worker& tmp)
	{
		os << tmp.name << " " << tmp.function
			<< " " << tmp.age << " " << tmp.salary << endl;
		return os;
	};
	bool operator<(const worker& tmp) const
	{
		return salary > tmp.salary;
	};
	int operator+=(int tmp)
	{
		return tmp+=salary;
	}
	bool operator==(const string& tmp) const
	{
		if (name == tmp)
		{
			cout << "Finded: " << name << " " << function
				<< " " << age << " " << salary << endl;
		}
		else
		{
			cout << "Not find!" << endl;
		}
		return name == tmp;
	};

};

class office
{
protected:
	vector<worker> workers = {};
	string f_name = "";
	string f_way = "";
	string buff = "";
public:
	office();
	void worker_add();
	void worker_delete();
	void worker_find();
	void worker_find_MAX_MIN();
	void worker_all_salary();
	void sort_salary();
	void sort_name();
	void salary_index();
	void office_save();
};

office::office()
{
	try
	{
		ifstream fin;
		cout << "Enter file way: ";
		cin >> f_way;
		cout << "Enter file name: ";
		cin >> f_name;
		std::filesystem::current_path(f_way);
		fin.open(f_name);
		while (!fin.eof())
		{
			getline(fin, buff);
			string n = buff.substr(0, buff.find_first_of(" "));
			buff.erase(0, n.size() + 1);
			string f = buff.substr(0, buff.find_first_of(" "));
			buff.erase(0, f.size() + 1);
			int a = stoi(buff.substr(0, buff.find_first_of(" ")));
			buff.erase(0, buff.find_first_of(" "));
			int s = stoi(buff.substr(0, buff.find_first_of("\0")));
			workers.emplace_back(n, f, a, s);
		}
		for (auto& tmp : workers)
		{
			cout << tmp;
		}
	}
	catch (std::exception& _ex)
	{
		cout << "Error: " << _ex.what() << endl;
	}
}

void office::worker_add()
{
	cout << "Enter name: ";
	string n; cin >> n;
	cout << "Enter function: ";
	string f; cin >> f;
	cout << "Enter age: ";
	int a; cin >> a;
	cout << "Enter salary: ";
	int s; cin >> s;
	workers.emplace_back(n, f, a, s);
}

void office::worker_delete()
{
	cout << "Enter name: ";
	cin >> buff;
	auto rem = remove(workers.begin(), workers.end(), buff);
	if (rem != workers.end())
	{
		workers.erase(rem, workers.end());
	}
}

void office::worker_find()
{
	string bu;
	cout << "Enter find person: ";
	cin >> bu;
	find(workers.begin(), workers.end(), bu);
}

void office::worker_find_MAX_MIN()
{
	auto MIN_MAX = minmax_element(workers.begin(), workers.end(),
		[](worker& a, worker& b) {return a.salary < b.salary; });
	cout << "Min salary: " << *MIN_MAX.first;
	cout << "Max salary: " << *MIN_MAX.second;
}

void office::worker_all_salary()
{
	auto all_salary = accumulate(workers.begin(), workers.end(), 0,
		[](int a, const worker& b)
		{
			return a + b.salary;
		});
	cout << "All salary: " << all_salary << endl;
}

void office::sort_salary()
{

	sort(workers.begin(), workers.end());
	for (auto& tmp : workers)
	{
		cout << tmp;
	}
	cout << "Sorted!" << endl;
	ofstream fout;
	fout.open(f_name);
	for (auto& tmp : workers)
	{
		fout << tmp;
	}
	cout << "File saved!" << endl;
	fout.close();
}

void office::sort_name()
{
	sort(workers.begin(), workers.end(),
		[](worker& a, worker& b) {return a.name < b.name; });
	for (auto& tmp : workers)
	{
		cout << tmp;
	}
	cout << "Sorted!" << endl;
	ofstream fout;
	fout.open(f_name);
	for (auto& tmp : workers)
	{
		fout << tmp;
	}
	cout << "File saved!" << endl;
	fout.close();
}

void office::salary_index()
{
	cout << "Enter name: " << endl;
	cin >> buff;
	for (int i = 0; i < workers.size(); ++i)
	{
		if (workers[i].name == buff)
		{
			workers[i].salary =
				workers[i].salary + (workers[i].salary * 0, 075);
			break;
		}
	}
}

void office::office_save()
{
	try
	{
		ofstream fout;
		fout.open(f_name);
		for (auto& tmp : workers)
		{
			fout << tmp;
		}
		cout << "File saved!" << endl;
		fout.close();
	}
	catch (std::exception& _ex)
	{
		cout << "Error: " << _ex.what() << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	office my_of;
	my_of.worker_all_salary();
	system("pause");
	return 0;
}