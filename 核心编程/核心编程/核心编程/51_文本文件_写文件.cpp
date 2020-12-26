#include <iostream>
using namespace std;
#include <fstream>

void test_51()
{
	// 1.创建写文件对象
	ofstream ofs;
	// 2.设置文件位置，操作方式
	ofs.open("test.txt", ios::out);
	// 3.写入内容
	ofs << "姓名：张三" << endl;
	ofs << "年龄：22" << endl;
	ofs << "性别：男" << endl;

	// 4. 关闭文件
	ofs.close();
}

int main51()
{
	test_51();

	system("pause");
	return 0;
}