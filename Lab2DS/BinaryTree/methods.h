#ifndef methods_h
#define methods_h

#include <iostream>
#include "ClassTree.h"
#include "deleteNode.h"
#include <stdio.h>

using namespace std;

template<typename T>
BinaryTree<T>::BinaryTree() {
	root = nullptr;
	Size = 0;
}

template<typename T>
BinaryTree<T>::~BinaryTree() {
	clear();
	cout << "cleared\n";
}
template<typename T>
void BinaryTree<T>::PrintTree(Node<T>* node, int indent)
{
	if (node) {
		if (node->pright) PrintTree(node->pright, indent + 4);
		if (indent) {
			for (int i = 0; i < indent; i++)cout << " ";
		}
		if (node->pright) {
			cout << "/\n";
			for (int i = 0; i < indent; i++) cout << " ";
		}
		cout << node->data << "\n ";
		if (node->pleft) {
			for (int i = 0; i < indent; i++) cout << " ";
			cout << "\\\n";
			PrintTree(node->pleft, indent + 4);
		}
	}
}

template<typename T>
void BinaryTree<T>::show()
{
	Node<T> *node = root;
	PrintTree(node, 0);
}
template<typename T>
void BinaryTree<T>::push(T data) {
	if (!root) { setRoot(data); return; }
	Node<T> *node = new Node<T>;

	node->data = data;
	node->pleft = nullptr;
	node->pright = nullptr;
	Node<T>* curr = root;
	while (curr) {
		node->parent = curr;
		if (node->data >= curr->data) curr = curr->pright;
		else curr = curr->pleft;
	}
	if (node->data < node->parent->data) node->parent->pleft = node;
	else node->parent->pright = node;
	Size++;
}

template<typename T>
void BinaryTree<T>::symmetricOrder(Node<T> *node, T *arr) {
	if (node) {
		symmetricOrder(node->pleft, arr);
		symmetricOrderHelper(node, arr);
		symmetricOrder(node->pright, arr);
	}
}


template<typename T>
void BinaryTree<T>::symmetricOrderHelper(Node<T> *node, T *arr) {
	//cout << node->data << "  ,";
	arr[index] = node->data;
	index++;
}


template<typename T>
void BinaryTree<T>::copyToArr(T *arr) {
	Node<T> *cur = root;
	symmetricOrder(cur, arr);
}

template<typename T>
void BinaryTree<T>::clearHelper(Node<T> *node)
{
	if (!node) { cout << "A tree already empty\n"; return; }
	if (!node->pleft && !node->pright) {
		if (!node->parent) root = nullptr;
		else {
			int tmp = node->data;
			node = node->parent;
			if (node->pleft && node->pleft->data == tmp) node->pleft = nullptr;
			if (node->pright && node->pright->data == tmp) node->pright = nullptr;
			clearHelper(node);
		}
	}
	else {
		if (node->pleft) clearHelper(node->pleft);
		if (node->pright) clearHelper(node->pright);
	}
}


template<typename T>
void BinaryTree<T>::clear() {
	Node<T> *node = root;
	clearHelper(node);
}



template<typename T>
int BinaryTree<T>::maxCount(T* arr) {
	copyToArr(arr);
	int count = 1, tempCount;
	int popular = arr[0];
	int tempPopular = 0;
	for (int i = 0; i < (getSize() - 1); i++)
	{
		tempPopular = arr[i];
		tempCount = 0;
		for (int j = 1; j < getSize(); j++)
		{
			if (tempPopular == arr[j])
				tempCount++;
		}
		if (tempCount > count)
		{
			popular = tempPopular;
			count = tempCount;
		}
	}
	if (count > 1) {
		cout << "\nmax repeat " << popular << ":" << count << endl;
		delete arr;
		return popular;
	}
	else {
		delete arr;
		cout << "\nmax repeat is empty\n";
		return 0;
	}
}

template<typename T>
int BinaryTree<T>::minCount(T * arr) {
	copyToArr(arr);

	cout << "\nmin repeat\n";
	int countMin = 0;
	for (int i = 0; i < getSize(); ++i) {
		int count = 0;
		for (int j = 0; j < getSize(); ++j)
			if (i != j && arr[i] == arr[j])
				++count;
		if (!count) {
			cout << arr[i] << " ->";
			countMin++;
		}
	}
	cout<<  endl<<countMin;
	return countMin;
	cout << endl;

}


template<typename T>
void BinaryTree<T>::setRoot(T data) {
	root = new Node<T>;
	root->data = data;
	root->pleft = nullptr;
	root->pright = nullptr;
	root->parent = nullptr;
	Size++;
}

template<typename T>
void BinaryTree<T>::fillRandom() {

	if (!root) for (int i = 0; i < 15; i++) push(rand() % 198 - 99);
}

template<typename T>
Node<T>* BinaryTree<T>::find(T data)
{
	Node<T> * current = root;
	return findHelper(current, data);
}

template<typename T>
Node<T>* BinaryTree<T>::findHelper(Node<T>* current, T data)
{
	if (current == nullptr) return nullptr;
	if (current->data == data) return current;
	Node<T>* next;
	if (current->data <= data)  next = this->findHelper(current->pright, data);
	else  next = this->findHelper(current->pleft, data);
	if (next != nullptr) return next;
	return nullptr;
}

#endif 