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
void BinaryTree<T>::filterMultipleN(int N) {// problem1  оставить числа кратные N
	if (!root || N == 0) { cout << "Tree is empty!\n"; return; }//Если дерево пусто, или N == 0(число не может быть кратно 0), выходим из программы
	Node <T> * curr = root;//делаем указатель на корень
	filterMultipleNHelper(curr, N);//вызываем хелпер
	if (root->data % N != 0) deleteRoot(root);//по скольку по удаления узла , мы переприсваивали указатель на корень, и после рекурсивно вызывали
	//с правым или левым сыном , мы не проверяли корень, вот и проверим:)
}
template<typename T>
void BinaryTree<T>::filterMultipleNHelper(Node<T> *curr, int N) {// хелпер для problem1
	if (curr->data % N != 0) {//проверка, при делении данных, узла на N , есть ли остаток от деления, если есть попадаем в контекст
		if (curr) deleteNode(curr->data);//дополнительная проверка, если узел не null, удаляем узел
		curr = root;//после удаления , может остаться мусор адреса, присваиваем узлу корень
		if (curr) {//если дерево не пусто
			if (curr->pleft) filterMultipleNHelper(curr->pleft, N);//то с помощью рекурсии , переходим к следующему узлу, передавая в узел указатель 
			if (curr->pright) filterMultipleNHelper(curr->pright, N);//на его левого или правого сына
		}
	}
	else {
		if (curr->pright) filterMultipleNHelper(curr->pright, N);//та же рекурсия, пока не попадем в контекст if (curr->data % N != 0) {}
		if (curr->pleft) filterMultipleNHelper(curr->pleft, N);//

	}
}

