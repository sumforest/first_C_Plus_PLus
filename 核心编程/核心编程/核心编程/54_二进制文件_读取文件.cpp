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
	// 创建输入流
	ifstream ifs("person.txt", ios::in | ios::binary);
	// 判断文件是否读取成功
	if (!ifs.is_open())
	{
		cout << "读取文件失败" << endl;
		return;
	}
	// 读取文件
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
