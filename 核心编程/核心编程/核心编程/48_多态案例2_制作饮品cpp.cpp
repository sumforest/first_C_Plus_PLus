#include <iostream>
using namespace std;

class AstractDrink
{
public:
	// 煮水
	virtual void boil() = 0;
	// 冲泡
	virtual void brew() = 0;
	// 倒入杯中
	virtual void pour() = 0;
	// 加料
	virtual void charge() = 0;

	void makeDirnk()
	{
		boil();
		brew();
		pour();
		charge();
	}
};

class Coffee :public AstractDrink
{
public:
	virtual void boil()
	{
		cout << "煮沸鼎湖山泉" << endl;
	}

	virtual void brew()
	{
		cout << "把煮沸鼎湖山泉拿来冲泡咖啡" << endl;
	}

	virtual void pour()
	{
		cout << "把冲泡好的咖啡导入杯中" << endl;
	}

	virtual void charge()
	{
		cout << "加入牛奶" << endl;
	}
};

void doDrinking(AstractDrink* abs)
{
	abs->makeDirnk();
	// 释放内存
	delete abs;
}

void test_48()
{
	doDrinking(new Coffee);
}

int main48()
{
	test_48();

	system("pause");
	return 0;
}