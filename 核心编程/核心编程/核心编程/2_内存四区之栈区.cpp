#include <iostream>
using namespace std;

// 局部变量存放在堆区，执行完之后由编译器进行释放
// 注意： 不要返回局部变量的内存地址进行操作，因为操作时地址所指向的内存已经被编译器释放了
int* func()
{
	int a = 10;
	return &a;
}

int main2()
{
	int* p=  func();
	// 第一次打印正常时因为编译器为我们保留了一次使用的机会
	cout << *p << endl;
	cout << *p << endl;

	system("pause");
	return 0;
}