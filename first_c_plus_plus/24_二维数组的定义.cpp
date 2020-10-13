#include <iostream>
using namespace std;

int main()
{
	// 定义方式1
	/*int arr[2][3];
	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 3;
	arr[1][0] = 4;
	arr[1][1] = 5;
	arr[1][2] = 6;*/
	// 遍历
	/*
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j< 3; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	*/

	// 定义方式2
	/*int arr[2][3] = 
	{
		{1,2,3},
		{4,5,6}
	};
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/

	// 定义方式3
	/*int arr[2][3] = { 1,2,3,4,5,6 };

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/

	// 定义方式4
	int arr[][3] = { 1,2,3,4,5,6 };


	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}


	system("pause");
	return 0;
}