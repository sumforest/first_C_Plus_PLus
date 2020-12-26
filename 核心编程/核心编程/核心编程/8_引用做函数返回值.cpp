#include <iostream>
using namespace std;

// 返回局部变量的引用
int& returnLocalVar()
{
	int a = 10;
	return a;
}

// 引用可以作为左值
int& returnStaticVar()
{
	static int  a = 10;
	return a;
}


int main8()
{
	//int& ref = returnLocalVar();
	//cout << "a = " << ref << endl;
	//cout << "a = " << ref << endl;

	int& ref2 = returnStaticVar();
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	// 函数返回引用可做左值
	returnStaticVar() = 1000;
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	system("pause");
	return 0;
}