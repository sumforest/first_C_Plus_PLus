#include <iostream>
using namespace std;

class Person_8_1
{
public:
	void showPerson1()
	{
		cout << "showPerson1被调用" << endl;
	}
};

class Person_8_2
{
public:
	void showPerson2()
	{
		cout << "showPerson2被调用" << endl;
	}
};

template<class T>
class MyTemplate
{
public:
	MyTemplate(T t)
	{
		this->obj = t;
	}
	T obj;
	void function1()
	{
		obj.showPerson1();
	}
	void function2()
	{
		obj.showPerson2();
	}
};

void test_8()
{
	Person_8_1 p1;
	MyTemplate<Person_8_1> m(p1);
	// 成员函数在调用时创建
	m.function1();
	//m.function2();
}


int main8()
{
	test_8();

	system("pause");
	return 0;
}