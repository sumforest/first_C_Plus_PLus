#include <iostream>
using namespace std;
#include <string>

class Animal_49
{
public:
	Animal_49()
	{
		cout << "���๹�챻����" << endl;
	}
	// ��������������ڶ�̨�и���ָ���޷�����������������������ڴ�й©
	//virtual ~Animal_49()
	//{
	//	cout << "��������������" << endl;
	//}

	// ������������,��������������ʵ��
	virtual ~Animal_49() = 0;

	virtual void speak() = 0;
};

Animal_49::~Animal_49()
{
	cout << "��������������" << endl;
}

class Cat_49:public Animal_49
{
public:
	Cat_49(string name) 
	{
		cout << "���๹�챻����" << endl;
		this->name = new string(name);
	}

	~Cat_49()
	{
		cout << "������������������" << endl;
		if (name != NULL)
		{
			delete name;
			name = NULL;
		}
	}

	string* name;

	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};

void test_49()
{
	Animal_49 *animal = new Cat_49("Tom");
	animal->speak();
	// �����ڶ��������������鹹�����޷������ã�������ڴ�й©
	delete animal;
}

int main49()
{
	test_49();

	system("pause");
	return 0;
}