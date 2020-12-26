#include <iostream>
using namespace std;

template<class T>
class Base_9
{
public:
	T m_a;
};

class Son_9 :public Base_9<int>
{
public:
	int m_b;
};

template<class T1,class T2>
class Son_9_1 :public Base_9<T2>
{
public:
	Son_9_1()
	{
		cout << "T1的数据类型：" << typeid(T1).name() << endl;
		cout << "T2的数据类型：" << typeid(T2).name() << endl;
	}
	T1 t1;
};

void test_10()
{
	Son_9_1<int ,char> son;
}

int main10()
{
	test_10();
	system("pause");
	return 0;
}