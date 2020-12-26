#include <iostream>
using namespace std;

// 函数默认参数，从左开始，只要由默认参数那么后面的参数都要有默认参数
int defaultNum(int a = 0, int b = 10, int c = 20)
{
	return a + b + c;
}

// 函数的默认参数中，函数的声明和函数的实现只能有一个
int defaultNum2(int a, int b = 20, int c = 20);

int defaultNum2(int a, int b, int c)
{
	return a + b + c;
}

int main10()
{


	system("pause");
	return 0;
}