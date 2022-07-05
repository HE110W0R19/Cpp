#pragma once
#include <map>
#include "Basic.h"
#include <memory>

class BasicDecorator :public File {
protected:
	unique_ptr<File> file;
	vector<string> content;
	void prepareHTML(string& txt);
public:
	BasicDecorator(unique_ptr<File> f) :file(f.release()) {
		if (!file)
			throw;
	}
	virtual void openFile(const string&) override;
	virtual void display() override;
	virtual vector<string>&& getContent() override;
};
inline void BasicDecorator::openFile(const string& name)
{
	file->openFile(name);
	content = file->getContent();
}
void BasicDecorator::display()
{
	ofstream out("1.html");
	if (!out.is_open())
		return;
	out << "<html><head></head><body>";
	for (auto iter = content.begin(); iter != content.end(); ++iter) {
		prepareHTML(*iter);
		out << *iter <<"<br/>";
	}
	out << "</body></html>";
}
inline vector<string>&& BasicDecorator::getContent()
{
	if (content.empty())
		return file->getContent();
	return move(content);
}
 void BasicDecorator::prepareHTML(string& txt)
{
	map<string, string> Dict;
	Dict["<"] = "&lt;";
	Dict[">"] = "&gt;";
	Dict["\""] = "&quot;";
	Dict["\'"] = "&apos;";
	for (auto& value : Dict) {
		while (txt.find(value.first) != string::npos) {
			txt.replace(txt.find(value.first),1, value.second);
		}
	}
}

 class LineDecor :public BasicDecorator {
 public:
	 LineDecor(unique_ptr<File> f) :BasicDecorator(move(f)) {}
	 void display() override;
 };
 void LineDecor::display()
 {
	 ofstream out("2.html");
	 if (!out.is_open())
		 return;
	 out << "<html><head></head><body>";
	 for (int i = 0; i!=content.size(); ++i) {
		 prepareHTML(content.at(i));
		 out<<i+1<<"| &nbsp;&nbsp;&nbsp;" << content.at(i) << "<br/>";
	 }
	 out << "</body></html>";
 }