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
	cout << "�����" << endl;

	// �Ƚ� n - 1 ��
	for (int i = 0; i < lenth - 1; i++)
	{
		// ÿ�ֱȽ� ���� - 1 ��
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