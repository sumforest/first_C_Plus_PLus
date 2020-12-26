#include <iostream>
using namespace std;
#include <string>

class Animal_49
{
public:
	Animal_49()
	{
		cout << "父类构造被调用" << endl;
	}
	// 虚析构函数解决在多台中父类指针无法调用子类析构函数而造成内存泄漏
	//virtual ~Animal_49()
	//{
	//	cout << "父类析构被调用" << endl;
	//}

	// 纯虚析构函数,纯虚析构必须有实现
	virtual ~Animal_49() = 0;

	virtual void speak() = 0;
};

Animal_49::~Animal_49()
{
	cout << "父类析构被调用" << endl;
}

class Cat_49:public Animal_49
{
public:
	Cat_49(string name) 
	{
		cout << "子类构造被调用" << endl;
		this->name = new string(name);
	}

	~Cat_49()
	{
		cout << "子类析构函数被调用" << endl;
		if (name != NULL)
		{
			delete name;
			name = NULL;
		}
	}

	string* name;

	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};

void test_49()
{
	Animal_49 *animal = new Cat_49("Tom");
	animal->speak();
	// 开辟在堆区的子类对象的虚构函数无法被调用，会造成内存泄漏
	delete animal;
}

int main49()
{
	test_49();

	system("pause");
	return 0;
}