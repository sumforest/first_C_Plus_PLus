#include <iostream>
using namespace std;
#include <string>

class Building_32;

class GoodGay_32
{
public:
	GoodGay_32();

	Building_32 *building;

	// ���Է���Building��˽������
	void test1();
	// ���ܷ���Building��˽������
	void test2();
};

class Building_32
{
	// ��Ա��������Ԫ
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
	sittingRoom = "����";
	bedRoom = "����";
}

GoodGay_32::GoodGay_32()
{
	building = new Building_32();
}

void GoodGay_32::test1()
{
	cout << "test1�û������ڷ��ʣ�" << building->sittingRoom << endl;
	cout << "test1�û������ڷ��ʣ�" << building->bedRoom << endl;
}

void GoodGay_32::test2()
{
	cout << "test2�û������ڷ��ʣ�" << building->sittingRoom << endl;
	//cout << "test1�û������ڷ��ʣ�" << building->bedRoom << endl;
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