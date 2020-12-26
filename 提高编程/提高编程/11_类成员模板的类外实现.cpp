#include <iostream>
using namespace std;
#include <string>

template<class T1, class T2>
class Person_11
{
public:
	Person_11(T1 name, T2 age);

	void showInfo();

	T1 name;
	T2 age;
};

template<class T1,class T2>
Person_11<T1,T2>::Person_11(T1 name, T2 age)
{

	this->name = name;
	this->age = age;
}

template<class T1, class T2>
void Person_11<T1, T2>::showInfo()
{
	cout << "name : " << this->name << " ;age: " << this->age << endl;
}

int main11()
{
	Person_11<string,int> p("уехЩ", 23);
	p.showInfo();

	system("pause");
	return 0;
}