#include <iostream>
using namespace std;
#include <string>

// 1.������������в����з���ֵ
class MyReturn
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

void test_31_1()
{
	MyReturn mr;
	cout << mr(10, 20) << endl;
}

// 2.��������������Լ���״̬
class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}
	int count;

	void operator()(string str)
	{
		cout << str << endl;
		count++;
	}
};

void test_31_2()
{
	MyPrint mp;
	mp("hello C++");
	mp("hello C++");
	mp("hello C++");
	mp("hello C++");
	cout << "�ַ�����ӡ������" << mp.count << endl;
}

// 3.����������Ϊ��������
void test_31_3_1(MyPrint& mp,string str)
{
	mp(str);
}

void test_31_3()
{
	MyPrint mp;
	test_31_3_1(mp, "����������Ϊ��������");
}

int main31()
{
	//test_31_1();
	//test_31_2();
	test_31_3();

	system("pause");
	return 0;
}