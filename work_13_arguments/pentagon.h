#pragma once
#include <iostream>
//list
namespace lst
{
	struct DooElement {
		int value;
		DooElement* prev;
		DooElement* next;
		DooElement(int v) :value(v), next(nullptr), prev(nullptr) {}
	};
	class list {
		DooElement* Head = nullptr;
		DooElement* Tail = nullptr;
	public:
		~list();
		void add_to_front(int new_val);
		void add_to_end(int new_val);
		void display() const;
		void del_front();
		void del_end();
		int& find(int key);
	};
	void list::add_to_front(int new_val)
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
	void list::add_to_end(int new_val)
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
	void list::display() const
	{
		DooElement* current = Head;
		while (current) {
			std::cout << current->value << " ";
			current = current->next;
		}
		std::cout << "\n------next------\n";
	}

	void list::del_front()
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
	void list::del_end()
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
	list::~list() {
		while (Head) {
			del_front();
		}
	}
	int& list::find(int key)
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
}
//spisok
namespace spk
{
	class spisok {
	protected:
		struct element {
			int value = 0;//значение
			element* next = nullptr;//связь
		};
		element* start, * end;//Head, Tail
	public:
		spisok() :start(nullptr), end(nullptr) {}
		~spisok();
		void add(int val);//добавление в конец
		void del(int val);//удаление по значению
		void add(int val, int poz);//добавление по позиции
		void del_first();
		void print() {
			if (!start)
				return;
			element* current = start;
			do {
				std::cout << current->value << " ";
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
	spisok::~spisok()
	{
		while (start)
			del_first();
	}
	void spisok::add(int val, int poz)
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
				std::cout << "ALARM! add to end\n";
				end->next = newEl;
				end = newEl;
			}
			else {
				newEl->next = cur->next;
				cur->next = newEl;
			}
		}
	}
	void spisok::add(int val)
	{
		element* newEl = new element;
		newEl->value = val;
		if (!start) {
			start = end = newEl;
		}
		else
		{
			end->next = newEl;
			end = newEl;
		}
	}
	void spisok::del_first()
	{
		if (!start)
			return;
		element* del = start;
		start = start->next;
		delete del;
	}
	void spisok::del(int val)
	{
		if (!start)
			return;
		element* before = start;
		if (before->value == val)
			del_first();
		else {
			element* before_end = before;
			while (before->next && before->next->value != val) {
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
			int val = 0;
			elem* prev = nullptr, * next = nullptr;
		};
		elem* head = nullptr, * tail = nullptr;
	public:
		~DoubleSpisok() { while (tail)del(); };
		void add(int val, int poz = 0);
		void del(int poz = -1);
		friend std::ostream& operator<<(std::ostream& os, const DoubleSpisok& d) {
			DoubleSpisok::elem* el = d.head;
			while (el)
			{
				os << el->val << " ";
				el = el->next;
			}
			os << std::endl;
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
			if (tail) tail->next = nullptr;
			delete del;
		}
		else if (poz == 0) {
			elem* del = head;
			head = head->next;
			if (head) head->prev = nullptr;
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
}
//stack
namespace stk
{
	class stack {
		std::string* st;
		const size_t size;
		size_t cur_size;
	public:
		stack(int s = 10) :size(s), cur_size(0) {
			st = new std::string[size];
		}
		~stack() { delete[] st; }
		void push(std::string value);
		void pop();
		std::string show();
		bool isFull() { return cur_size == size; }
		bool empty() { return cur_size == 0; }
	};
	void stack::push(std::string value)
	{
		if (cur_size == size)
			return;
		st[cur_size] = value;
		cur_size++;
	}
	void stack::pop()
	{
		if (cur_size == 0)
			return;
		--cur_size;
	}
	std::string stack::show()
	{
		return cur_size ? st[cur_size - 1] : 0;
	}
}
//tree
namespace tre
{
	struct elem {
		elem* rootEl = nullptr;
		elem* left = nullptr, * right = nullptr;
		int value;
	};
	class tree {
		elem* root;
	public:
		tree() { root = nullptr; }
		void addToTree(int x);
		void addToTree(elem* x, elem* insert);
		bool find(int x);
		int max_el();
		int min_el();
		void print()const {
			if (!root)return;
			print(root->left);
			std::cout << root->value << std::endl;

			print(root->right);
		}
		void print(elem* El) const {
			if (!El)return;
			print(El->left);
			std::cout << El->value << std::endl;

			print(El->right);
		}
	};
	void tree::addToTree(int x) {

		elem* newEl = new elem;
		newEl->value = x;
		if (!root) {
			root = newEl;
			return;
		}
		addToTree(newEl, root);
	}
	void tree::addToTree(elem* x, elem* insert)
	{
		if (!x || !insert)
			return;
		if (insert->value <= x->value) {
			if (insert->right)
				addToTree(x, insert->right);
			else {
				x->rootEl = insert;
				insert->right = x;
			}
		}
		else {
			if (insert->left)
				addToTree(x, insert->left);
			else {
				x->rootEl = insert;
				insert->left = x;
			}
		}

	}
	bool tree::find(int x) {
		elem* curEl = root;
		do {
			if (curEl->value == x)
				return true;
			else if (curEl->value <= x) {
				curEl = curEl->right;
			}
			else {
				curEl = curEl->left;
			}
		} while (curEl);
		return false;
	}
	int tree::max_el() {
		elem* curEl = root;
		while (curEl->right) {
			curEl = curEl->right;
		}
		return curEl->value;
	}
	int tree::min_el() {
		elem* curEl = root;
		while (curEl->left) {
			curEl = curEl->left;
		}
		return curEl->value;
	}
}