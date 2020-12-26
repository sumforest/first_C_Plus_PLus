#include <iostream>
using namespace std;

class Person_18
{
public:

	// 构造函数，创建对象前被编译器调用
	Person_18()
	{
		cout << "Person 构造函数被调用" << endl;
	}

	// 析构函数，对象被销毁时被编译器调用
	~Person_18()
	{
		cout << "Person 析构函数被调用" << endl;
	}
};

void test_18_1()
{
	Person_18 personTest;
}

int main18()
{
	//test_18_1();

	Person_18 person;

	system("pause");
	return 0;
}