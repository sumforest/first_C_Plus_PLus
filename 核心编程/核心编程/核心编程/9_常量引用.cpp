#include <iostream>
using namespace std;

// �������÷�ֹ���õ�ֵ���޸�
void print(const int& val)
{
	//val = 1000;
	cout << "val = " << val << endl;
}

int main9()
{
	// �����ó�ʼ������ʱ��֪���ڴ�ռ�
	// 10���ڴ��ַδ֪����
	//int& ref = 10;

	// �������������̣�int temp = 10; const int& ref = temp;
	//const int& ref = 10;

	int a = 10;

	print(a);

	system("pause");
	return 0;
}