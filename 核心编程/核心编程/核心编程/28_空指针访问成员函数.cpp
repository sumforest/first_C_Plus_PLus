#include <iostream>
using namespace std;

class Person_28
{
public:

	void showClassName()
	{
		cout << "ShowClassName is invoked" << endl;
	}

	void showAge()
	{
		if (this == NULL)
		{
			return;
		}
		// age===this->age;此为编译器默认增加
		cout << "this.age = " << age << endl;
	}

	int age;
};

int main28()
{
	// 空指针访问成员函数
	Person_28 *p = NULL;
	//p->showClassName();
	p->showAge();

	system("pause");
	return 0;
}