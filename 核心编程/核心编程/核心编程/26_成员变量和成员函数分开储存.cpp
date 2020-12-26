#include <iostream>
using namespace std;

class Person_26
{
public:
	// 存放再对象上
	int a;
	// 不存放再对象上
	static int b;
	// 不存放再对象上
	static void func() 
	{

	}
	// 不存放再对象上
	void func2()
	{

	}
};

int Person_26::b = 20;

void test_26_1()
{
	Person_26 p;
	// C++中空对象所占的内存空间为1字节
	// C++编译器会为每个空对象分配1个字节的空间，是为了区分空对象占用内存的位置；每个空对象有着独一无二的内存地址
	cout << "空类的大小：" << sizeof(p) << endl;
}

void test_26_2()
{
	Person_26 p;
	cout << "Person_26类的大小：" << sizeof(p) << endl;
}

int main26()
{
	//test_26_1();
	test_26_2();

	system("pause");
	return 0;
}