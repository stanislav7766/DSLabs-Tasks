#include <iostream>
#include <string>
using namespace std;

void print(int *arr1, string *arr2, int len) 
{
	for(int i =0; i< len; i++)
		cout << arr2[i] << " - " << arr1[i] << endl;
}

void sort(int *arr1, string *arr2, int len)
{
	int j;
	string temp;
	for (int i = 0; i < len; i++)
	{
		for (j = i;j > 0; j--)
		{
			if (arr1[j] < arr1[j - 1])
			{
				swap(arr1[j], arr1[j - 1]);
				temp = arr2[j];
				arr2[j] = arr2[j - 1];
				arr2[j - 1] = temp;
			}
		}
	}
}

void main() {
	const int SIZE = 10;
	int *A = new int[SIZE] {1242, 5765, 2421, 9967, 2113, 1121, 9489, 7467, 8823, 2222};
	string *B = new string[SIZE]{ "Artur", "Gerold", "Zwain", "Shwein", "Spin", "Porto", "Utin", "Mopsy", "Zun", "Alfred" };
	cout << "before sort" << endl;
	cout << "" << endl;
	print(A, B, SIZE);
	sort(A, B, SIZE);
	cout << "" << endl;
	cout << "after sort" << endl;
	cout << "" << endl;
	print(A, B, SIZE);
	system("pause");
}