#include <iostream>
using namespace std;

class Person_36
{
public:
	Person_36(int a)
	{
		age = new int(a);
	}

	// ���������ͷ��ڴ�
	~Person_36()
	{
		if (age != NULL)
		{
			delete age;
			age = NULL;
		}
	}

	Person_36& operator=(Person_36 &p)
	{
		// ��ֵ֮ǰ�жϵ�ǰ��age�Ƿ��Ѿ������ڴ棬���������ڴ����ͷ�
		if (age != NULL)
		{
			delete age;
			age = NULL;
		}

		// ���
		age = new int(*p.age);
		return *this;
	}
	
	int *age;
};

void test_36()
{
	Person_36 p1(18);
	Person_36 p2(20);

	p1 = p2;

	cout << "p1������ = " << *p1.age << endl;
	cout << "p2������ = " << *p2.age << endl;
}

int main36()
{
	test_36();

	system("pause");
	return 0;
}