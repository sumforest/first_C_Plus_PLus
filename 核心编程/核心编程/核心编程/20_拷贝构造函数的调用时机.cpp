#include <iostream>
using namespace std;

class Person_20
{
public:
	Person_20()
	{
		cout << "默认无参构造被调用" << endl;
	}

	Person_20(int age)
	{
		m_age = age;
		cout << "有参构造函数被调用" << endl;
	}

	Person_20(const Person_20& p)
	{
		cout << "拷贝构造函数被调用" << endl;
		m_age = p.m_age;
	}

public:
	int m_age;
};

// 拷贝构造函数被调用的时机
// 创建好的对象用于初始化新的对象
void test_20_1()
{
	Person_20 p1(10);
	cout << "p1的年龄 = " << p1.m_age << endl;
	Person_20 p2(p1);
	cout << "p2的年龄 = " << p2.m_age << endl;
}

// 值传递的方式给函数参数传值
void dowork(Person_20 p)
{

}

void test_20_2() 
{
	Person_20 p = 10;
	dowork(p);
}

// 返回局部变量时被调用
Person_20 dowork2()
{
	Person_20 p(10);
	cout << "p的地址:" << &p << endl;
	return p;
}

void test_20_3()
{
	Person_20 pReceive = dowork2();
	cout << "pReceive 的地址：" << &pReceive << endl;
}

int main20()
{
	//test_20_1();

	//test_20_2();

	test_20_3();

	system("pause");
	return 0;
}