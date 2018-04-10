#include <iostream>
#include <time.h>

using namespace std;

void arrRand(int* arr, int len);
void printArray(int *array, int SIZE);
void quicksort(int *arr, int first, int last);

void main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	int N;
	cout << endl << "Задайте длину массива - N: ";
	cin >> N;
	int *A = new int[N];
	cout << endl << "Рандомный Массив: \n";
	arrRand(A, N);

	int *B = new int[N];
	for (int i = 0; i < N; ++i)
		B[i] = A[i];

	delete[] A;
	quicksort(B, 0, N - 1);
	cout << endl << "Отсортированый массив :" << endl;

	printArray(B, N);
	delete[] B;
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
		while (arr[i]>pivot) i++;
		while (pivot > arr[j]) j--;
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