template<typename T>
void BinaryTree<T>::filterOdd() {//problem2  удалить Нечетные числа
	if (!root) { cout << "Tree is empty!\n"; return; }
	Node <T> * curr = root;
	filterOddHelper(curr);
	if (root->data % 2 != 0) deleteRoot(root);
}
template<typename T>
void BinaryTree<T>::filterOddHelper(Node<T> *curr) {//хелпер для problem2
	if (curr->data % 2 != 0) {//если при делении на 2, остача ноль, то число четное , и мы его не удаляем
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
void BinaryTree<T>::filterGreaterN(int N) {//problem3 оставить числа > N
	if (!root) { cout << "Tree is empty!\n"; return; }
	Node <T> * curr = root;
	filterGreaterNHelper(curr, N);
	if (root->data < N) deleteRoot(root);
}
template<typename T>
void BinaryTree<T>::filterGreaterNHelper(Node<T> *curr, int N) {//хелпер для problem3
	if (curr->data < N) {// если данные узла меньше заданного N, то удаляем узел
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
void BinaryTree<T>::filterLessN(int N) {//problem4 оставить Числа < N
	if (!root) { cout << "Tree is empty!\n"; return; }
	Node <T> * curr = root;
	filterLessNHelper(curr, N);
	if (root->data > N) deleteRoot(root);
}
template<typename T>
void BinaryTree<T>::filterLessNHelper(Node<T> *curr, int N) {//хелпер для problem4
	if (curr->data > N) {// если данные узла больше заданного N, то удаляем узел
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
void BinaryTree<T>::delete_choosen(std::vector<T> &choose) {//problem5 оставить Числа по выбору, то есть удалить узлы ,
	if (!root) { cout << "Tree is empty!\n"; return; }// данных ,которых нет в передаваемом массиве
	Node <T> * curr = root;
	delete_choosenHelper(curr, choose);
	if (!deletechoosen(choose, curr->data)) deleteRoot(root);
}
template<typename T>
void BinaryTree<T>::delete_choosenHelper(Node<T> *curr, std::vector<T>&choose) {//хелпер для problem5
	if (!deletechoosen(choose, curr->data)) {// функция для проверки , есть ли данные узла в массиве, если нету, то удаляем узел 
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
void BinaryTree<T>::filterPrime() {//problem6 оставить Простые числа
	if (!root) { cout << "Tree is empty!\n"; return; }
	Node <T> * curr = root;
	filterPrimeHelper(curr);
	if (!PrimeNumber(root->data)) deleteRoot(root);
}
template<typename T>
void BinaryTree<T>::filterPrimeHelper(Node<T> *curr) {// хелпер для problem6
	if (!PrimeNumber(curr->data)) { // переходим к функции для проверки простое ли число, если не простое , удалить узел
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
void BinaryTree<T>::filterNotPrime() {//problem7 оставить Составные числа
	if (!root) { cout << "Tree is empty!\n"; return; }
	Node <T> * curr = root;
	filterNotPrimeHelper(curr);
	if (PrimeNumber(root->data)) deleteRoot(root);
}
template<typename T>
void BinaryTree<T>::filterNotPrimeHelper(Node<T> *curr) {//хелпер для problem7
	if (PrimeNumber(curr->data)) {// переходим к функции для проверки простое ли число, если простое , удалить узел
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
void BinaryTree<T>::filterInterval(int X, int Y) {//problem8 оставить Числа в интервале от X до Y
	if (!root) { cout << "Tree is empty!\n"; return; }
	Node <T> * curr = root;
	filterIntervalHelper(curr, X, Y);
	if (!(curr->data <= Y && curr->data >= X)) deleteRoot(root);
}
template<typename T>
void BinaryTree<T>::filterIntervalHelper(Node<T> *curr, int X, int Y) {//хелпер для problem8
	if (!(curr->data <= Y && curr->data >= X)) {// если данные узла меньше Х и больше Y, то удалим узел
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
void BinaryTree<T>::filterSumOfFigureGreaterN(int N) {	//problem9 оставить Числа, сумма цифр (по модулю) которого > N
	if (!root) { cout << "Tree is empty!\n"; return; } 
	Node <T> * curr = root;
	filterSumOfFigureGreaterNHelper(curr, N);
	if (f(curr->data)<= N) deleteRoot(root);
}

template<typename T>
void BinaryTree<T>::filterSumOfFigureGreaterNHelper(Node<T> *curr, int N) {//хелпер для problem9
	if (f(curr->data)<= N) { // переходим к функции, что возвращает сумму цифр по модулю,  для нашей проверки, 
		if (curr) deleteNode(curr->data);//если сумма меньше или равна заданному N, то удаляем узел
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
void BinaryTree<T>::filterSumOfFigureLessN(int N) {//problem10 оставить Числа, сумма цифр (по модулю) которого < N
	if (!root) { cout << "Tree is empty!\n"; return; }
	Node <T> * curr = root;
	filterSumOfFigureLessNHelper(curr, N);
	if (f(curr->data)>= N) deleteRoot(root);
}
template<typename T>
void BinaryTree<T>::filterSumOfFigureLessNHelper(Node<T> *curr, int N) {//хелпер для problem10
	if (f(curr->data)>= N) {// переходим к функции, что возвращает сумму цифр по модулю,  для нашей проверки, 
		if (curr) deleteNode(curr->data);//если сумма больше или равна заданному N, то удаляем узел
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
void BinaryTree<T>::filterSumOfFigureInterval(int X, int Y) {//problem11 оставить Числа, сумма цифр (по модулю) 
	if (!root) { cout << "Tree is empty!\n"; return; }//которого лежит в интервале от X до Y
	Node <T> * curr = root;
	filterSumOfFigureIntervalHelper(curr, X,Y);
	if (!(f(curr->data) <= Y && f(curr->data) >= X)) deleteRoot(root);
}

template<typename T>
void BinaryTree<T>::filterSumOfFigureIntervalHelper(Node<T> *curr, int X, int Y) {// хелпер для problem11
	if (!(f(curr->data) <= Y && f(curr->data) >= X)) {//переходим к функции, что возвращает сумму цифр по модулю,  для нашей проверки
		if (curr) deleteNode(curr->data);// если суммма меньше Х и больше Y, то удаляем узел
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
void BinaryTree<T>::filterSqrtNumInt() {//problem12 оставить Числа, взятые по модулю, квадратный корень которых целое число
	if (!root) { cout << "Tree is empty!\n"; return; }
	Node <T> * curr = root;
	filterSqrtNumIntHelper(curr);
	if (f2(curr->data)) deleteRoot(root);
}

template<typename T>
void BinaryTree<T>::filterSqrtNumIntHelper(Node<T> *curr) {//хелпер для problem12
	if (f2(curr->data)) {// переходим к функции , что проверяет будет ли квадратный корень числа целым , если нет, удаляем узел
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
bool deletechoosen(std::vector<T> &choose, T data) {//функция для сравнивания curr->data с элементами массива, если есть совпадение, возвращает 1, иначе 0
	for (int i = 0; i < choose.size(); i++) if (choose[i] == data) return 1;
	return 0;
}

std::vector<int> setVector() {//функция для для заполнения массива 5ю рандомными значениями,
	std::vector<int> vec;
//	for (int i = 0; i < 5; i++) vec.push_back(rand() % 198 - 99);
	for (int i = 0; i < 5; i++) vec.push_back(i*i);
	return vec;
}

bool PrimeNumber(int number) {// функция для проверки является ли число простым
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

void parse(int n, std::vector<int> &vec) {// функция, которая парсит число на массив цифр
	vec.push_back(n % 10);// добавляем в массив остаток от деления числа на 10(число 321, добавляем 1)
	if (n > 0) {// проверка для взятия по модулю
		int temp = n / 10;// в темп , помещаем n/10
		if (temp == 0) return;// если темп == 0, выходим из функции
		parse(temp, vec);// рекурсивный вызов
	}
	else {
		int temp = -1 *(n / 10);
		if (temp == 0) return;
		parse(temp, vec);
	}
}
int f(int data) {//функция , что вернет сумму цифр, числа 
	std::vector<int> vec;// обьявим с помощью вектора, пустой массив
	parse(data, vec);// переходим к функции, которая парсит число на массив цифр
	int Sum =0;// переменная для суммы цифр
	for (int i = 0; i < (vec.size()); i++) Sum += vec[i];// с помощью цикла , посчитаем , сумму элементов массива цифр
	vec.clear();// (число 321, массив:[1,2,3], сумма 6)
	return Sum;// вернем эту сумму
}

bool f2(int data) {//функция , что проверяет будет ли квадратный корень числа целым
	double x = data;// создадим переменную для хранения данных(числа)
	if (data > 0) {// проверка, для взятия по модулю
		if (floor(sqrt(x)) != sqrt(x)) { return 1; }//floor()- округляет число в меньшую сторону 
		else {return 0;}//, если число целое целое , то округление ничего не даст и оно будет и так равно числу,
	}//если квадратный корень числа целый, вернем 0, если нет, 1
	else {
		x *= (-1);
		if (floor(sqrt(x)) != sqrt(x)) { return 1; }
		else {return 0;}
	}
}
#endif;
