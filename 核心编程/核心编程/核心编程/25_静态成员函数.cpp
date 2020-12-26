#include <iostream>
using namespace std;

class Person_25
{
public:

	// 1.所有对象只能访问一个成员函数
	// 2.静态成员函数只能访问静态成员变量
	static void func()
	{
		m_a = 200;
		//m_b = 300; 静态成员函数不能访问成员变量，因为当有多个实例调用静态成员函数的时候，编译器无法确认修改的时哪个实例的成员变量
		cout << "静态成员函数被调用" << endl;
	}

	static int m_a;

	int m_b;

private:
	static void func2()
	{

	}
};

int Person_25::m_a = 100;

void test_25_1()
{
	// 1.通过对象实例访问
	Person_25 p1;
	p1.func();

	// 2.通过类名访问
	Person_25::func();

	// 类外访问不到私用的静态成员函数
	//Person_25::func2();
}

int main25()
{
	test_25_1();
	system("pause");
	return 0;
}