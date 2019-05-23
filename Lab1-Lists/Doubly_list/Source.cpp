#include <iostream>
#include <string>
#include <regex>
using namespace std;

template<typename T>
struct Node {
	T data;
	Node *pNext;
	Node *pPrev;
};

template<typename T>
class List {
private:
	Node<T> *head;
	Node<T> *tail;
	int Size;
public:
	List();
	~List();
	void push_front(T data);
	void push_back(T data);
	void pop_front();
	void pop_back();
	void insert(T data, int n);
	void removeAt(int n);
	T& operator[](const int index);
	bool isEmpty();
	int GetSize() { return Size; }
	void clear();
	void show();

};

template<typename T>
List<T>::List() {
	Size = 0;
	head = tail = nullptr;
}


template<typename T>
List<T>::~List() {
	clear();
}


template<typename T>
void List<T>::push_back(T data) {

	Node<T> *node = new Node<T>;

	node->pNext = nullptr;
	node->data = data;
	node->pPrev = tail;

	if (tail != nullptr) tail->pNext = node;
	if (Size == 0) head = tail = node;
	else tail = node;
	Size++;
}

template<typename T>
void List<T>::push_front(T data) {
	Node<T> *node = new Node<T>;
	node->pPrev = nullptr;
	node->data = data;
	node->pNext = head;

	if (head != nullptr) head->pPrev = node;
	if (Size == 0) head = tail = node;
	else head = node;
	Size++;
}


template <typename T>
void List<T>::pop_front() {
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}


template <typename T>
void List<T>::pop_back() {
	Node<T> *temp = tail;
	tail = tail->pPrev;
	temp->pPrev = nullptr;
	tail->pNext = nullptr;
	delete temp;
	Size--;
}


template<typename T>
void List<T>::insert(T data, int index)
{
	if (index < 0)
	{
		cout << "Invalid index\n";
		return;
	}
	if (index >= Size - 1) {
		push_back(data);
		return;
	}
	if (index <= Size / 2)
	{
		cout << "index<\n";
		Node<T> *current = this->head;
		for (int counterLtoR = 0; current != nullptr; counterLtoR++)
		{
			if (counterLtoR == index)
			{
				Node<T> * node = new Node<T>;
				node->pNext = current->pNext;
				node->pPrev = current;
				current->pNext = node;
				node->data = data;
				current->pNext->pPrev = node;
				break;
			}
			current = current->pNext;
		}
	}
	else
	{
		cout << "index>\n";
		Node<T> *current = this->tail;
		for (int counterRtoL = Size - 1; current != nullptr; counterRtoL--)
		{
			if (counterRtoL ==index)
			{
				Node<T> * node = new Node<T>;
				node->pNext = current->pNext;
				node->pPrev = current;
				current->pNext = node;
				node->data = data;
				current->pNext->pPrev = node;
				break;
			}
			current = current->pPrev;
		}
	}
	Size++;
}


template<typename T>
void List<T>::removeAt(int index)
{
	if (index > Size-1 || index < 0) {
		cout << "Invalid index\n";
		return;
	}
	if (index == 0) {
		pop_front();
		return;
	}	
	if (index == Size-1) {
		pop_back();
		return;
	}
    if (index <= (Size) / 2) {
		cout << "index<\n";
		Node<T> *current = this->head;
		for (int counterLtoR = 0; current != nullptr; counterLtoR++)
		{
			if (counterLtoR == index-1) {
				Node<T> *temp = current->pNext;
				current->pNext = temp->pNext;
				temp->pNext->pPrev = current;
				delete temp;
				break;
			}
			current = current->pNext;
		}
	}
	else {
	    cout << "index>\n";
		Node<T> *current = this->tail;
		for (int counterRtoL = Size - 1; current != nullptr; counterRtoL--)
		{
			if (counterRtoL == index-1)
			{
				Node<T> *temp = current->pNext;
				current->pNext = temp->pNext;
				temp->pNext->pPrev = current;
				delete temp;
				break;
			}
			current = current->pPrev;
		}
	}
	Size--;
}

template<typename T>
T & List<T>::operator[](const int index)
{
	if (Size == 0 || index < 0 || index > Size -1) {
		cout << "invalid index\n";
	}
	else {
		if (index < Size / 2)
		{
			Node<T> *current = this->head;
			for (int counterLtoR = 0; current != nullptr; counterLtoR++)
			{
				if (counterLtoR == index) { return current->data; }
				current = current->pNext;
			}
		}
		else
		{
			Node<T> *current1 = this->tail;
			for (int counterRtoL = Size - 1; current1 != nullptr; counterRtoL--)
			{
				if (counterRtoL == index) { return current1->data; }
				current1 = current1->pPrev;
			}
		}
	}
}


template<typename T>
bool List<T>::isEmpty()
{
	if (head == nullptr) { return true; }
	else { return false; }
}


template <typename T>
void List<T>::clear() {
	while (Size) pop_front();
	cout << "List was cleared" << endl;
}


template<typename T>
void List<T>::show() {
	if (Size != 0) {
		Node<T> *current = head;
		while (current->pNext != nullptr) {
			cout << current->data << ", ";
			current = current->pNext;
		}
		cout << current->data << endl;
	}
	else {
		cout << "empty\n";
	}
}



void main() {
	setlocale(LC_ALL, "ru");
	regex rx;
	List<string> SHARP;
	SHARP.push_back("0");
	SHARP.push_back("1");
	SHARP.push_back("2");
	SHARP.push_back("3");
	SHARP.push_back("4");
	SHARP.push_back("5");
	SHARP.insert("01", 5);
	SHARP.removeAt(5);
	SHARP.pop_front();
	SHARP.pop_front();
	SHARP.pop_front();
	SHARP.pop_front();
	SHARP.pop_front();
	SHARP.pop_front();
	SHARP.show();


	system("pause");
}
