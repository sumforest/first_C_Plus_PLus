#include <iostream>
using namespace std;
#include <fstream>
#include <string>

class Person_53
{
public:
	char name[64];
	int age;
};

void test_53()
{
	// ���������
	ofstream ofs;
	// ָ���ļ�λ�ã������ļ��ķ�ʽ
	ofs.open("person.txt", ios::out | ios::binary);
	// д�ļ�
	Person_53 person = { "����",18 };
	ofs.write((const char*)&person, sizeof(person));
	// �ر��ļ�
	ofs.close();
}

int main53()
{
	test_53();

	system("pause");
	return 0;
}