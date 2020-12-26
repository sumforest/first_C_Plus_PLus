#include <iostream>
using namespace std;

int main31()
{
	// 空指针用于初始化指针类型
	int *p = NULL;

	// 空指针不能访问
	*p = 100;
	system("pause");
	return 0;
}