#include <iostream>
#include <math.h>
//#include <vector>
#include <iomanip>
#include <stdio.h>
#include <stdarg.h>
#ifndef problems_h
#define problems_h
#include "ClassTree.h"




template<typename T>
void BinaryTree<T>::filterMultipleN(int N) {// problem1  �������� ����� ������� N
	if (!root || N == 0) { cout << "Tree is empty!\n"; return; }//���� ������ �����, ��� N == 0(����� �� ����� ���� ������ 0), ������� �� ���������
	Node <T> * curr = root;//������ ��������� �� ������
	filterMultipleNHelper(curr, N);//�������� ������
	if (root->data % N != 0) deleteRoot(root);//�� ������� �� �������� ���� , �� ��������������� ��������� �� ������, � ����� ���������� ��������
	//� ������ ��� ����� ����� , �� �� ��������� ������, ��� � ��������:)
}
template<typename T>
void BinaryTree<T>::filterMultipleNHelper(Node<T> *curr, int N) {// ������ ��� problem1
	if (curr->data % N != 0) {//��������, ��� ������� ������, ���� �� N , ���� �� ������� �� �������, ���� ���� �������� � ��������
		if (curr) deleteNode(curr->data);//�������������� ��������, ���� ���� �� null, ������� ����
		curr = root;//����� �������� , ����� �������� ����� ������, ����������� ���� ������
		if (curr) {//���� ������ �� �����
			if (curr->pleft) filterMultipleNHelper(curr->pleft, N);//�� � ������� �������� , ��������� � ���������� ����, ��������� � ���� ��������� 
			if (curr->pright) filterMultipleNHelper(curr->pright, N);//�� ��� ������ ��� ������� ����
		}
	}
	else {
		if (curr->pright) filterMultipleNHelper(curr->pright, N);//�� �� ��������, ���� �� ������� � �������� if (curr->data % N != 0) {}
		if (curr->pleft) filterMultipleNHelper(curr->pleft, N);//

	}
}

template<typename T>
void BinaryTree<T>::filterOdd() {//problem2  ������� �������� �����
	if (!root) { cout << "Tree is empty!\n"; return; }
	Node <T> * curr = root;
	filterOddHelper(curr);
	if (root->data % 2 != 0) deleteRoot(root);
}
template<typename T>
void BinaryTree<T>::filterOddHelper(Node<T> *curr) {//������ ��� problem2
	if (curr->data % 2 != 0) {//���� ��� ������� �� 2, ������ ����, �� ����� ������ , � �� ��� �� �������
		if (curr) deleteNode(curr->data);
		curr = root;
		if (curr) {
			if (curr->pleft) filterOddHelper(curr->pleft);
			if (curr->pright) filterOddHelper(curr->pright);
		}
	}
	else {
		if (curr->pright) filterOddHelper(curr->pright);
		if (curr->pleft) filterOddHelper(curr->pleft);

	}
}

template<typename T>
void BinaryTree<T>::filterGreaterN(int N) {//problem3 �������� ����� > N
	if (!root) { cout << "Tree is empty!\n"; return; }
	Node <T> * curr = root;
	filterGreaterNHelper(curr, N);
	if (root->data < N) deleteRoot(root);
}
template<typename T>
void BinaryTree<T>::filterGreaterNHelper(Node<T> *curr, int N) {//������ ��� problem3
	if (curr->data < N) {// ���� ������ ���� ������ ��������� N, �� ������� ����
		if (curr) deleteNode(curr->data);
		curr = root;
		if (curr) {
			if (curr->pleft) filterGreaterNHelper(curr->pleft, N);
			if (curr->pright) filterGreaterNHelper(curr->pright, N);
		}
	}
	else {
		if (curr->pright) filterGreaterNHelper(curr->pright, N);
		if (curr->pleft) filterGreaterNHelper(curr->pleft, N);

	}
}
template<typename T>
void BinaryTree<T>::filterLessN(int N) {//problem4 �������� ����� < N
	if (!root) { cout << "Tree is empty!\n"; return; }
	Node <T> * curr = root;
	filterLessNHelper(curr, N);
	if (root->data > N) deleteRoot(root);
}
template<typename T>
void BinaryTree<T>::filterLessNHelper(Node<T> *curr, int N) {//������ ��� problem4
	if (curr->data > N) {// ���� ������ ���� ������ ��������� N, �� ������� ����
		if (curr) deleteNode(curr->data);
		curr = root;
		if (curr) {
			if (curr->pleft) filterLessNHelper(curr->pleft, N);
			if (curr->pright) filterLessNHelper(curr->pright, N);
		}
	}
	else {
		if (curr->pright) filterLessNHelper(curr->pright, N);
		if (curr->pleft) filterLessNHelper(curr->pleft, N);

	}
}

