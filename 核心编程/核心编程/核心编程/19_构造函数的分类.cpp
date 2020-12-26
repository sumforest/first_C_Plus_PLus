#include <iostream>
using namespace std;

class Person_19
{
public:
	Person_19()
	{
		cout << "无参构造函数被调用" << endl;
	}

	Person_19(int a)
	{
		cout << "有参构造被调用" << endl;
	}

	Person_19(const Person_19 &p)
	{
		cout << "拷贝构造函数被调用" << endl;
	}
};

int main19()
{
	// 调用方法：
	// 括号法
	//Person_19 p1; // 调用无参构造方法
	//Person_19 p2(10); // 调用有参构造
	// 使用括号调用无参构造编译器会认为声明函数而不是创建对象
	//Person_19 p3();

	// 显式法
	Person_19 p4 = Person_19(10);
	// 调用拷贝构造函数
	//Person_19 p5 = Person_19(p4);
	// 匿名对象,特点：当前行执行结束，匿名对象会被回收
	//Person_19 p6;
	//注意： 不要使用拷贝构造函数初始化匿名对象,编译器会认为重定义
	//Person_19(p4);

	// 隐式转换法
	Person_19 p7 = 10; // 调用有参构造
	Person_19 p8 = p4; // 调用拷贝构造函数

	system("pause");
	return 0;
}