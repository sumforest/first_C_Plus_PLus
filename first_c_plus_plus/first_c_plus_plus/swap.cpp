// 双引号表示自定义头文件
#include "swap.h"

// 在源文件编写函数定义
void swapDivd(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}