#include <iostream>
using namespace std;

// Ã°ÅİÅÅĞò
void bubbleSort(int *arr, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

// Êä³öÊı×é
void printArr(int *arr, int len)
{
	for(int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}
}

int main35()
{
	int arr[] = { 3,1,5,2,0,9,6,4,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	// Ã°ÅİÅÅĞò
	bubbleSort(arr, len);
	
	printArr(arr, len);

	system("pause");
	return 0;
}