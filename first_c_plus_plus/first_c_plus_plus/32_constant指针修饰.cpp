#include <iostream>
using namespace std;

int main32()
{
	// const修饰指针-常量指针,指针指向可变，指针指向的值不可以变
	int a = 10;
	int b = 10;
	const int *p = &a;
	//*p = 100;
	p = &b;

	// const修饰常量，指针常量，指针指向不可变，指针值指向的值可变
	int* const p1 = &a;
	*p1 = 100;
	//p1 = &b;

	// const修饰常量和指针，指针指向和指针指向的值都不可改变
	const int* const p3 = &a;
	//*p = 100;
	//p = &b;

	system("pause");
	return 0;
}