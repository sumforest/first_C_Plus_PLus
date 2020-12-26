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
	// 创建输出流
	ofstream ofs;
	// 指定文件位置，操作文件的方式
	ofs.open("person.txt", ios::out | ios::binary);
	// 写文件
	Person_53 person = { "张三",18 };
	ofs.write((const char*)&person, sizeof(person));
	// 关闭文件
	ofs.close();
}

int main53()
{
	test_53();

	system("pause");
	return 0;
}