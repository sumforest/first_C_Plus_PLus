#include <iostream>
using namespace std;

class Person_27 
{
public:
	int age;
	Person_27(int age)
	{
		// this指针的作用：1.区分形参和成员变量
		this->age = age;
	}

	// 必须返回引用或者指针不然会返回this的拷贝
	Person_27& addAge(Person_27& p)
	{
		this->age += p.age;
		return *this;
	}
};

void test_27_1()
{
	Person_27 p1(10);
	cout << "p1.age = " << p1.age << endl;
}

// this指针作用： 2.返回非静态成员函数中对象本身
void test_27_2()
{
	Person_27 p1(10);
	Person_27 p2(10);

	p2.addAge(p1).addAge(p1).addAge(p1);
	cout << "p2.age = " << p2.age << endl;
}

int main27()
{
	//test_27_1();
	test_27_2();
	system("pause");
	return 0;
}