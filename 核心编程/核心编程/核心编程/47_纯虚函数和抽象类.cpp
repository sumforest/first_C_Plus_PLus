#include <iostream>
using namespace std;

class Base_47
{
public:
	// 纯虚函数，存在纯虚函数的类叫抽象类；
	virtual void func() = 0;
};

class Son_47 : public Base_47
{
public:
	// 实现纯虚函数，其中virtual可省略
	virtual void func()
	{

	}
};

void test_47()
{
	// 抽象类特点:
	// 1.不能够实例化
	// 2.子类必须实现纯虚函数，否则子类也是抽象类
	//Base_47 base;
	//Base 47* base = new Base_47;

	//Son_47 son;
	Son_47* son =new  Son_47;
}

int main47()
{
	test_47();

	system("pause");
	return 0;
}