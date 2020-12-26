#include <iostream>
using namespace std;
#include<string>

template <class NameType, class AgeType = int>
class Person_7
{
public:
	Person_7(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}

	void showInfo()
	{
		cout << this->name << " " << this->age << endl;
	}

	NameType name;
	AgeType age;
};

// 区别：
// 1.类模板没有自动类型转换
void test_7()
{
	Person_7<string, int> p("张三", 22);
	p.showInfo();
}

// 2.类模板的类型参数列表可以有默认值
void test_7_2()
{
	Person_7<string> p("孙悟空", 22);
	p.showInfo();
}


int main7()
{
	//test_7();
	test_7_2();

	system("pause");
	return 0;
}