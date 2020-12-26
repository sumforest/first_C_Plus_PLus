#include <iostream>
using namespace std;

class Person
{
public:
	string m_Name;

protected:
	string m_Car;

private:
	string m_Password;

public:
	void fucn()
	{
		m_Name = '张三';
		m_Car = "拖拉机";
		m_Password = "123456";
	}
};

int main15()
{
	Person person;
	person.m_Name;
	//person.m_Car;
	//person.m_Password;

	person.fucn();

	system("pause");
	return 0;
}