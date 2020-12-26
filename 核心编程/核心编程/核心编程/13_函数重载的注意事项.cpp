#include <iostream>
using namespace std;

void func12_1(int& a)
{
	cout << "func12_1(int &a) 被调用" << endl;
}

void func12_2(const int& a)
{
	cout << "func12_2(const int& a) 被调用" << endl;
}

void func12_3(int a, int b = 10)
{
	cout << "func12_3(int a, int b = 10) 被调用" << endl;
}

void func12_3(int a)
{
	cout << "func12_3(int a) 被调用" << endl;
}


int main13()
{
	// 当const修饰的形参作为函数重载的条件是，const有无可以作为函数重载的条件
	//int a = 10;
	//func12_1(a); //调用 func12_1(int& a)
	//func12_2(10); //调用  func12_2(const int& a)

	// 当重载函数由默认值时，要尽量避免二义性
	//func12_3(10);

	system("pause");
	return 0;
}