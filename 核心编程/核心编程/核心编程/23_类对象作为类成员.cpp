#include <iostream>
using namespace std;
#include <string>

class Phone
{
public:
	Phone(string pName) :m_pName(pName)
	{
		cout << "Phone的构造函数被调用" << endl;
	}

	~Phone()
	{
		cout << "Phone的析构函数被调用" << endl;
	}

	string m_pName;
};

class Person_23
{
public:
	Person_23(string name, string pName) :m_name(name), phone(pName)
	{
		cout << "Person_23的构造函数被调用" << endl;
	}

	~Person_23()
	{
		cout << "Person_23的析构函数被调用" << endl;
	}

	string m_name;
	Phone phone;
};

// 当其他类对象作为当前类成员对象,先构造其他类对象；析构函数相反，本类先执行析构函数然后其他类对象再执行析构函数（栈的先进后出）。
void test_23()
{
	Person_23 p("张三", "iphone 12 Pro Max");
	cout << p.m_name << "拿着：" << p.phone.m_pName << endl;
}

int main23()
{
	test_23();
	
	system("pause");
	return 0;
}