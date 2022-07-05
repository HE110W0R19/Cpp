#pragma once
#include <iostream>
#include <string>

template<typename some_type>
class Iterator {
	some_type* cur;//указатель на текущий элемент контейнера
public:
	Iterator(some_type* ptr) :cur(ptr) {}
	//реализация доступа к элементу
	some_type& operator*() { return *cur; }
	some_type* operator->() { return cur; }
	//реализация перехода от одного к другому
	Iterator& operator++() { ++cur; return *this; }//next
	//сравнение итераторов
	bool operator!=(const Iterator& next) { return next.cur != cur; }
	bool operator<(const Iterator& next) { return cur < next.cur; }

};

template<typename some_type>
class conteiner {
	some_type* mass;//контейнер в виде массива
	int size;
public:
	conteiner(int s = 10) :size(10) {
		mass = new some_type[size];
	}
	void show() const {
		for (int i = 0; i < size; ++i)
		{
			std::cout << i << " ";
			std::cout << mass[i];
		}
	}

	Iterator<some_type> start() { return Iterator<some_type>(mass); }//получение итератора на первый элемент
	Iterator<some_type> finish() { return Iterator<some_type>(mass + size); }//получение итератора на элемент ЗА последний
	Iterator<some_type> create() { return Iterator<some_type>(mass); }
};

int iter() {
	conteiner<int> ABC;
	ABC.show();
	for (Iterator<int> a = ABC.start(); a != ABC.finish(); ++a)
		std::cout << *a << " ";
	std::cout << std::endl;
	return 0;
}

/*
+
 Упрощает классы хранения данных.
 Позволяет реализовать различные способы обхода структуры данных.
 Позволяет одновременно перемещаться по структуре данных в разные стороны.
- 
 Не оправдан, если можно обойтись простым циклом.
*/