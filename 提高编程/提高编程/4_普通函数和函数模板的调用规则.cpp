#include <iostream>
using namespace std;

void test_4_1(int a, int b)
{
	cout << "��ͨ����������" << endl;
}

template<class T>
void test_4_1(T a, T b)
{
	cout << "����ģ�屻����" << endl;
}

// 3.����ģ���������
template<class T>
void test_4_1(T a, T b, T c)
{
	cout << "���صĺ���ģ�屻����" << endl;
}

void test_4()
{
	int a = 10;
	int b = 20;
	//1. ͬʱ������ͨ�����ͺ���ģ��ʱ�����ȵ�����ͨ����
	//test_4_1(a, b);
	// 2.ͨ����ģ������б���ǿ�Ƶ���Ŷģ�庯��
	//test_4_1<>(a, b);
	char c = 'a';
	char d = 'b';
	// 4.�������ģ��������õ�ƥ�䣬��ô���ȵ��ú���ģ��
	test_4_1(c,d);
}

int main4()
{
	test_4();

	system("pause");
	return 0;
}