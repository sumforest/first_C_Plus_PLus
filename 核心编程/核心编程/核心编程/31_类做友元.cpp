#include	<iostream>
using namespace std;
#include <string>

// 类声明
class Buildding_31;

class GoodGay
{
public:
	GoodGay();
	// building类型指针
	Buildding_31 *buildding_31;

	void visited();
};

class Buildding_31
{
	// 类做友元
	friend class GoodGay;
public:
	Buildding_31();

public:
	string sittingRoom;

private:
	string bedRoom;
};

GoodGay::GoodGay() 
{
	// 在堆区分配内存，不然构造函数执行完毕后内存将会被编译器释放
	buildding_31 = new Buildding_31();
}

Buildding_31::Buildding_31() 
{
	sittingRoom = "客厅";
	bedRoom = "卧室";
}


void GoodGay:: visited()
{
	cout << "好基友正在访问：" << buildding_31->sittingRoom << endl;
	cout << "好基友正在访问：" << buildding_31->bedRoom << endl;
}

void test_31()
{
	GoodGay gg;
	gg.visited();
}
int main31()
{
	test_31();

	system("pause");
	return 0;
}