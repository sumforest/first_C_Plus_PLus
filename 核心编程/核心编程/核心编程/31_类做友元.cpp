#include	<iostream>
using namespace std;
#include <string>

// ������
class Buildding_31;

class GoodGay
{
public:
	GoodGay();
	// building����ָ��
	Buildding_31 *buildding_31;

	void visited();
};

class Buildding_31
{
	// ������Ԫ
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
	// �ڶ��������ڴ棬��Ȼ���캯��ִ����Ϻ��ڴ潫�ᱻ�������ͷ�
	buildding_31 = new Buildding_31();
}

Buildding_31::Buildding_31() 
{
	sittingRoom = "����";
	bedRoom = "����";
}


void GoodGay:: visited()
{
	cout << "�û������ڷ��ʣ�" << buildding_31->sittingRoom << endl;
	cout << "�û������ڷ��ʣ�" << buildding_31->bedRoom << endl;
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