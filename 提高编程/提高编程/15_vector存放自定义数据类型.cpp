#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Person_15
{
public:
	Person_15(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

void test_15()
{
	vector<Person_15> v;
	Person_15 p1("p1", 10);
	Person_15 p2("p2", 20);
	Person_15 p3("p3", 30);
	Person_15 p4("p4", 40);
	Person_15 p5("p5", 50);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	// 遍历
	for (vector<Person_15>::iterator  it = v.begin() ; it != v.end(); it++)
	{
		cout << "姓名：" << (*it).name << "；年龄：" << (*it).age << endl;
	}

}

void test_15_2()
{
	vector<Person_15*> v;
	Person_15 p1("p1", 10);
	Person_15 p2("p2", 20);
	Person_15 p3("p3", 30);
	Person_15 p4("p4", 40);
	Person_15 p5("p5", 50);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	// 遍历
	for (vector<Person_15*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it)->name << "；年龄：" << (*it)->age << endl;
	}
}

int main15()
{
	//test_15();
	test_15_2();

	system("pause");
	return 0;
}