#include <iostream>
#include <random>
#include <string.h>
#include <windows.h>
#include <fstream>
#include "Пентагон.h"

std::random_device Rand;

int main()
{
	setlocale(LC_ALL, "Rus");
	lst::list tmp_list;
	spk::spisok tmp_spisok;
	stk::stack tmp_str_stack;
	tre::tree tmp_tree;
	
	//tree test
	std::cout << "-----TREE TEST----" << "\n";
	tmp_tree.addToTree(1);
	tmp_tree.addToTree(2);
	tmp_tree.addToTree(3);
	tmp_tree.print();
	std::cout << "Min elem: " << tmp_tree.min_el() << "\n";
	std::cout << "Max elem: " << tmp_tree.max_el() << "\n";
	
	//string stack test
	std::cout << "-----STRING STACK TEST----" << "\n";
	tmp_str_stack.push("1");
	std::cout << tmp_str_stack.show()<<"\n";
	
	//spisok test 
	std::cout << "-----SPISOK TEST----" << "\n";
	tmp_spisok.add(1);
	tmp_spisok.add(2);
	tmp_spisok.print();
	
	//list test 
	std::cout << "-----LIST TEST----" << "\n";
	tmp_list.add_to_front(1);
	tmp_list.add_to_front(2);
	tmp_list.display();
	system("pause");
	return 0;
}

