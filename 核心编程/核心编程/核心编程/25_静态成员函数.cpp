#include <iostream>
using namespace std;

class Person_25
{
public:

	// 1.���ж���ֻ�ܷ���һ����Ա����
	// 2.��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
	static void func()
	{
		m_a = 200;
		//m_b = 300; ��̬��Ա�������ܷ��ʳ�Ա��������Ϊ���ж��ʵ�����þ�̬��Ա������ʱ�򣬱������޷�ȷ���޸ĵ�ʱ�ĸ�ʵ���ĳ�Ա����
		cout << "��̬��Ա����������" << endl;
	}

	static int m_a;

	int m_b;

private:
	static void func2()
	{

	}
};

int Person_25::m_a = 100;

void test_25_1()
{
	// 1.ͨ������ʵ������
	Person_25 p1;
	p1.func();

	// 2.ͨ����������
	Person_25::func();

	// ������ʲ���˽�õľ�̬��Ա����
	//Person_25::func2();
}

int main25()
{
	test_25_1();
	system("pause");
	return 0;
}