#include <iostream>
using namespace std;
#include <string>

// 1.函数对象可以有参数有返回值
class MyReturn
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

void test_31_1()
{
	MyReturn mr;
	cout << mr(10, 20) << endl;
}

// 2.函数对象可以有自己的状态
class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}
	int count;

	void operator()(string str)
	{
		cout << str << endl;
		count++;
	}
};

void test_31_2()
{
	MyPrint mp;
	mp("hello C++");
	mp("hello C++");
	mp("hello C++");
	mp("hello C++");
	cout << "字符串打印次数：" << mp.count << endl;
}

// 3.函数对象作为参数传递
void test_31_3_1(MyPrint& mp,string str)
{
	mp(str);
}

void test_31_3()
{
	MyPrint mp;
	test_31_3_1(mp, "函数对象作为参数传递");
}

int main31()
{
	//test_31_1();
	//test_31_2();
	test_31_3();

	system("pause");
	return 0;
}