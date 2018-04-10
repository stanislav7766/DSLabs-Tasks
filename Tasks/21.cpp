#include <iostream>
using namespace std;
void modulesort(int* arr, int len);
void printArray(int* arr, int len)
{

	for (int i = 0; i < len; i++)
	{
		cout << "|" << arr[i] << "|";
	}
	cout << "" << endl;
}


void modulesort(int *arr, int len)
{
	int i = 0;
	int j = 0;
	int num1;
	int num2;
	while (i < len)
	{
		while (j > 0)
		{
			if (arr[j] < 0) num1 = arr[j] * -1;
			else num1 = arr[j];
			if (arr[j - 1] < 0) num2 = arr[j - 1] * -1;
			else num2 = arr[j - 1];
			if (num1 < num2)
			{
				swap(arr[j], arr[j - 1]);
			}
			j--;
		}
		i++;
		j = i;
	}
	printArray(arr, len);
}
void main() {
	int N = 9;
	int *A = new int[N] {-56, 23, -52, 1, 9, 0, 4, 7, 4};
	cout << "before module sort" << endl;
	printArray(A, N);
	cout << "after module sort" << endl;
	modulesort(A, N);
	system("pause");
}