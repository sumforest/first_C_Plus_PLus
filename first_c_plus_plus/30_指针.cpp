#include <iostream>
using namespace std;

int main30()
{
	int a = 10;
	// ����ָ��
	int *p;
	// ��ָ�븳ֵ
	p = &a;
	cout << "����a���ڴ��ַ��" << &a << endl;
	cout << "ָ��p��ֵ��" << p << endl;

	// ʹ��ָ��,������
	*p = 1000;
	cout << "a = " << a << endl;
	cout << "*p = " << *p << endl;

	system("pause");
	return 0;
}