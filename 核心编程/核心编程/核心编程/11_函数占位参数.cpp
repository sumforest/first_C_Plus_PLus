#include <iostream>
using namespace std;

// ����ռλ����������ʱ���벹ȫռλ����
void test10(int a, int)
{
	cout << "����ռλ����" << endl;
}

// ����ռλ������Ĭ��ֵ������ʱ���Բ���ȫ
void test11(int a, int = 10)
{
	cout << "����ռλ����,��Ĭ��ֵ" << endl;
}

int main11()
{
	
	//test10(10,1);
	test11(10);

	system("pause");
	return 0;
}