#include <iostream>
using namespace std;

class Base_43_1
{
public:
	Base_43_1() 
	{
		a = 100;
	}

	int a ;
};

class Base_43_2
{
public:
	Base_43_2()
	{
		a = 200;
	}
	
	int a;
};

class Son_43:public Base_43_1,public Base_43_2
{
public:
	Son_43()
	{
		c = 300;
		d = 400;
	}

	int c;
	int d;
};

void test_43()
{
	Son_43 son;
	cout << "Son_42 的大小：" << sizeof(son) << endl;
	cout << "Base_43_1 中a = " << son.Base_43_1::a << endl;
	cout << "Base_43_2 中a = " << son.Base_43_2::a << endl;
}

int main43()
{
	test_43();

	system("pause");
	return 0;
}