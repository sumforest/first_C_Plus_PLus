#include <iostream>
using namespace std;

class Base_42
{
public:
	Base_42()
	{
		a = 10;
	}

	void test()
	{
		cout << "����� test()" << endl;
	}

	void test(int a)
	{
		cout << "����� test(int a)" << endl;
	}

	int a;
};

class Son_42:public Base_42
{
public:
	Son_42()
	{
		a = 20;
	}

	void test()
	{
		cout << "����� test()" << endl;
	}

	int a ;
};

void test_42()
{
	Son_42 son;
	cout << "���� a = " << son.a << endl;
	cout << "���� a = " << son.Base_42::a << endl;
}

void test_42_1()
{
	Son_42 son;
	// ����������ͬ���ĳ�Ա�������������б����أ�Ҫ���������з�����Ҫ��������
	//son.test(10);
	//son.Base_42::test();
	son.Base_42::test(10);
}

int main42()
{
	//test_42();
	test_42_1();

	system("pause");
	return 0;
}