#include <iostream>
using namespace std;

// �ֲ���������ڶ�����ִ����֮���ɱ����������ͷ�
// ע�⣺ ��Ҫ���ؾֲ��������ڴ��ַ���в�������Ϊ����ʱ��ַ��ָ����ڴ��Ѿ����������ͷ���
int* func()
{
	int a = 10;
	return &a;
}

int main2()
{
	int* p=  func();
	// ��һ�δ�ӡ����ʱ��Ϊ������Ϊ���Ǳ�����һ��ʹ�õĻ���
	cout << *p << endl;
	cout << *p << endl;

	system("pause");
	return 0;
}