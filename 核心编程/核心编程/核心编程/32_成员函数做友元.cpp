#include <iostream>
using namespace std;
#include <string>

class Building_32;

class GoodGay_32
{
public:
	GoodGay_32();

	Building_32 *building;

	// 可以访问Building的私有属性
	void test1();
	// 不能访问Building的私有属性
	void test2();
};

class Building_32
{
	// 成员函数做友元
	friend void GoodGay_32::test1();

public:
	Building_32();

public:
	string sittingRoom;

private:
	string bedRoom;
};

Building_32::Building_32()
{
	sittingRoom = "客厅";
	bedRoom = "卧室";
}

GoodGay_32::GoodGay_32()
{
	building = new Building_32();
}

void GoodGay_32::test1()
{
	cout << "test1好基友正在访问：" << building->sittingRoom << endl;
	cout << "test1好基友正在访问：" << building->bedRoom << endl;
}

void GoodGay_32::test2()
{
	cout << "test2好基友正在访问：" << building->sittingRoom << endl;
	//cout << "test1好基友正在访问：" << building->bedRoom << endl;
}

void test_32()
{
	GoodGay_32 gg;
	gg.test1();
	gg.test2();
}

int main32()
{
	test_32();

	system("pause");
	return 0;
}