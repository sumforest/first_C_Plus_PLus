#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base 构造函数被调用" << endl;
	}

	~Base()
	{
		cout << "Base 析构函数被调用" << endl;
	}
};

class Son:public Base
{

public:
	Son()
	{
		cout << "Son 构造函数被调用" << endl;
	}

	~Son()
	{
		cout << "Son 析构函数被调用" << endl;
	}
};

void test_41()
{
	//Base b;
	Son son;
}

int main41()
{
	test_41();
	system("pause");
	return 0;
}