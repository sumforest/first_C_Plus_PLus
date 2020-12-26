#include <iostream>
using namespace std;

int main5()
{
	// 引用，本质就是起别名
	int a = 10;
	
	int &b = a;
	b = 20;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	system("pause");
	return 0;
}