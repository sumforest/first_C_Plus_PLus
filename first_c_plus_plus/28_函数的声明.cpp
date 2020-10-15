#include <iostream>
using namespace std;

// 函数声明告诉编译器这个函数的存在
int max(int a, int b);

int main28()
{
	int a = 10;
	int b = 20;
	cout << max(a, b) << endl;

	system("pause");
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}