#include <iostream>
using namespace std;
#include <fstream>

class Person_54
{
public:
	char name[64];
	int age;
};

void test_54()
{
	// ����������
	ifstream ifs("person.txt", ios::in | ios::binary);
	// �ж��ļ��Ƿ��ȡ�ɹ�
	if (!ifs.is_open())
	{
		cout << "��ȡ�ļ�ʧ��" << endl;
		return;
	}
	// ��ȡ�ļ�
	Person_54 person;
	ifs.read((char*)&person, sizeof(person));
	cout << person.name << " ," << person.age << endl;
}

int main54()
{
	test_54();

	system("pause");
	return 0;
}
