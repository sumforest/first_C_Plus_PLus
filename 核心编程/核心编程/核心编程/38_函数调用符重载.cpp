#include <iostream>
using namespace std;
#include <string>

class MyPrint
{
public:
	// 重载函数调用符
	void operator()(string content)
	{
		cout << content << endl;
	}
};

class MyAdd
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};

void test_38()
{
	MyPrint myprint;
	myprint("hello world");
}

void test_38_1()
{
	cout << MyAdd()(100, 100) << endl;
}

int main38()
{
	//test_38();
	 test_38_1();

	system("pause");
	return 0;
}