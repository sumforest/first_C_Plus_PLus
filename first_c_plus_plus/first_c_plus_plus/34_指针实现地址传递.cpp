#include <iostream>
using namespace std;

void swap(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main34()
{
	int a = 10;
	int b = 20;
	// ��ַ����
	swap(&a, &b);
	// ��ַ���ݻ�ñ�ʵ�ε�ֵ
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	system("pause");
	return 0;
}