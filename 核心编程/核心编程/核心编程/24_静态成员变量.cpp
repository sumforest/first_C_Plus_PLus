#include <iostream>
using namespace std;

class Person_24
{
public:
	// 1.���ж�����һ������
	// 2.�ڱ���׶ξͷ�����cu��
	// 3.���������������ʼ������
	static int m_a;
};

int Person_24::m_a = 100;

void test_24_1()
{
	Person_24 p;
	cout << p.m_a << endl;

	Person_24 p2;
	p2.m_a = 200;
	cout << p.m_a << endl;
}

void test_24_2()
{
	// 1.ͨ����ʵ������
	//Person_24 p1;
	//cout << p1.m_a << endl;
	// 2.ͨ����������
	cout << Person_24::m_a << endl;
}

int main24()
{
	//test_24_1();
	test_24_2();

	system("pause");
	return 0;
}