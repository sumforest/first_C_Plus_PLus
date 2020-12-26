#include <iostream>
using namespace std;

int main21()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "数组所占字节大小：" << sizeof(arr) << endl;
	cout << "数组第一个元素的大小：" << sizeof(arr[0]) << endl;
	cout << "数组的长度：" << sizeof(arr) / sizeof(arr[0]) << endl;

	cout << endl;
	// 把十六进制的内存地址转换成十进制
	cout << "数组首地址：" <<(int) arr << endl;
	cout << "数组第一个元素地址：" << (int)&arr[0] << endl;
	cout << "数组第二个元素地址：" << (int)&arr[1] << endl;

	// 数组名称是常量不能进行赋值操作
	system("pause");
	return 0;
}
