#pragma once
#include <iostream>
using namespace std;

class Spisok {
protected:
	struct element{
		int value=0;//значение
		element* next=nullptr;//связь
	};
	element* start, *end;//Head, Tail
public:
	Spisok() :start(nullptr), end(nullptr) {}
	~Spisok() ;
	void add(int val);//добавление в конец
	void del(int val);//удаление по значению
	void add(int val,int poz);//добавление по позиции
	void del_first();
	void print() {
		if (!start)
			return;
		element* current = start;
		do {
			cout << current->value << " ";
			current = current->next;
		} while (current);
	}
	bool find(int v) {
		element* cur = start;
		while (cur) {
			if (cur->value == v)
				return true;
			cur = cur->next;
		}
		return false;
	}
};

Spisok::~Spisok()
{
	while (start)
		del_first();
}
void Spisok::add(int val, int poz)
{
	element* newEl = new element;
	newEl->value = val;
	if (!start) {
		start = end = newEl;
	}
	else if (poz == 0) {
		newEl->next = start;
		start = newEl;
	}
	else
	{
		element* cur = start;
		while (--poz && cur->next) {
			cur = cur->next;
		}
		if (poz) {
			cout << "ALARM! add to end\n";
			end->next = newEl;
			end = newEl;
		}
		else {
			newEl->next = cur->next;
			cur->next = newEl;
		}
	}
}


void Spisok::add(int val)
{
	element* newEl = new element;
	newEl->value = val;
	if (!start) {
		start=end = newEl;
	}
	else
	{
		end->next = newEl;
		end = newEl;
	}
}
void Spisok::del_first()
{
	if (!start)
		return;
	element* del = start;
	start = start->next;
	delete del;
}

void Spisok::del(int val)
{
	if (!start)
		return;
	element* before = start;
	if (before->value == val)
		del_first();
	else {
		element* before_end = before;
		while ( before->next && before->next->value != val) {
			before_end = before;
			before = before->next;
		}
		if (before != end) {
			element* del = before->next;
			before->next = del->next;//before->next->next
			delete del;
		}
		else if (end->value == val) {
			end = before_end;
			before_end->next = nullptr;
			delete before;
		}
	}
}


class DoubleSpisok {
	struct elem {
		int val=0;
		elem *prev = nullptr, *next = nullptr;
	};
	elem *head=nullptr, *tail=nullptr;
public:
	~DoubleSpisok() { while (tail)del(); };
	void add(int val, int poz = 0);
	void del(int poz = -1);
	friend ostream& operator<<(ostream& os, const DoubleSpisok& d) {
		DoubleSpisok::elem* el = d.head;
		while (el)
		{
			os << el->val << " ";
			el = el->next;
		}
		os << endl;
		return os;
	}

	int operator[](int poz) {
		return head->val;
	}
};


void DoubleSpisok::del(int poz)
{
	if (!head)
		return;
	if (poz == -1) {
		elem* del = tail;
		tail = tail->prev;
		if(tail) tail->next = nullptr;
		delete del;
	}
	else if(poz==0) {
		elem* del = head;
		head = head->next;
		if(head) head->prev = nullptr;
		delete del;
	}
	else {
		elem* cur = head;
		while (--poz && cur->next) {
			cur = cur->next;
		}
		if (poz)
			return;
		elem* del = cur->next;
		if (!del)
			return;
		if (del == tail) {
			tail = tail->prev;
			tail->next = nullptr;
			delete del;
			return;
		}
		cur->next = del->next;
		del->next->prev = cur;
		delete del;
	}
}


void DoubleSpisok::add(int val, int poz)
{
	elem* newEl = new elem;
	newEl->val = val;
	if (!head)
		head = tail = newEl;
	else if (poz == 0) {
		head->prev = newEl;
		newEl->next = head;
		head = newEl;
	}
	else {
		elem* cur = head;
		while (cur->next && --poz)
			cur = cur->next;
		if (cur == tail) {
			tail->next = newEl;
			newEl->prev = tail;
			tail = newEl;
		}
		else {
			//elem* next = cur->next;
			newEl->next = cur->next;
			cur->next->prev = newEl;
			cur->next = newEl;
			newEl->prev = cur;
		}
	}
}