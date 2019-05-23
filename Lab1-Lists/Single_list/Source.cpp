#include <iostream>
#include <string>
#include <regex>
using namespace std;

template<typename T>
struct Node {
	T data;
	Node *pNext;
};

template<typename T>
class List {
private:
	Node<T> *head;
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
	head = nullptr;
}

template<typename T>
List<T>::~List() {
	clear();
}


template<typename T>
void List<T>::push_front(T data) {
	Node<T> *node = new Node<T>;
	Node<T> *temp = head;
	head = node;
	node->data = data;
	node->pNext = temp;
	Size++;
}


template<typename T>
void List<T>::push_back(T data) {
	Node<T> *node = new Node<T>;
	node->pNext = nullptr;
	node->data = data;
	if (Size == 0) head = node;
	else {
		Node<T> *current = this->head;
		while (current->pNext != nullptr) current = current->pNext;
		current->pNext = node;
	}
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
	Node<T> *current = this->head;
	for (int counter = 0; current != nullptr; counter++)
	{
		if (counter == Size-2)
		{
			Node<T> *temp = current->pNext;
			current->pNext = nullptr;
			delete temp;
			break;
		}
		current = current->pNext;
	}
	Size--;
}


template<typename T>
void List<T>::insert(T data, int index)
{
	if (index < 0) {
		cout << "Invalid index\n";
		return;
	}
	if (index >= Size - 1) {
		push_back(data);
		return;
	}
	else {
		Node<T> * node = new Node<T>;
		Node<T> *current = this->head;
		for (int counter = 0; current != nullptr; counter++)
		{
			if (counter == index)
			{
				node->pNext = current->pNext;
				node->data = data;
				current->pNext = node;
				break;
			}
			current = current->pNext;
		}
		Size++;
	}
}


template<typename T>
void List<T>::removeAt(int index)
{
	if (index > Size - 1 || index < 0) {
		cout << "Invalid index\n";
		return;
	}
	if (index == 0) {
		pop_front();
		return;
	}
	if (index == Size - 1) {
		pop_back();
		return;
	}
	Node<T> *current = this->head;
	for (int counter = 0; current != nullptr; counter++)
	{
		if (counter == index - 1)
		{
			Node<T> *temp = current->pNext;
			current->pNext = temp->pNext;
			delete temp;
		}
		current = current->pNext;
	}
	Size--;
}


template<typename T>
T & List<T>::operator[](const int index)
{
	if (Size == 0) cout << "empty\n";
	else
	{
		Node<T> *current = this->head;
		for (int counterLtoR = 0; current != nullptr; counterLtoR++)
		{
			if (counterLtoR == index) return current->data;
			current = current->pNext;
		}
	}
}


template<typename T>
bool List<T>::isEmpty()
{
	if(head == nullptr) return true; 
	else return false;
}


template <typename T>
void List<T>::clear() {
	while (Size) pop_front();
	cout << "List was cleared" << endl;
}


template<typename T>
void List<T>::show() {
	if (head != nullptr) {
		Node<T> *temp = head;
		while (temp->pNext != nullptr) {
			cout << temp->data << ", ";
			temp = temp->pNext;
		}
		cout << temp->data << endl;
	}
}

void main() {
	setlocale(LC_ALL, "ru");
	regex rx;

	List<string> SHARP;

	SHARP.push_front("tabletSHARP");
	SHARP.push_back("vknfvnfkmSHARP");
	SHARP.push_back("phoneSHARP");
	List<string> SONY;
	SONY.push_front("tabletSONY");
	SONY.push_back("gfddfSONY");
	SONY.push_back("3456tfokSONY");
	bool b1 = false;
	List<string> Common;
	if (SHARP.isEmpty() || SONY.isEmpty()) cout << "Список пуст";
	else {
		for (int i = 0; i < SHARP.GetSize(); i++)
		{ 
			for (int j = 0; j < SONY.GetSize(); j++)
			{
				rx = SONY[j].substr(0, 3);

				if (regex_search(SHARP[i].begin(), SHARP[i].end(), rx) && regex_search(SONY[j].begin(), SONY[j].end(), rx))
				{
					b1 = true;
					Common.push_front(SHARP[i] + "-" + SONY[j]);
				}
			}
		}
		if (b1 == false) cout << "совпадений нет\n";
	}

	Common.show();
	system("pause");
}
