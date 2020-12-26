#include <iostream>
using namespace std;

class Animal_45
{
public:
	// 父类函数中virtual修饰,此时speak方法动态绑定。
	// 动态绑定条件：
	// 1.具有继承关系
	// 2.子类重写父类的函数

	//动态多态的使用
	// 父类的指针或引用，执行子类对象
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

class Cat_45 :public Animal_45
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};

void doSpeak(Animal_45 &animal)
{
	// 父类Animal_45中函数是静态绑定的，所以一会一直执行父类的方法
	animal.speak();
}

void test_45()
{
	Cat_45 cat;
	doSpeak(cat);
}

int main45()
{
	test_45();

	system("pause");
	return 0;
}