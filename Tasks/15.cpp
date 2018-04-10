#include <iostream>
#include <time.h>

using namespace std;
void PrintArray(int* arr, int n);
void quicksort(int *arr, int left, int right);
void arrRand(int* arr, int len);
void reverse(int *arr, int len);
void main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	int N;
	cout << endl << "Задайте длину массива - N: ";
	cin >> N;
	int *a = new int[N];
	cout << endl << "Рандомный Массив: \n";
	arrRand(a, N);
	quicksort(a, 0, N-1);
	cout << endl << "Отсортированный Массив: \n";
	PrintArray(a, N);
	cout << "\nrev: \n";
	reverse(a, N);
	delete[] a;
	system("pause");
}

void PrintArray(int* arr, int n)
{
	for (int t = 0; t < n; t++)
		cout << arr[t] << " ";
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

void reverse(int *arr, int len) {
	for (int i = 0; i < len / 2; i++) {
		swap(arr[i], arr[len - i - 1]);
	}
	PrintArray(arr, len);

}