#include <iostream>
using namespace std;

class Person_21
{
public:

	Person_21()
	{
		cout << "Ĭ���޲ι��캯��������" << endl;
	}

	Person_21(int age, int height)
	{
		m_age = age;
		m_height = new int(height);
		cout << "�вι��캯��������" << endl;
	}

	Person_21(const Person_21& p)
	{
		m_age = p.m_age;
		m_height = new int(*p.m_height);
		cout << "�������캯��������" << endl;
	}

	~Person_21()
	{
		if (m_height != NULL)
		{
			delete m_height;
			m_height = NULL;
		}
		cout << "��������������" << endl;
	}

	int m_age;

	int* m_height;
};

void test_21_1()
{
	Person_21 p1(18,160);
	Person_21 p2(p1);

	cout << "p1���� = " << p1.m_age << endl;
	cout << "p2���� = " << p2.m_age << endl;
}

int main21()
{
	test_21_1();

	system("pause");
	return 0;
}