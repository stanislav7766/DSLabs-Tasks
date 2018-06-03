#ifndef deleteNode_h
#define deleteNode_h

#include "ClassTree.h"

template<typename T>
int BinaryTree<T>::deleteNode(T data) {
	deleted = false;
	Node<T> *temp = find(data);
	if (!root || !temp) return 0;
	if (data == root->data) deleteRoot(temp);
	else deleteNodeHelper(temp);
	if (root && find(data)) {
		deleted = false;
		deleteNode(data);
	}
	else return 1;
}


template<typename T>
void BinaryTree<T>::deleteNodeHelper(Node<T>* temp) {
	if (!deleted && !temp->pright && !temp->pleft) {
		deleteWithoutTwo(temp);
	}
	if (!deleted && !temp->pright) {
		deleteWithoutPright(temp);
	}
	if (!deleted && !temp->pleft) {
		deleteWithoutPleft(temp);
	}
	if (!deleted && temp->pright && temp->pleft) {
		deleteWithTwo(temp);
	}
}

template<typename T>
void BinaryTree<T>::deleteWithoutPright(Node<T>* temp) {
	Node<T>* parent = temp->parent;
	if (temp->data <= temp->parent->data) parent->pleft = temp->pleft;
	else parent->pright = temp->pleft;
	temp->pleft->parent = parent;
	delete temp;
	deleted = true;
	Size--;
}

template<typename T>
void BinaryTree<T>::deleteWithoutTwo(Node<T>* temp) {
	Node<T>* parent = temp->parent;
	if (parent->pleft == temp) parent->pleft = nullptr;
	else parent->pright = nullptr;
	delete temp;
	deleted = true;
	Size--;
}
template<typename T>
void BinaryTree<T>::deleteRoot(Node<T>* temp) {
	deleted = false;
	if (!temp->pright && !temp->pleft) {
		root = nullptr; Size--; return;
	}
	if (!temp->pright) {
		temp = temp->pleft;
		while (temp->pright) temp = temp->pright;
		root->data = temp->data;
		deleteNodeHelper(temp);
	}
	else {
		temp = temp->pright;
		while (temp->pleft) temp = temp->pleft;
		root->data = temp->data;
		deleteNodeHelper(temp);
	}
}


template<typename T>
void BinaryTree<T>::deleteWithTwo(Node<T>* temp) {
	Node<T>* exchange = temp;
	exchange = exchange->pright;
	while (exchange->pleft) exchange = exchange->pleft;
	temp->data = exchange->data;
	if (!exchange->pright && !exchange->pleft) deleteWithoutTwo(exchange);
	else deleteWithoutPleft(exchange);
	deleted = true;
}


template<typename T>
void BinaryTree<T>::deleteWithoutPleft(Node<T>* temp) {
	Node<T>* parent = temp->parent;
	if (temp->data >= temp->parent->data) parent->pright = temp->pright;
	else parent->pleft = temp->pright;
	temp->pright->parent = parent;
	delete temp;
	deleted = true;
	Size--;
}
#endif 