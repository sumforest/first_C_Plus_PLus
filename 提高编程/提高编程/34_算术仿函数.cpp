#include <iostream>
using namespace std;
#include <functional>

void test_34_1()
{
	negate<int> n;
	cout << n(50) << endl;
}

void test_34_2()
{
	plus<int> p;
	cout << p(1, 2) << endl;
}

int main34()
{
	//test_34_1();
	test_34_2();

	system("pause");
	return 0;
}