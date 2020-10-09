#include <iostream>
using namespace std;

int main16()
{
	int a = 10;
	int b = 20;
	int c = 0;
	c = a > b ? a : b;
	cout << "c=" << c << endl;
	cout << endl;

	// 在C++中三目运算符返回的是变量，可以为变量赋值
	a > b ? a : b = 100;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	system("pause");
	return 0;
}