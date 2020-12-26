#include <iostream>
using namespace std;

// 函数定义
void swap(int num1, int num2)
{
	cout << "交换前：" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	int temp = num1;
	num1 = num2;
	num2 = temp;

	cout << "交换后：" << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
}

int main27()
{
	int a = 10;
	int b = 20;

	cout << "调用swap函数前" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	swap(a, b);
	cout << "调用swap函数后" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	// 结论：值传递是，形参的改变不会影响实参

	system("pause");
	return 0;
}