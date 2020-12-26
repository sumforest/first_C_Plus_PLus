#include <iostream>
using namespace std;

int main30()
{
	int a = 10;
	// 定义指针
	int *p;
	// 给指针赋值
	p = &a;
	cout << "变量a的内存地址：" << &a << endl;
	cout << "指针p的值：" << p << endl;

	// 使用指针,解引用
	*p = 1000;
	cout << "a = " << a << endl;
	cout << "*p = " << *p << endl;

	system("pause");
	return 0;
}