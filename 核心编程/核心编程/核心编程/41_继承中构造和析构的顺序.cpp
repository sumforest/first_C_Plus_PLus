#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base ���캯��������" << endl;
	}

	~Base()
	{
		cout << "Base ��������������" << endl;
	}
};

class Son:public Base
{

public:
	Son()
	{
		cout << "Son ���캯��������" << endl;
	}

	~Son()
	{
		cout << "Son ��������������" << endl;
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