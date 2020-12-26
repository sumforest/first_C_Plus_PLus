#include <iostream>
using namespace std;

int main23()
{
	int arr[] = { 4,2,8,0,5,7,1,3,9 };
	int lenth = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < lenth; i++)
	{
		cout << arr[i] << endl;
	}
	cout << "排序后：" << endl;

	// 比较 n - 1 轮
	for (int i = 0; i < lenth - 1; i++)
	{
		// 每轮比较 轮数 - 1 次
		for (int j = 0; j < lenth - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < lenth; i++)
	{
		cout << arr[i] << endl;
	}

	system("pause");
	return 0;
}