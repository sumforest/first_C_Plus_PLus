#include <iostream>
using namespace std;
#include <string>

template<class T1,class T2>
class Person_9
{
public:
	Person_9(T1 name, T2 age)
	{
		this->name = name;
		this->age = age;
	}

	void showInfo()
	{
		cout << "name = " << this->name << " age = " << this->age << endl;
	}

	T1 name;
	T2 age;
};

// 指定类型做参数
void test_9_1(Person_9<string,int> &p)
{
	p.showInfo();
}

// 参数模板化
template<class T1,class T2>
void test_9_2(Person_9<T1,T2> &p)
{
	p.showInfo();
}

// 类模板化
template<class T>
void test_9_3(T t)
{
	t.showInfo();
	cout << "T的类型为：" << typeid(T).name() << endl;
}

void test_9()
{
	Person_9<string,int> p("孙悟空",22);
	//test_9_1(p);
	//test_9_2(p);
	test_9_3(p);
}

int main9()
{
	test_9();

	system("pause");
	return 0;
}