#include <iostream>
using namespace std;

// 全局变量
int g_a = 10;
int g_b = 10;

// const修饰的全局变量
const int c_g_a = 10;
const int c_g_b = 10;


int main1()
{
	// 局部变量
	int l_a = 10;
	int l_b = 20;
	cout << "局部变量l_a的地址：" << (int)&l_a << endl;
	cout << "局部变量l_b的地址：" << (int)&l_b << endl;

	cout << "全局变量g_a内存地址：" << (int)&g_a << endl;
	cout << "全局变量g_b内存地址：" << (int)&g_b << endl;

	// 静态变量
	static int s_a = 10;
	static int s_b = 10;
	cout << "静态变量s_a内存地址：" << (int)&s_a << endl;
	cout << "静态变量s_b内存地址：" << (int)&s_b << endl;

	// 常量：字符串
	cout << "字符串内存地址：" << (int)&"HelloWorld" << endl;
	// 常量：const修饰的局部变量
	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "const修饰的局部变量c_l_a内存地址：" << (int)&c_l_a << endl;
	cout << "const修饰的局部变量c_l_b内存地址：" << (int)&c_l_b << endl;
	// 常量： const修饰的全局变量
	cout << "const修饰的全局变量c_g_a：" << (int)&c_g_a << endl;
	cout << "const修饰的全局变量c_g_b：" << (int)&c_g_b << endl;

	system("pause");
	return 0;
}