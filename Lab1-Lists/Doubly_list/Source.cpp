#include <iostream>
#include <string>
#include <regex>
using namespace std;

template<typename T>
struct Node {//������� ������
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
	void isEmpty();
	void insert(T data, int n);
	void removeAt(int n);
	void push_front(T data);
	void push_back(T data);
	int GetSize() { return Size; }
	T& operator[](const int index);
	void clear();
	void pop_front();
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
void List<T>::isEmpty()
{
	if (head == nullptr) {
		cout << "Empty";
	}
	else{
		cout << "Not empty";
	}
}

template<typename T>
void List<T>::insert(T data, int n)
{
	Node<T> * node = new Node<T>;
	Node<T> *current = this->head;
	for (int counter = 0; current != nullptr; counter++)
	{
		if (counter == n)//���� ����� �� = �������
		{/*
			Node<T> *temp = current->pNext;
			current->pNext = node;
			node->data = data;
			node->pNext = temp;*/
			node->pNext = current->pNext;
			node->data = data;
			current->pNext = node;

		}
		current = current->pNext;
	}
	Size++;

}


template<typename T>
void List<T>::removeAt(int n)
{
	Node<T> *current = this->head;
	for (int counter = 0; current != nullptr; counter++)
	{
		if (counter == n - 1)
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
void List<T>::push_front(T data) {
	Node<T> *node = new Node<T>;//������� ����
	Node<T> *temp = head;//�������� � ��������� �� , ��� head
	head = node;//� head ����������� ��� ����
	node->data = data;// � ������ ���� ����������� ����
	node->pNext = temp;//� ���� ������ ���� , ����������� ������ head
	Size++;
}


template<typename T>
void List<T>::push_back(T data) {
	Node<T> *node = new Node<T>;//������� ����
	if (head == nullptr) {//������ ����
		head = node;//� head ����������� ��� ��
		head->data = data;//� ������ ���� ����������� ����
		head->pNext = nullptr;//���� ������ �� ���� ���
	}
	else {
		Node<T> *temp = this->head;//� ��������� �� ����������� ������ �� head
		while (temp->pNext != nullptr) {//���� ���� ������ �� �� ���
			temp = temp->pNext;// ��������� �� �� ��
		}
		temp->pNext = node;//� ��������� ������ ���������� ��, ����������� ��� ���� 
		node->data = data;//
		node->pNext = nullptr;//
	}
	Size++;
}


template<typename T>
void List<T>::show() {
	if (head != nullptr) {//������ �� ����
		Node<T> *temp = head;//� ��������� ���� ����������� head
		while (temp->pNext != nullptr) {//���� ������ �� ���� �� ���
			cout << temp->data << ", ";//����� ������ �� ����
			temp = temp->pNext;//��������� �� �� ��
		}
		cout << temp->data << endl;//����� temp->pNext = nullptr, ������� ��� ����
	}

}


template <typename T>
void List<T>::clear() {
	while (Size) {
		pop_front();

	}
	cout << "List was cleared" << endl;
}


template <typename T>
void List<T>::pop_front() {
	Node<T> *temp = head;//� �� ���� ����������� head 
	head = head->pNext;//� head ����������� ���� ������ ����
	delete temp;//������� ���������
	Size--;
}

template<typename T>
T & List<T>::operator[](const int index)//������������ ������ ������� ������� � ����������� ��� ��������)
{
	if (Size == 0) { cout << "empty\n"; }
	else
	{
		Node<T> *current = this->head;//��� ��������� ����, ����� ������ ��� �� ���������
		for (int counterLtoR = 0; current != nullptr; counterLtoR++)//���� ��������� �� ���
		{
			if (counterLtoR == index)//���� ����� �� = �������
			{
				return current->data;  //������ ��� ���� ����
			}
			current = current->pNext; //���� ���, ��������� �� �� ��
		}
	}
}

void main() {
	setlocale(LC_ALL, "ru");
	regex rx;

	List<string> SHARP;
	SHARP.push_front("tabletSHARP");
	SHARP.push_back("mouseSHARP");
	SHARP.push_back("notebookSHARP");

	List<string> SONY;
	SONY.push_front("tabletSONY");
	SONY.push_back("mouseSONY");

	SONY.push_back("notebookSONY");

	List<string> Common;
	for (int i = 0; i < SHARP.GetSize(); i++)
	{
	for (int j = 0; j < SONY.GetSize(); j++)
	{
	rx = SONY[j].substr(0, 3);
	if (regex_search(SHARP[i].begin(), SHARP[i].end(), rx) && regex_search(SONY[j].begin(), SONY[j].end(), rx))
	Common.push_front(SHARP[i] + "-" + SONY[j]);
	}
	}

	Common.show();
	system("pause");
}
