#include <iostream>
using namespace std;
#include <string>

class Buildding
{
	// 全局函数做友元
	friend void test_30(Buildding *b);

public:
	Buildding()
	{
		sittingRoom = "客厅";
		bedRoom = "卧室";
	}

public:
	string sittingRoom;

private:
	string bedRoom;
};

void test_30(Buildding *b)
{
	cout << "好基友,正在访问："<< b->sittingRoom << endl;
	cout << "好基友,正在访问："<< b->bedRoom << endl;
}

void test_30_1()
{
	Buildding b;
	test_30(&b);
}

int main30()
{
	test_30_1();

	system("pause");
	return 0;
}