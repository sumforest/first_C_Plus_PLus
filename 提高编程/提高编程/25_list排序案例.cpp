#include <iostream>
using namespace std;
#include <list>
#include <string>

class Person_25
{
public:
	Person_25(string name, int age, int height)
	{
		this->name = name;
		this->age = age;
		this->height = height;
	}
	string name;
	int age;
	int height;
};

bool comparator(Person_25& p1,Person_25& p2)
{
	if (p1.age == p2.age)
	{
		return p1.height > p2.height;
	}
	return p1.age < p2.age;
}

void test_25()
{
	list<Person_25> li;
	Person_25 p1("刘备", 35, 175);
	Person_25 p2("操作", 45, 180);
	Person_25 p3("孙权", 40, 170);
	Person_25 p4("赵云", 25, 190);
	Person_25 p5("张飞", 35, 160);
	Person_25 p6("关羽", 35, 200);

	li.push_back(p1);
	li.push_back(p2);
	li.push_back(p3);
	li.push_back(p4);
	li.push_back(p5);
	li.push_back(p6);

	cout << "排序前：" << endl;
	for (list<Person_25>::const_iterator it = li.begin(); it != li.end(); it++)
	{
		cout << "姓名：" << it->name << " 年龄：" << it->age << " 身高：" << it->height << endl;
	}

	li.sort(comparator);

	cout << "排序后：" << endl;
	for (list<Person_25>::const_iterator it = li.begin(); it != li.end(); it++)
	{
		cout << "姓名：" << it->name << " 年龄：" << it->age << " 身高：" << it->height << endl;
	}
}

int main25()
{
	test_25();

	system("pause");
	return 0;
}