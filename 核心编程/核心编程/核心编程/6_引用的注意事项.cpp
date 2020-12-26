#include <iostream>
using namespace std;

int main6()
{
	// 注意事项：1.引用必须初始化
	int a = 10;
	//int &b;
	int &b = a;

	// 注意事项: 2.引用初始化后不可以改变
	int c = 20;
	// 赋值操作
	b = c;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	system("pause");
	return 0;
}