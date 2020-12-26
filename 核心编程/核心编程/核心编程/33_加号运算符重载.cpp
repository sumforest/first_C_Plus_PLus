#include <iostream>
using namespace std;

class Person_33
{
public: 
	// 初始化参数列表
	Person_33(int a, int b):a(a),b(b)
	{

	}
	
	// 成员函数重载“+”号运算符
	/*Person_33 operator+(Person_33 &p)
	{
		Person_33 temp (this->a + p.a, this->b + p.b);
		return temp;
	}*/

	int a;
	int b;
};


// 全局函数重载 “+”号运算符
Person_33 operator+(Person_33 &p1, Person_33 &p2)
{
	Person_33 temp(p1.a + p2.a, p1.b + p2.b);
	return temp;
}

// 运算符重载发生函数重载
Person_33 operator+(Person_33 &p1,int val)
{
	Person_33 temp(p1.a + val, p1.b + val);
	return temp;
}

void test_33()
{
	Person_33 p1(10, 10);
	Person_33 p2(10, 10);
	
	Person_33 p3 = p1 + p2;
	cout << "p3.a = " << p3.a << endl;
	cout << "p3.b = " << p3.b << endl;

	Person_33 p4 = p1 + 100;
	cout << "p4.a = " << p4.a << endl;
	cout << "p4.b = " << p4.b << endl;
}

int main33()
{
	test_33();

	system("pause");
	return 0;
}