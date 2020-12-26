#include <iostream>
using namespace std;

int add(int a,int b)
{
	return a + b;
}

template<class T>
T add_template(T a, T b)
{
	return a + b;
}

void test_3_1()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	// 发生隐式类型转换
	cout << add(a, c) << endl;
	// 报错产生二义性
	//cout << add_template(a, c) << endl;
	cout << add_template<int>(a, c) << endl;
}

int main3()
{
	/*
	区别：
	1.普通函数会发生隐式转换
	2.函数模板在调用时没有显示指定类型，让编译器自动类型推导不会发生隐式类型转化
	3.函数模板在调用时手动的指定类型，会发生类型转换
	总结:
	在调用函数模板时最好显示的指定类型，因为可以自己确定调用的类型T
	*/
	test_3_1();

	system("pause");
	return 0;
}