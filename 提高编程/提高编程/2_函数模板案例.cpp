#include <iostream>
using namespace std;

template<class T>
void exchange_2(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

// 选择排序
template<class T>
void sort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		// 假定最大值下标是max
		int max = i;
		for (int k = i+1; k < len; k++)
		{
			if (arr[max] < arr[k])
			{
				max = k;
			}
		}
		if (max != i)
		{
			exchange_2(arr[i], arr[max]);
		}
	}
}

template<class T>
void printArr(T arr[] ,int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test_2_1()
{
	char chs[] = { 'b','e','a','c','f' };
	sort(chs, sizeof(chs));
	printArr(chs, sizeof(chs));
}

void test_2_2()
{
	int nums[] = { 3,9,1,4,6,5 };
	int len = sizeof(nums)/sizeof(nums[0]);
	sort(nums, len);
	printArr(nums, len);
}

int main2()
{
	//test_2_1();
	test_2_2();

	system("pause");
	return 0;
}