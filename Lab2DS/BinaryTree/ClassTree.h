#ifndef ClassTree_h
#define ClassTree_h
#include <vector>
template<typename T>
struct Node {
	T data;
	Node *pleft;
	Node *pright;
	Node *parent;
};

template<typename T>
class BinaryTree {
private:


	Node<T> *root;
	int Size;
	int index;// необходим для копирования дерева в массив
	bool deleted = false;
	void setRoot(T data);
	void symmetricOrder(Node<T> *node, T *arr); // обход дерева по возростанию элементов для копирования в массив
	void symmetricOrderHelper(Node<T> *node, T *arr);
	void copyToArr(T *arr);
	void clearHelper(Node<T> *node);
	void PrintTree(Node<T>* tp, int spaces);
	void deleteNodeHelper(Node<T>* temp);
	void deleteWithoutPright(Node<T>* temp);
	void deleteWithoutPleft(Node<T>* temp);
	void deleteWithTwo(Node<T>* temp);
	void deleteWithoutTwo(Node<T>* temp);
	void deleteRoot(Node<T>* temp);
	Node<T> *findHelper(Node<T> *current, T data);



public:
	BinaryTree();
	~BinaryTree();
	Node<T>* getRoot() { return root; }
	void push(T data);
	int maxCount(T *arr);
	int minCount(T *arr);
	int getSize() { return Size; }
	void clear();
	void show();// вывод дерева
	int deleteNode(T data);//удаление элемента
	void fillRandom();
	void filterMultipleN(int N);
	void filterMultipleNHelper(Node<T> *curr, int N);
	void filterOddHelper(Node<T> *curr);
	void filterOdd();
	void filterGreaterNHelper(Node<T> *curr, int N);
	void filterGreaterN(int N);
	void filterLessNHelper(Node<T> *curr, int N);
	void filterLessN(int N);
	void filterNotPrime();
	void filterNotPrimeHelper(Node<T> *curr);
	void filterPrime();
	void filterPrimeHelper(Node<T> *curr);
	Node<T> *find(T data);
	//void filterSelection(int num, ...);
	void delete_choosen(std::vector<T>&choose);
	void delete_choosenHelper(Node<T> *curr, std::vector<T> &choose);
	void filterInterval(int X, int Y);
	void filterIntervalHelper(Node<T> *curr, int X, int Y);
	void filterSumOfFigureGreaterN(int N);
	void filterSumOfFigureGreaterNHelper(Node<T> *curr, int N);
	void filterSumOfFigureLessN(int N);
	void filterSumOfFigureLessNHelper(Node<T> *curr, int N);
	void filterSumOfFigureInterval(int X,int Y);
	void filterSumOfFigureIntervalHelper(Node<T> *curr, int X,int Y);
	void filterSqrtNumInt();
	void filterSqrtNumIntHelper(Node<T> *curr);
};
#endif 
