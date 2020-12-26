#include <iostream>
using namespace std;
#include <string>

template<class T1, class T2>
class Person_12;


template<class T1, class T2>
void showInfo2(Person_12<T1,T2> &p)
{
	cout << "name: " << p.name << " ;age: " << p.age << endl;
}

template<class T1,class T2>
class Person_12
{
	// 全局函数类内实现
	friend void showInfo(Person_12 &p)
	{
		cout << "name: " << p.name << " ;age: " << p.age << endl;
	}

	friend void showInfo2<>(Person_12 &p);

public:
	Person_12(T1 name, T2 age)
	{
		this->name = name;
		this->age = age;
	}
private:
	T1 name;
	T2 age;
};

void test_12()
{
	Person_12<string,int> p("张三", 22);
	//showInfo(p);
	showInfo2(p);
}

int main12()
{
	test_12();

	system("pause");
	return 0;
}