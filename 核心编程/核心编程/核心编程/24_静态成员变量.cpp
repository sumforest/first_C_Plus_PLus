#include <iostream>
using namespace std;

class Person_24
{
public:
	// 1.所有对象公用一份数据
	// 2.在编译阶段就分配内cu存
	// 3.类内声明，类外初始化操作
	static int m_a;
};

int Person_24::m_a = 100;

void test_24_1()
{
	Person_24 p;
	cout << p.m_a << endl;

	Person_24 p2;
	p2.m_a = 200;
	cout << p.m_a << endl;
}

void test_24_2()
{
	// 1.通过类实例访问
	//Person_24 p1;
	//cout << p1.m_a << endl;
	// 2.通过类名访问
	cout << Person_24::m_a << endl;
}

int main24()
{
	//test_24_1();
	test_24_2();

	system("pause");
	return 0;
}