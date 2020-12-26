#include <iostream>
using namespace std;

int main12() {
	// 递增运算符
	int a = 10;
	// 前置++
	++a;
	cout << a << endl;

	//后置++
	int b = 10;
	b++;
	cout << b << endl;

	// 前置++，先进行递增操作，再计算表达式
	int a1 = 10;
	int b1 = ++a1 * 10;
	cout << "a1 = " << a1 << endl; // 11
	cout << "b1 = " << b1 << endl; // 110

	// 后置++，先计算表达式，再进行递增操作
	int a2 = 10;
	int b2 = a2++ * 10;
	cout << "a2 = " << a2 << endl; // 11
	cout << "b2 = " << b2 << endl; // 100 

	system("pause");
	return 0;
}