#pragma once
#include <iostream>
using namespace std;
struct DooElement {
	int value;
	DooElement* prev;
	DooElement* next;
	DooElement(int v) :value(v), next(nullptr), prev(nullptr) {}
};

class List {
	DooElement* Head = nullptr;
	DooElement* Tail = nullptr;
public:
	~List();
	void add_to_front(int new_val);
	void add_to_end(int new_val);
	void display() const;
	void del_front();
	void del_end();
	int& find(int key);
};
void List::add_to_front(int new_val)
{
	DooElement* new_elem = new DooElement(new_val);
	if (!Head) {
		Head = Tail = new_elem;
	}
	else {
		new_elem->next = Head;
		Head->prev = new_elem;
		Head = new_elem;
	}
}
void List::add_to_end(int new_val)
{
	DooElement* new_elem = new DooElement(new_val);
	if (!Tail) {
		Head = Tail = new_elem;
	}
	else {
		new_elem->prev = Tail;
		Tail->next = new_elem;
		Tail = new_elem;
	}
}

void List::display() const
{
	DooElement* current = Head;
	while (current) {
		cout << current->value << " ";
		current = current->next;
	}
	cout << "\n------next------\n";
}

void List::del_front()
{
	if (Head == Tail) {
		if (Head) {
			delete Head;
			Head = Tail = nullptr;
		}
		return;
	}
	DooElement* del = Head;
	Head = Head->next;
	Head->prev = nullptr;
	delete del;
}

void List::del_end()
{
	if (Head == Tail) {
		if (Head) {
			delete Head;
			Head = Tail = nullptr;
		}
		return;
	}
	DooElement* del = Tail;
	Tail = Tail->prev;
	Tail->next = nullptr;
	delete del;
}

List::~List() {
	while (Head) {
		del_front();
	}
}
int& List::find(int key)
{
	DooElement* current = Head;
	while (current) {
		if (current->value == key) {
			return current->value;
		}
		current = current->next;
	}
	return Head->value;
}

struct tree_elem {
	int value;
	tree_elem* parent = nullptr;
	tree_elem* left = nullptr;
	tree_elem* right = nullptr;
	tree_elem(int val) :value(val) {}
};
