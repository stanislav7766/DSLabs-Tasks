#include <iostream>
using namespace std;
void PrintArray(char **array, int SIZE);
void shellSort(char** arr, int len);

void main()
{
	setlocale(LC_ALL, "RU");
	char **A = new char *[5]{"������", "������", "������", "������", "��������"};
	cout << endl << "��������������� ������: \n";
	shellSort(A, 5);

	PrintArray(A, 5);

	delete[] A;

	system("pause");
}


void shellSort(char** arr, int len)
{
	for (int step = len / 2; step > 0; step /= 2)
	{
		for (int i = step; i < len; i += 1)
		{
			char* temp = arr[i];

			int j;
			for (j = i; j >= step && strcmp(arr[j - step], temp) > 0; j -= step) //strcmp() , ���������� 0 ���� ������� �����, ���������� >0, ���� ������1 > ������2, ���������� <0, ���� ������1 < ������2
			{
				arr[j] = arr[j - step];
			}
			arr[j] = temp;
		}
	}
}

void PrintArray(char** arr, int n)
{
	for (int i= 0; i < n; i++)
		cout << arr[i] << " "<<endl;
}
