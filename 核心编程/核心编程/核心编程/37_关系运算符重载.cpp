#include <iostream>
using namespace std;
#include <string>

class Person_37
{
public:
	Person_37(int age,string name):age(age),name(name)
	{

	}

	bool operator==(Person_37 p)
	{
		if (this->age == p.age && this->name == p.name)
		{
			return true;
		}
		return false;
	}

	bool operator!=(Person_37 p)
	{
		if (this->age == p.age && this->name == p.name)
		{
			return false;
		}
		return true;
	}

	int age;
	string name;
};

void test_37()
{
	Person_37 p1(20, "Tom");
	Person_37 p2(21, "Tom");

	if (p1 == p2)
	{
		cout << "p1 和 p2 相等" << endl;
	}

	if (p1 != p2)
	{
		cout << "p1 和 p2 不相等" << endl;
	}

}

int main37()
{
	test_37();

	system("pause");
	return 0;
}