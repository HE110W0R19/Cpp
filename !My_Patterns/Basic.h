#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>

using namespace std;
class File {
public:
	virtual void openFile(const string&) = 0;
	virtual void display() = 0;
	virtual vector<string>&& getContent() = 0;
};

class BasicFunctional : public File {
	vector<string> content;
public:
	virtual void openFile(const string&) override;
	virtual void display() override;
	virtual vector<string>&& getContent() override;
};

void BasicFunctional::display() {
	try {
		for (int i = 0; i < content.size(); ++i)
			cout << content.at(i) << endl;
	}
	catch (...) {
		cout << " some error in function:" << __FUNCTION__ << endl;
	}
}

vector<string>&& BasicFunctional::getContent()
{
	return move(content);
}

void BasicFunctional::openFile(const string& nameFile)
{
	if (!filesystem::exists(nameFile))
		return;
	ifstream file(nameFile);
	if (!file.is_open())
		return;
	string buff;
	while (!file.eof()) {
		buff = "";
		getline(file, buff);
		bool flag = file.fail();
		if (file.fail() && !file.eof() && buff.size() == 0) {
			file.clear();
			continue;
		}
		content.emplace_back(buff);
	}
}