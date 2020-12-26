#include <iostream>
using namespace std;

// 常量引用防止引用的值被修改
void print(const int& val)
{
	//val = 1000;
	cout << "val = " << val << endl;
}

int main9()
{
	// 给引用初始化必须时已知的内存空间
	// 10的内存地址未知报错
	//int& ref = 10;

	// 编译器工作过程：int temp = 10; const int& ref = temp;
	//const int& ref = 10;

	int a = 10;

	print(a);

	system("pause");
	return 0;
}