template<typename T>
void BinaryTree<T>::delete_choosen(std::vector<T> &choose) {//problem5 �������� ����� �� ������, �� ���� ������� ���� ,
	if (!root) { cout << "Tree is empty!\n"; return; }// ������ ,������� ��� � ������������ �������
	Node <T> * curr = root;
	delete_choosenHelper(curr, choose);
	if (!deletechoosen(choose, curr->data)) deleteRoot(root);
}
template<typename T>
void BinaryTree<T>::delete_choosenHelper(Node<T> *curr, std::vector<T>&choose) {//������ ��� problem5
	if (!deletechoosen(choose, curr->data)) {// ������� ��� �������� , ���� �� ������ ���� � �������, ���� ����, �� ������� ���� 
		if (curr) deleteNode(curr->data);
		curr = root;
		if (curr) {
			if (curr->pleft) delete_choosenHelper(curr->pleft, choose);
			if (curr->pright) delete_choosenHelper(curr->pright, choose);
		}
	}
	else {
		if (curr->pright) delete_choosenHelper(curr->pright, choose);
		if (curr->pleft) delete_choosenHelper(curr->pleft, choose);

	}
}


template<typename T>
void BinaryTree<T>::filterPrime() {//problem6 �������� ������� �����
	if (!root) { cout << "Tree is empty!\n"; return; }
	Node <T> * curr = root;
	filterPrimeHelper(curr);
	if (!PrimeNumber(root->data)) deleteRoot(root);
}
template<typename T>
void BinaryTree<T>::filterPrimeHelper(Node<T> *curr) {// ������ ��� problem6
	if (!PrimeNumber(curr->data)) { // ��������� � ������� ��� �������� ������� �� �����, ���� �� ������� , ������� ����
		if (curr) deleteNode(curr->data);
		curr = root;
		if (curr) {
			if (curr->pleft) filterPrimeHelper(curr->pleft);
			if (curr->pright) filterPrimeHelper(curr->pright);
		}
	}
	else {
		if (curr->pright) filterPrimeHelper(curr->pright);
		if (curr->pleft) filterPrimeHelper(curr->pleft);

	}
}

template<typename T>
void BinaryTree<T>::filterNotPrime() {//problem7 �������� ��������� �����
	if (!root) { cout << "Tree is empty!\n"; return; }
	Node <T> * curr = root;
	filterNotPrimeHelper(curr);
	if (PrimeNumber(root->data)) deleteRoot(root);
}
template<typename T>
void BinaryTree<T>::filterNotPrimeHelper(Node<T> *curr) {//������ ��� problem7
	if (PrimeNumber(curr->data)) {// ��������� � ������� ��� �������� ������� �� �����, ���� ������� , ������� ����
		if (curr) deleteNode(curr->data);
		curr = root;
		if (curr) {
			if (curr->pleft) filterNotPrimeHelper(curr->pleft);
			if (curr->pright) filterNotPrimeHelper(curr->pright);
		}
	}
	else {
		if (curr->pright) filterNotPrimeHelper(curr->pright);
		if (curr->pleft) filterNotPrimeHelper(curr->pleft);

	}
}


