#include <iostream>
using namespace std;

class Person_29
{
public:

	void test1() const
	{
		// thisָ���൱��ָ�볣����ָ��ָ�򲻿��Ըı䣬ָ���ֵ�ɸı�
		// ��������const���ε�ʱthisָ�룬����ָ���ָ�򲻿��Ըı䣬ָ���ֵҲ�����Ըı�
		// �����������޸ĳ�Ա����
		//this->age = 100;
		//this = NULL;
		this->modify = 100;
	}

	void func()
	{

	}

	int age;
	// ����Ա�����м�mutable�ؼ��֣���ô�ڳ������п����޸ģ�
	mutable int modify;
};

void test_29()
{
	// ������
	const Person_29 p;
	// ������ֻ�ܵ��ó�����
	//p.age = 100;
	p.modify = 100;

	p.test1();
	//p.func();
}

int main29()
{

	system("pause");
	return 0;
}