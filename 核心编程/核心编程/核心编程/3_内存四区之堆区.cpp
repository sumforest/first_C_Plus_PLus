#include <iostream>
using namespace std;

// 堆区由程序员来管理，使用new关键字可以在堆区创建内存
int* newFunc()
{
	return new int(10);
}

int main3()
{
	int *p = newFunc();

	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;

	system("pause");
	return 0;
}