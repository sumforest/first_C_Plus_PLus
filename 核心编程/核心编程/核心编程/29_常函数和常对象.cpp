#include <iostream>
using namespace std;

class Person_29
{
public:

	void test1() const
	{
		// this指针相当于指针常量：指针指向不可以改变，指向的值可改变
		// 常函数加const修饰的时this指针，所以指针的指向不可以改变，指向的值也不可以改变
		// 常函数不能修改成员属性
		//this->age = 100;
		//this = NULL;
		this->modify = 100;
	}

	void func()
	{

	}

	int age;
	// 当成员属性中加mutable关键字，那么在常函数中可以修改；
	mutable int modify;
};

void test_29()
{
	// 常对象
	const Person_29 p;
	// 常对象只能调用常函数
	//p.age = 100;
	p.modify = 100;

	p.test1();
	//p.func();
}

int main29()
{

	system("pause");
	return 0;
}