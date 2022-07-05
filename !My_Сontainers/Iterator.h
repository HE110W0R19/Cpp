#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

namespace Test {
	class element {
		int x;
	public:
		element* next;
		element* prev;
		element(int a = 0) :x(a), next(NULL), prev(NULL) { };
		int get() const { return x; }
		int& get() { return x; }
		void set(int a = 0) { x = a; }
	};

	class list {
		element* head = NULL;
		element* tail = NULL;
		int SIZE;
	public:
		list() :SIZE(0) {}
		~list() { Clear(); }
		void Clear() {};
		void add(int x = -1);
		bool find(int x);
		int size() { return SIZE; }
		void print();
		//1. удаление конкретного элемента
		//2. добавление в начало списка
		//3. функтор поиска максимума
		//4. перегрузить в итераторе -- и -
		class Iterator {
			element* curr;
		public:
			Iterator(element* c) :curr(c) {}
			int operator*() const { return curr->get(); }
			element* operator->() const { return curr; }
			int& operator*() { return curr->get(); }
			element* operator->() { return curr; }
			element* operator+(int x) {
				element* el = curr;
				while (el->next && x--) {
					el = el->next;
				}
				curr = x == 0 ? el : el + 1;
				return curr;
			}
			element* operator++() { return curr->next ? curr = curr->next : (curr = curr + 1); }
			element* operator++(int x) {
				element* el = curr;
				curr->next ? curr = curr->next : (curr = curr + 1);
				return el;
			}

			bool operator!=(Iterator& lt) { return curr != lt.curr; }
			bool operator==(Iterator& lt) { return curr == lt.curr; }
			bool operator<(Iterator& lt) { return curr < lt.curr; }
		};
		Iterator begin() { return head; };
		Iterator end() { return tail + 1; };
	};
	template<class T>
	class IteratorMassiv {
		T* elem;
	public:
		IteratorMassiv(T* el) :elem(el) {}
		T operator*()const { return *elem; }
		T* operator->()const { return elem; }
		bool operator==(const IteratorMassiv<T>& it)const { return elem == it.elem; }
		bool operator!=(const IteratorMassiv<T>& it)const { return elem != it.elem; }
		IteratorMassiv& operator++() { ++elem; return *this; }
		IteratorMassiv operator++(int) {
			IteratorMassiv copy(*this);
			++elem;
			return copy;
		}
	};
	template<class T>
	IteratorMassiv<T> Begin(T* mas) { return IteratorMassiv(mas); }
	template<class T>
	IteratorMassiv<T> End(T* mas) { return IteratorMassiv(mas); }

}