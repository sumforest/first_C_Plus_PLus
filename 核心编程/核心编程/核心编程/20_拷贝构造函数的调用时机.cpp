#include <iostream>
using namespace std;

class Person_20
{
public:
	Person_20()
	{
		cout << "Ĭ���޲ι��챻����" << endl;
	}

	Person_20(int age)
	{
		m_age = age;
		cout << "�вι��캯��������" << endl;
	}

	Person_20(const Person_20& p)
	{
		cout << "�������캯��������" << endl;
		m_age = p.m_age;
	}

public:
	int m_age;
};

// �������캯�������õ�ʱ��
// �����õĶ������ڳ�ʼ���µĶ���
void test_20_1()
{
	Person_20 p1(10);
	cout << "p1������ = " << p1.m_age << endl;
	Person_20 p2(p1);
	cout << "p2������ = " << p2.m_age << endl;
}

// ֵ���ݵķ�ʽ������������ֵ
void dowork(Person_20 p)
{

}

void test_20_2() 
{
	Person_20 p = 10;
	dowork(p);
}

// ���ؾֲ�����ʱ������
Person_20 dowork2()
{
	Person_20 p(10);
	cout << "p�ĵ�ַ:" << &p << endl;
	return p;
}

void test_20_3()
{
	Person_20 pReceive = dowork2();
	cout << "pReceive �ĵ�ַ��" << &pReceive << endl;
}

int main20()
{
	//test_20_1();

	//test_20_2();

	test_20_3();

	system("pause");
	return 0;
}