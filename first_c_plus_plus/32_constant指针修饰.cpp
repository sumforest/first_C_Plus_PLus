#include <iostream>
using namespace std;

int main32()
{
	// const����ָ��-����ָ��,ָ��ָ��ɱ䣬ָ��ָ���ֵ�����Ա�
	int a = 10;
	int b = 10;
	const int *p = &a;
	//*p = 100;
	p = &b;

	// const���γ�����ָ�볣����ָ��ָ�򲻿ɱ䣬ָ��ֵָ���ֵ�ɱ�
	int* const p1 = &a;
	*p1 = 100;
	//p1 = &b;

	// const���γ�����ָ�룬ָ��ָ���ָ��ָ���ֵ�����ɸı�
	const int* const p3 = &a;
	//*p = 100;
	//p = &b;

	system("pause");
	return 0;
}