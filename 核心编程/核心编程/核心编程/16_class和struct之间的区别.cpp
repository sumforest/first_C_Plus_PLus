#include <iostream>
using namespace std;

// class 和 struct最大的不同在于访问权限的不同：
// class默认权限时私有
// struct默认权限时公共的

class C
{
	int a;
};

struct S
{
	int b;
};


int main16()
{
	C c;
	// 不可访问
	//c.a = 10;

	S s;
	s.b = 100;

	system("pause");
	return 0;
}