#include <iostream>
using namespace std;

class Person_26
{
public:
	// ����ٶ�����
	int a;
	// ������ٶ�����
	static int b;
	// ������ٶ�����
	static void func() 
	{

	}
	// ������ٶ�����
	void func2()
	{

	}
};

int Person_26::b = 20;

void test_26_1()
{
	Person_26 p;
	// C++�пն�����ռ���ڴ�ռ�Ϊ1�ֽ�
	// C++��������Ϊÿ���ն������1���ֽڵĿռ䣬��Ϊ�����ֿն���ռ���ڴ��λ�ã�ÿ���ն������Ŷ�һ�޶����ڴ��ַ
	cout << "����Ĵ�С��" << sizeof(p) << endl;
}

void test_26_2()
{
	Person_26 p;
	cout << "Person_26��Ĵ�С��" << sizeof(p) << endl;
}

int main26()
{
	//test_26_1();
	test_26_2();

	system("pause");
	return 0;
}