#include <iostream>
using namespace std;
int main15()
{
	// ������ֻС�������ʹ��if-else����ҳ��������е�
	int a = 0;
	int b = 0;
	int c = 0;
	cout << "������С��A�����أ�" << endl;
	cin >> a;
	cout << "������С��B�����أ�" << endl;
	cin >> b;
	cout << "������С��C�����أ�" << endl;
	cin >> c;
	cout <<  endl;

	cout << "С��A�����أ�" << a<< endl;
	cout << "С��B�����أ�" << b<<endl;
	cout << "С��C�����أ�" << c << endl;
	cout << endl;

	if (a > b)
	{
		if (a > c)
		{
			cout << "С��A����" << endl;
		}
		else
		{
			cout << "С��C����" << endl;
		}
	}
	else
	{
		if (b > c)
		{
			cout << "С��B����" << endl;
		}
		else
		{
			cout << "С��C��" << endl;
		}
	}

	system("pause");
	return 0;
}