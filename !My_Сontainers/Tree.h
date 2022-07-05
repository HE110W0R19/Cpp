#pragma once
#include <iostream>
using namespace std;
struct elem {
	elem* rootEl = nullptr;
	elem* left = nullptr, * right = nullptr;
	int value;
};
class Tree {
	elem* root;
public:
	Tree() { root = nullptr; }
	//~Tree();
	void addToTree(int x);
	void addToTree(elem* x, elem* insert);
	bool find(int x);
	int max();
	int min();
	void print()const {
		if (!root)return;
		print(root->left);
		cout << root->value << endl;

		print(root->right);
	}
	void print(elem* El) const {
		if (!El)return;
		print(El->left);
		cout << El->value << endl;

		print(El->right);
	}
};

//void Tree::addToTree(int x) {
//	elem* newEl = new elem;
//	newEl->value = x;
//	if (!root) {
//		root = newEl;
//	}
//	else {
//		elem* curEl=root,*tmp; 
//		do {
//			tmp = curEl;
//			if (curEl->value <= newEl->value) {
//				curEl=curEl->right;
//			}
//			else {
//				curEl=curEl->left;
//			}
//		} while (curEl);
//		newEl->rootEl = tmp;
//		if (tmp->value <= newEl->value) {
//			tmp->right = newEl;
//		}
//		else {
//			tmp->left = newEl;
//		}
//	}
//
//}
void Tree::addToTree(int x) {

	elem* newEl = new elem;
	newEl->value = x;
	if (!root) {
		root = newEl;
		return;
	}
	addToTree(newEl, root);
}
void Tree::addToTree(elem* x, elem* insert)
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
bool Tree::find(int x) {
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
int Tree::max() {
	elem* curEl = root;
	while (curEl->right) {
		curEl = curEl->right;
	}
	return curEl->value;
}
int Tree::min() {
	elem* curEl = root;
	while (curEl->left) {
		curEl = curEl->left;
	}
	return curEl->value;
}