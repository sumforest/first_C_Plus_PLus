#include <iostream>
using namespace std;

class Test_22 {
public:
	int m_a;
	int m_b;
	int m_c;

	// 初始化参数列表
	Test_22(int a, int b, int c) :m_a(a), m_b(b), m_c(c)
	{

	}
};

void test_22_1()
{
	Test_22 t(30, 20, 10);
	cout << "m_a = " << t.m_a << endl;
	cout << "m_b = " << t.m_b << endl;
	cout << "m_c = " << t.m_c << endl;
}

int main22()
{
	test_22_1();
	system("pause");
	return 0;
}