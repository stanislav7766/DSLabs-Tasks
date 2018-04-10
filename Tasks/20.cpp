#include <iostream>
#include <string>
using namespace std;
void printArray(string *arr, int len);
void shellSort(string* arr, int len);


void main()
{
	 int N = 8;
	string *A = new string[N]{ "composition", "closure", "functor", "varible", "arr", "const", "list", "debug" };
	cout << "Before sorting" << endl;
	printArray(A, N);
	cout << "after sorting" << endl;
	shellSort(A, N);
	printArray(A, N);
	system("pause");
}

	void printArray(string *arr, int len)
	{

		for (int i = 0; i < len; i++)
		{
			cout << arr[i] << " ";           
		}
		cout << " " << endl;                    
	}

	void shellSort(string* arr, int len)
	{
		for (int step = len / 2; step > 0; step /= 2)
		{
			for (int i = step; i < len; i += 1)
			{
				string temp = arr[i];

				int j;
				for (j = i; j >= step && arr[j - step].length() > temp.length(); j -= step)
				{
					arr[j] = arr[j - step];
				}
				arr[j] = temp;
			}
		}
	}