template<typename T>
void BinaryTree<T>::filterInterval(int X, int Y) {//problem8 �������� ����� � ��������� �� X �� Y
	if (!root) { cout << "Tree is empty!\n"; return; }
	Node <T> * curr = root;
	filterIntervalHelper(curr, X, Y);
	if (!(curr->data <= Y && curr->data >= X)) deleteRoot(root);
}
template<typename T>
void BinaryTree<T>::filterIntervalHelper(Node<T> *curr, int X, int Y) {//������ ��� problem8
	if (!(curr->data <= Y && curr->data >= X)) {// ���� ������ ���� ������ � � ������ Y, �� ������ ����
		if (curr) deleteNode(curr->data);
		curr = root;
		if (curr) {
			if (curr->pleft) filterIntervalHelper(curr->pleft, X, Y);
			if (curr->pright) filterIntervalHelper(curr->pright, X, Y);
		}
	}
	else {
		if (curr->pright) filterIntervalHelper(curr->pright, X, Y);
		if (curr->pleft) filterIntervalHelper(curr->pleft, X, Y);

	}
}

template<typename T>
void BinaryTree<T>::filterSumOfFigureGreaterN(int N) {	//problem9 �������� �����, ����� ���� (�� ������) �������� > N
	if (!root) { cout << "Tree is empty!\n"; return; } 
	Node <T> * curr = root;
	filterSumOfFigureGreaterNHelper(curr, N);
	if (f(curr->data)<= N) deleteRoot(root);
}

template<typename T>
void BinaryTree<T>::filterSumOfFigureGreaterNHelper(Node<T> *curr, int N) {//������ ��� problem9
	if (f(curr->data)<= N) { // ��������� � �������, ��� ���������� ����� ���� �� ������,  ��� ����� ��������, 
		if (curr) deleteNode(curr->data);//���� ����� ������ ��� ����� ��������� N, �� ������� ����
		curr = root;
		if (curr) {
			if (curr->pleft) filterSumOfFigureGreaterNHelper(curr->pleft, N);
			if (curr->pright) filterSumOfFigureGreaterNHelper(curr->pright, N);
		}
	}
	else {
		if (curr->pright) filterSumOfFigureGreaterNHelper(curr->pright, N);
		if (curr->pleft) filterSumOfFigureGreaterNHelper(curr->pleft, N);

	}
}	

template<typename T>
void BinaryTree<T>::filterSumOfFigureLessN(int N) {//problem10 �������� �����, ����� ���� (�� ������) �������� < N
	if (!root) { cout << "Tree is empty!\n"; return; }
	Node <T> * curr = root;
	filterSumOfFigureLessNHelper(curr, N);
	if (f(curr->data)>= N) deleteRoot(root);
}
template<typename T>
void BinaryTree<T>::filterSumOfFigureLessNHelper(Node<T> *curr, int N) {//������ ��� problem10
	if (f(curr->data)>= N) {// ��������� � �������, ��� ���������� ����� ���� �� ������,  ��� ����� ��������, 
		if (curr) deleteNode(curr->data);//���� ����� ������ ��� ����� ��������� N, �� ������� ����
		curr = root;
		if (curr) {
			if (curr->pleft) filterSumOfFigureLessNHelper(curr->pleft, N);
			if (curr->pright) filterSumOfFigureLessNHelper(curr->pright, N);
		}
	}
	else {
		if (curr->pright) filterSumOfFigureLessNHelper(curr->pright, N);
		if (curr->pleft) filterSumOfFigureLessNHelper(curr->pleft, N);

	}
}

template<typename T>
void BinaryTree<T>::filterSumOfFigureInterval(int X, int Y) {//problem11 �������� �����, ����� ���� (�� ������) 
	if (!root) { cout << "Tree is empty!\n"; return; }//�������� ����� � ��������� �� X �� Y
	Node <T> * curr = root;
	filterSumOfFigureIntervalHelper(curr, X,Y);
	if (!(f(curr->data) <= Y && f(curr->data) >= X)) deleteRoot(root);
}

template<typename T>
void BinaryTree<T>::filterSumOfFigureIntervalHelper(Node<T> *curr, int X, int Y) {// ������ ��� problem11
	if (!(f(curr->data) <= Y && f(curr->data) >= X)) {//��������� � �������, ��� ���������� ����� ���� �� ������,  ��� ����� ��������
		if (curr) deleteNode(curr->data);// ���� ������ ������ � � ������ Y, �� ������� ����
		curr = root;
		if (curr) {
			if (curr->pleft) filterSumOfFigureIntervalHelper(curr->pleft, X,Y);
			if (curr->pright) filterSumOfFigureIntervalHelper(curr->pright, X,Y);
		}
	}
	else {
		if (curr->pright) filterSumOfFigureIntervalHelper(curr->pright, X,Y);
		if (curr->pleft) filterSumOfFigureIntervalHelper(curr->pleft, X,Y);
	}
}


