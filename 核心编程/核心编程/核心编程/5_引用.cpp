#include <iostream>
using namespace std;

int main5()
{
	// ���ã����ʾ��������
	int a = 10;
	
	int &b = a;
	b = 20;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	system("pause");
	return 0;
}