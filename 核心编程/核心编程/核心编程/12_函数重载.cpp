#include <iostream>
using namespace std;

// 函数重载条件：参数类型不同、参数个数不同、参数顺序不同
void func()
{
	cout << "func() 被调用" << endl;
}

void func(int a)
{
	cout << "func(int a) 被调用" << endl;
}

void func(int a, double b)
{
	cout << "func(int a, double b) 被调用" << endl;
}

void func(double a, int b)
{
	cout << "func(double a, int b) 被调用" << endl;
}

// 函数的返回值不作为方法重载的条件
//void func()
//{
//
//}

int main12()
{
	//func();
	//func(10);
	//func(10, 3.14);
	//func(3.14, 10);
	func();

	system("pause");
	return 0;
}