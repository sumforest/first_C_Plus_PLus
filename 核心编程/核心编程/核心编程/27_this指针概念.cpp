#include <iostream>
using namespace std;

class Person_27 
{
public:
	int age;
	Person_27(int age)
	{
		// thisָ������ã�1.�����βκͳ�Ա����
		this->age = age;
	}

	// ���뷵�����û���ָ�벻Ȼ�᷵��this�Ŀ���
	Person_27& addAge(Person_27& p)
	{
		this->age += p.age;
		return *this;
	}
};

void test_27_1()
{
	Person_27 p1(10);
	cout << "p1.age = " << p1.age << endl;
}

// thisָ�����ã� 2.���طǾ�̬��Ա�����ж�����
void test_27_2()
{
	Person_27 p1(10);
	Person_27 p2(10);

	p2.addAge(p1).addAge(p1).addAge(p1);
	cout << "p2.age = " << p2.age << endl;
}

int main27()
{
	//test_27_1();
	test_27_2();
	system("pause");
	return 0;
}