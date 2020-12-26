#include <iostream>
using namespace std;

class MyInteger
{
	friend ostream& operator<<(ostream &cout, MyInteger mi);
public:
	MyInteger()
	{
		num = 0;
	}

	// 重载前置++,返回引用多次++操作同一个对象
	MyInteger& operator++()
	{
		num++;
		return *this;
	}

	// 占位参数int表示后置++
	MyInteger operator++(int)
	{
		MyInteger temp = *this;
		num++;
		return temp;
	}
private :
	int num;
};

// 重载左移运算符
ostream& operator<<(ostream &cout,MyInteger mi)
{
	cout << mi.num;
	return cout;
}

void test_35()
{
	MyInteger mi;
	cout << mi++ << endl;
	cout << mi << endl;
}

int main35()
{
	test_35();

	system("pause");
	return 0;
}