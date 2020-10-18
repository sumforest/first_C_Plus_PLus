#include <iostream>
using namespace std;

int main33()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	
	// 使用指针访问数组第一个元素
	int *p = arr;
	cout << "数组第一个元素：" << *p << endl;
	cout << "数组第二个元素：" << *++p << endl;

	// 使用指针遍历数组
	int *p2 = arr;
	for (int i = 0; i < 10; i++)
	{
		cout << *p2 << endl;
		p2++;
	}

	system("pause");
	return 0;
}