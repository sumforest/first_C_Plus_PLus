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
		// age===this->age;��Ϊ������Ĭ������
		cout << "this.age = " << age << endl;
	}

	int age;
};

int main28()
{
	// ��ָ����ʳ�Ա����
	Person_28 *p = NULL;
	//p->showClassName();
	p->showAge();

	system("pause");
	return 0;
}