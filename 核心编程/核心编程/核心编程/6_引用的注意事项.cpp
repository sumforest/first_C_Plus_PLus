#include <iostream>
using namespace std;

int main6()
{
	// ע�����1.���ñ����ʼ��
	int a = 10;
	//int &b;
	int &b = a;

	// ע������: 2.���ó�ʼ���󲻿��Ըı�
	int c = 20;
	// ��ֵ����
	b = c;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	system("pause");
	return 0;
}