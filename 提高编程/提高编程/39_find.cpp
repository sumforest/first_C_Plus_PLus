#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>

void test_40_1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator res =  find(v.begin(), v.end(), 5);
	if (res == v.end())
	{
		cout << "û���ҵ�";
	}
	else
	{
		cout << "�ҵ��ˣ�" << *res << endl;
	}
}

class Person_39
{
public:
	Person_39(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	// �Զ�������ʹ��find()��Ҫ����==
	bool operator==(const Person_39& val)
	{
		return this->name == val.name && this->age == val.age;
	}
	string name;
	int age;
};

void test_40_2()
{
	vector<Person_39> v;
	v.push_back(Person_39("aa", 10));
	v.push_back(Person_39("bb", 20));
	v.push_back(Person_39("cc", 30));
	v.push_back(Person_39("dd", 40));
	v.push_back(Person_39("ee", 50));

	vector<Person_39>::iterator res = find(v.begin(), v.end(), Person_39("bb", 20));
	if (res == v.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��ˣ� name=" << res->name << " age=" << res->age << endl;
	}
}

int main39()
{
	//test_40_1();
	test_40_2();

	system("pause");
	return 0;
}