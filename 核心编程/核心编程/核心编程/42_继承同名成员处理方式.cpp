#include <iostream>
using namespace std;

class Base_42
{
public:
	Base_42()
	{
		a = 10;
	}

	void test()
	{
		cout << "父类的 test()" << endl;
	}

	void test(int a)
	{
		cout << "父类的 test(int a)" << endl;
	}

	int a;
};

class Son_42:public Base_42
{
public:
	Son_42()
	{
		a = 20;
	}

	void test()
	{
		cout << "子类的 test()" << endl;
	}

	int a ;
};

void test_42()
{
	Son_42 son;
	cout << "子类 a = " << son.a << endl;
	cout << "父类 a = " << son.Base_42::a << endl;
}

void test_42_1()
{
	Son_42 son;
	// 父类与子类同名的成员函数会在子类中被隐藏，要想在子类中访问需要加作用域
	//son.test(10);
	//son.Base_42::test();
	son.Base_42::test(10);
}

int main42()
{
	//test_42();
	test_42_1();

	system("pause");
	return 0;
}