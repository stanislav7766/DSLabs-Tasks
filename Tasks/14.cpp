#include <iostream>
#include <time.h>
using namespace std;
void printArray(int *array, int SIZE);
void quicksort(int *arr, int left, int right);
void arrRand(int* arr, int len);
void inserNumber(int* a, int len, int k);


void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RU");
	int N, k;
	cout << endl << "Задайте длину массива - N: ";
	cin >> N;
	int *a = new int[N];
	cout << endl << "Рандомный Массив: \n";
	arrRand(a, N);
	cout << endl << "Отсортированный Массив: \n";
	quicksort(a, 0, N - 1);

	printArray(a, N);
	cout << endl << "Введите элемент, который нужно добавить в отсортированный массив: ";
	cin >> k;
	cout << endl;
	cout << "Конечный Массив: " << endl;
	inserNumber(a, N, k);
	delete[] a;

	system("pause");
}


void printArray(int *array, int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
		cout << array[i] << " ";
}

void quicksort(int *arr, int left, int right)
{
	int pivot;
	int i = left;
	int j = right;
	pivot = arr[(i + j) / 2];
	do
	{
		while (arr[i]<pivot) i++;
		while (pivot < arr[j]) j--;
		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (left<i) quicksort(arr, left, j);
	if (i<right) quicksort(arr, i, right);
}
void arrRand(int* arr, int len) {
	for (int i = 0; i<len; i++)
	{
		arr[i] = rand() % 198 - 99;
		cout << arr[i] << " ";
	}
}
void PrintArray(int* arr, int n)
{
	for (int t = 0; t < n; t++)
		cout << arr[t] << " ";
}
void inserNumber(int *arr, int len, int k)
{
	int *arrayB = new int[len + 1];
	int i = 0;
	while (i < len + 1) {
		arrayB[i] = arr[i];
		i++;
	}
	arrayB[len] = k;
	i = len;
	for(i; i>0 ; i--)
		if (arrayB[i] < arrayB[i - 1])
		{
			swap(arrayB[i], arrayB[i - 1]);
		}

	PrintArray(arrayB, len + 1);
	delete[] arrayB;
}
