#include <iostream>
using namespace std;

class MyInteger
{
	friend ostream& operator<<(ostream &cout, MyInteger mi);
public:
	MyInteger()
	{
		num = 0;
	}

	// ����ǰ��++,�������ö��++����ͬһ������
	MyInteger& operator++()
	{
		num++;
		return *this;
	}

	// ռλ����int��ʾ����++
	MyInteger operator++(int)
	{
		MyInteger temp = *this;
		num++;
		return temp;
	}
private :
	int num;
};

// �������������
ostream& operator<<(ostream &cout,MyInteger mi)
{
	cout << mi.num;
	return cout;
}

void test_35()
{
	MyInteger mi;
	cout << mi++ << endl;
	cout << mi << endl;
}

int main35()
{
	test_35();

	system("pause");
	return 0;
}