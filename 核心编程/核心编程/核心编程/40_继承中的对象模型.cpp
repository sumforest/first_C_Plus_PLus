#include <iostream>
using namespace std;

class Base
{
public:
	int a;
	int b;
private :
	int c;
};

class Son :public Base
{
public:
	int d;
};

void test_40()
{
	cout << "������Ĵ�С�� " << sizeof(Son) << endl;
}

int main40()
{
	test_40();

	system("pause");
	return 0;
}