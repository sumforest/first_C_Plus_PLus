#include <iostream>
using namespace std;

class Base_47
{
public:
	// ���麯�������ڴ��麯������г����ࣻ
	virtual void func() = 0;
};

class Son_47 : public Base_47
{
public:
	// ʵ�ִ��麯��������virtual��ʡ��
	virtual void func()
	{

	}
};

void test_47()
{
	// �������ص�:
	// 1.���ܹ�ʵ����
	// 2.�������ʵ�ִ��麯������������Ҳ�ǳ�����
	//Base_47 base;
	//Base 47* base = new Base_47;

	//Son_47 son;
	Son_47* son =new  Son_47;
}

int main47()
{
	test_47();

	system("pause");
	return 0;
}