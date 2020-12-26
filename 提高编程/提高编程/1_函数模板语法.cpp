#include <iostream>
using namespace std;

// 定义模板
template<typename T>

void exchange(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main1()
{
	int a = 10;
	int b = 20;
	// 1.自动类型推导
	//exchange(a, b);

	// 2.显示指定类型
	exchange<int>(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	system("pause");
	return 0;
}