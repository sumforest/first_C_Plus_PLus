#include <iostream>
using namespace std;

// 函数占位参数，调用时必须补全占位参数
void test10(int a, int)
{
	cout << "这是占位参数" << endl;
}

// 函数占位参数带默认值，调用时可以不补全
void test11(int a, int = 10)
{
	cout << "这是占位参数,带默认值" << endl;
}

int main11()
{
	
	//test10(10,1);
	test11(10);

	system("pause");
	return 0;
}