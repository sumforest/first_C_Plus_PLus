#include <iostream>
using namespace std;

class Person_19
{
public:
	Person_19()
	{
		cout << "�޲ι��캯��������" << endl;
	}

	Person_19(int a)
	{
		cout << "�вι��챻����" << endl;
	}

	Person_19(const Person_19 &p)
	{
		cout << "�������캯��������" << endl;
	}
};

int main19()
{
	// ���÷�����
	// ���ŷ�
	//Person_19 p1; // �����޲ι��췽��
	//Person_19 p2(10); // �����вι���
	// ʹ�����ŵ����޲ι������������Ϊ�������������Ǵ�������
	//Person_19 p3();

	// ��ʽ��
	Person_19 p4 = Person_19(10);
	// ���ÿ������캯��
	//Person_19 p5 = Person_19(p4);
	// ��������,�ص㣺��ǰ��ִ�н�������������ᱻ����
	//Person_19 p6;
	//ע�⣺ ��Ҫʹ�ÿ������캯����ʼ����������,����������Ϊ�ض���
	//Person_19(p4);

	// ��ʽת����
	Person_19 p7 = 10; // �����вι���
	Person_19 p8 = p4; // ���ÿ������캯��

	system("pause");
	return 0;
}