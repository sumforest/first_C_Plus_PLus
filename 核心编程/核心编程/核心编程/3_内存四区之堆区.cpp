#include <iostream>
using namespace std;

// �����ɳ���Ա������ʹ��new�ؼ��ֿ����ڶ��������ڴ�
int* newFunc()
{
	return new int(10);
}

int main3()
{
	int *p = newFunc();

	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;

	system("pause");
	return 0;
}