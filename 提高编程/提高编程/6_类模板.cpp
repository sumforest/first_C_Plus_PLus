#include <iostream>
using namespace std;
#include<string>

template <class NameType,class AgeType>
class Person_6
{
public:
	Person_6(NameType name, AgeType age)
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

void test_6()
{
	Person_6<string, int> p("уехЩ", 22);
	p.showInfo();
}


int main6()
{
	test_6();
	
	system("pause");
	return 0;
}