#include <iostream>
using namespace std;

int add(int a,int b)
{
	return a + b;
}

template<class T>
T add_template(T a, T b)
{
	return a + b;
}

void test_3_1()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	// ������ʽ����ת��
	cout << add(a, c) << endl;
	// �������������
	//cout << add_template(a, c) << endl;
	cout << add_template<int>(a, c) << endl;
}

int main3()
{
	/*
	����
	1.��ͨ�����ᷢ����ʽת��
	2.����ģ���ڵ���ʱû����ʾָ�����ͣ��ñ������Զ������Ƶ����ᷢ����ʽ����ת��
	3.����ģ���ڵ���ʱ�ֶ���ָ�����ͣ��ᷢ������ת��
	�ܽ�:
	�ڵ��ú���ģ��ʱ�����ʾ��ָ�����ͣ���Ϊ�����Լ�ȷ�����õ�����T
	*/
	test_3_1();

	system("pause");
	return 0;
}