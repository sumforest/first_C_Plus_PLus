#include <iostream>
using namespace std;

// ����Ĭ�ϲ���������ʼ��ֻҪ��Ĭ�ϲ�����ô����Ĳ�����Ҫ��Ĭ�ϲ���
int defaultNum(int a = 0, int b = 10, int c = 20)
{
	return a + b + c;
}

// ������Ĭ�ϲ����У������������ͺ�����ʵ��ֻ����һ��
int defaultNum2(int a, int b = 20, int c = 20);

int defaultNum2(int a, int b, int c)
{
	return a + b + c;
}

int main10()
{


	system("pause");
	return 0;
}