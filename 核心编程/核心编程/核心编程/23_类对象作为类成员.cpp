#include <iostream>
using namespace std;
#include <string>

class Phone
{
public:
	Phone(string pName) :m_pName(pName)
	{
		cout << "Phone�Ĺ��캯��������" << endl;
	}

	~Phone()
	{
		cout << "Phone����������������" << endl;
	}

	string m_pName;
};

class Person_23
{
public:
	Person_23(string name, string pName) :m_name(name), phone(pName)
	{
		cout << "Person_23�Ĺ��캯��������" << endl;
	}

	~Person_23()
	{
		cout << "Person_23����������������" << endl;
	}

	string m_name;
	Phone phone;
};

// �������������Ϊ��ǰ���Ա����,�ȹ���������������������෴��������ִ����������Ȼ�������������ִ������������ջ���Ƚ��������
void test_23()
{
	Person_23 p("����", "iphone 12 Pro Max");
	cout << p.m_name << "���ţ�" << p.phone.m_pName << endl;
}

int main23()
{
	test_23();
	
	system("pause");
	return 0;
}