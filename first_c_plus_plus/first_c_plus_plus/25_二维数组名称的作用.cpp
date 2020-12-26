#include <iostream>
using namespace std;

int main25()
{
	int arr[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	// 查看所占的空间
	cout << "二维数组的大小：" << sizeof(arr) << endl;
	cout << "二维数组第一行的大小：" << sizeof(arr[0]) << endl;
	cout << "二维数组第一个元素的大小：" << sizeof(arr[0][1]) << endl;
	cout << "二维数组行数：" << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "二维数组列数：" << sizeof(arr[0]) / sizeof(arr[0][1]) << endl;
	cout << "---" << endl;

	// 查看地址
	cout << "二维数组首地址：" << (int)arr << endl;
	cout << "二维数组第一行首地址：" << (int)arr[0] << endl;
	cout << "二维数组第二行首地址：" << (int)arr[1] << endl;
	cout << "二维数组第一个元素首地址：" << (int)&arr[0][0] << endl;

	system("pause");
	return 0;
}