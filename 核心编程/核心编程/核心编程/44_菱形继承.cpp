#include  <iostream>
using namespace std;

class Animal 
{
public:
	int m_age;
};

// virtual虚继承，使用虚继承后子类子存在一个相同的变量
class Sheep :virtual public Animal
{

};

class Tuo :virtual public Animal
{

};

class SheepTuo:public Sheep,public Tuo
{

};

void test_44()
{
	SheepTuo st;
	//问题：1. 菱形继承存在二义性
	//st.m_age;
	st.Sheep::m_age = 18;
	st.Tuo::m_age = 28;
	
	// 问题： 菱形继承两个子类存在两个相同的变量，浪费资源而且具有歧义
	// 解决办法： 使用虚继承
	cout << "羊驼的年龄 = " << st.m_age << endl;
}

int main44()
{
	test_44();

	system("pause");
	return 0;
}