template<typename T>
void BinaryTree<T>::filterSqrtNumInt() {//problem12 �������� �����, ������ �� ������, ���������� ������ ������� ����� �����
	if (!root) { cout << "Tree is empty!\n"; return; }
	Node <T> * curr = root;
	filterSqrtNumIntHelper(curr);
	if (f2(curr->data)) deleteRoot(root);
}

template<typename T>
void BinaryTree<T>::filterSqrtNumIntHelper(Node<T> *curr) {//������ ��� problem12
	if (f2(curr->data)) {// ��������� � ������� , ��� ��������� ����� �� ���������� ������ ����� ����� , ���� ���, ������� ����
		if (curr) deleteNode(curr->data);
		curr = root;
		if (curr) {
			if (curr->pleft) filterSqrtNumIntHelper(curr->pleft);
			if (curr->pright) filterSqrtNumIntHelper(curr->pright);
		}
	}
	else {
		if (curr->pright) filterSqrtNumIntHelper(curr->pright);
		if (curr->pleft) filterSqrtNumIntHelper(curr->pleft);
	}
}


template<typename T>
bool deletechoosen(std::vector<T> &choose, T data) {//������� ��� ����������� curr->data � ���������� �������, ���� ���� ����������, ���������� 1, ����� 0
	for (int i = 0; i < choose.size(); i++) if (choose[i] == data) return 1;
	return 0;
}

std::vector<int> setVector() {//������� ��� ��� ���������� ������� 5� ���������� ����������,
	std::vector<int> vec;
//	for (int i = 0; i < 5; i++) vec.push_back(rand() % 198 - 99);
	for (int i = 0; i < 5; i++) vec.push_back(i*i);
	return vec;
}

bool PrimeNumber(int number) {// ������� ��� �������� �������� �� ����� �������
	int i;
	bool isPrime = true;
	for (i = 2; i <= (sqrt(abs(number))); i++) {
		if (number%i == 0) {
			isPrime = false;
			break;
		}
	}
	if (isPrime) return 1;
	else return 0;
}

void parse(int n, std::vector<int> &vec) {// �������, ������� ������ ����� �� ������ ����
	vec.push_back(n % 10);// ��������� � ������ ������� �� ������� ����� �� 10(����� 321, ��������� 1)
	if (n > 0) {// �������� ��� ������ �� ������
		int temp = n / 10;// � ���� , �������� n/10
		if (temp == 0) return;// ���� ���� == 0, ������� �� �������
		parse(temp, vec);// ����������� �����
	}
	else {
		int temp = -1 *(n / 10);
		if (temp == 0) return;
		parse(temp, vec);
	}
}
int f(int data) {//������� , ��� ������ ����� ����, ����� 
	std::vector<int> vec;// ������� � ������� �������, ������ ������
	parse(data, vec);// ��������� � �������, ������� ������ ����� �� ������ ����
	int Sum =0;// ���������� ��� ����� ����
	for (int i = 0; i < (vec.size()); i++) Sum += vec[i];// � ������� ����� , ��������� , ����� ��������� ������� ����
	vec.clear();// (����� 321, ������:[1,2,3], ����� 6)
	return Sum;// ������ ��� �����
}

bool f2(int data) {//������� , ��� ��������� ����� �� ���������� ������ ����� �����
	double x = data;// �������� ���������� ��� �������� ������(�����)
	if (data > 0) {// ��������, ��� ������ �� ������
		if (floor(sqrt(x)) != sqrt(x)) { return 1; }//floor()- ��������� ����� � ������� ������� 
		else {return 0;}//, ���� ����� ����� ����� , �� ���������� ������ �� ���� � ��� ����� � ��� ����� �����,
	}//���� ���������� ������ ����� �����, ������ 0, ���� ���, 1
	else {
		x *= (-1);
		if (floor(sqrt(x)) != sqrt(x)) { return 1; }
		else {return 0;}
	}
}
#endif;
