#include <iostream>
using namespace std;
#include <string>

class Buildding
{
	// ȫ�ֺ�������Ԫ
	friend void test_30(Buildding *b);

public:
	Buildding()
	{
		sittingRoom = "����";
		bedRoom = "����";
	}

public:
	string sittingRoom;

private:
	string bedRoom;
};

void test_30(Buildding *b)
{
	cout << "�û���,���ڷ��ʣ�"<< b->sittingRoom << endl;
	cout << "�û���,���ڷ��ʣ�"<< b->bedRoom << endl;
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