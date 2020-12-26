#include <iostream>
using namespace std;

template<class T>
bool isEqual(T& a, T& b)
{
	return a == b;
}

class Person5
{
public:
	Person5(int age,string name)
	{
		this->age = age;
		this->name = name;
	}
	int age;
	string name;
};

// 具体化函数模板
template<> bool isEqual(Person5& a, Person5& b)
{
	return a.age == b.age && a.name == b.name;
}


void test_5_1()
{
	int a = 10;
	int b = 10;
	cout << isEqual(a, b) << endl;
}

void test_5_2()
{
	Person5 p1(18, "Tom");
	Person5 p2(18, "Tom");
	cout << isEqual(p1, p2) << endl;
}

int main5()
{
	//test_5_1();
	test_5_2();

	system("pause");
	return 0;
}