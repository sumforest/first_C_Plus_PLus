#include <iostream>
using namespace std;

class Person_18
{
public:

	// ���캯������������ǰ������������
	Person_18()
	{
		cout << "Person ���캯��������" << endl;
	}

	// ������������������ʱ������������
	~Person_18()
	{
		cout << "Person ��������������" << endl;
	}
};

void test_18_1()
{
	Person_18 personTest;
}

int main18()
{
	//test_18_1();

	Person_18 person;

	system("pause");
	return 0;
}