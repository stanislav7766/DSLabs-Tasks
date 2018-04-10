#include <iostream>
#include <time.h>

using namespace std;
void PrintArray(int* arr, int n);
void sort(int *arr, const int SIZEARR);
void arrRand(int* arr, int len);
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
	cout << "\nФильтр: \n";
	sort(a, N);
	delete[] a;
	system("pause");
}

void PrintArray(int* arr, int n)
{
	for (int t = 0; t < n; t++)
		cout << arr[t] << " ";
}

void arrRand(int* arr, int len) {
	for (int i = 0; i<len; i++)
	{
		arr[i] = rand() % 198 - 99;
		cout << arr[i] << " ";
	}
}

void sort(int *arr, int len)
{
	int *B = new int[len];
	int i = 0;
	int j = 0;
	while (i < len)
	{
		B[i] = arr[i];       
		while (j > 0)
		{                             
			if (B[j] < B[j - 1])
			{
				swap(B[j], B[j - 1]);
			}
			j--;
		}
		i++;
		j = i;

	}
	PrintArray(B, len);
}