#include <iostream>
using namespace std;

// 值传递
void swap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 指针传递
void swap2(int* a, int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 引用传递
void swap3(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}


int main7()
{
	int a = 10;
	int b = 20;

	//swap1(a, b);
	//swap2(&a, &b);
	swap3(a, b);
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	system("pause");
	return 0;
}