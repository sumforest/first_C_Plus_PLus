#include <iostream>
using namespace std;

// �����������߱�������������Ĵ���
int max(int a, int b);

int main28()
{
	int a = 10;
	int b = 20;
	cout << max(a, b) << endl;

	system("pause");
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}