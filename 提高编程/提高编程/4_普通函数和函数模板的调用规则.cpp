#include <iostream>
using namespace std;

void test_4_1(int a, int b)
{
	cout << "普通函数被调用" << endl;
}

template<class T>
void test_4_1(T a, T b)
{
	cout << "函数模板被调用" << endl;
}

// 3.函数模板可以重载
template<class T>
void test_4_1(T a, T b, T c)
{
	cout << "重载的函数模板被调用" << endl;
}

void test_4()
{
	int a = 10;
	int b = 20;
	//1. 同时存在普通函数和函数模板时，优先调用普通函数
	//test_4_1(a, b);
	// 2.通过空模板参数列表来强制调用哦模板函数
	//test_4_1<>(a, b);
	char c = 'a';
	char d = 'b';
	// 4.如果函数模板产生更好的匹配，那么优先调用函数模板
	test_4_1(c,d);
}

int main4()
{
	test_4();

	system("pause");
	return 0;
}