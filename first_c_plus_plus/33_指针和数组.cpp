#include <iostream>
using namespace std;

int main33()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	
	// ʹ��ָ����������һ��Ԫ��
	int *p = arr;
	cout << "�����һ��Ԫ�أ�" << *p << endl;
	cout << "����ڶ���Ԫ�أ�" << *++p << endl;

	// ʹ��ָ���������
	int *p2 = arr;
	for (int i = 0; i < 10; i++)
	{
		cout << *p2 << endl;
		p2++;
	}

	system("pause");
	return 0;
}