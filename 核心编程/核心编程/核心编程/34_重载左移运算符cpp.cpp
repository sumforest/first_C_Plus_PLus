#include <iostream>
using namespace std;

class Person_34
{
	friend ostream& operator << (ostream &cout, Person_34 &p);
	
public:
	Person_34(int a,int b) :a(a),b(b)
	{

	}

private:
	int a;
	int b;
};

// 重载左移运算符实现自定义对象输出
ostream& operator << (ostream &cout, Person_34 &p)
{
	cout << "a = " << p.a << ", b = " << p.b;
	return cout;
}

void test_34()
{
	Person_34 p(10, 10);
	cout << p << endl;
}

int main34()
{
	test_34();

	system("pause");
	return 0;
}