#include <iostream>
using namespace std;
#include <fstream>
#include <string>

void test_52() 
{
	// 1.创建流对象
	ifstream ifs;

	// 2.设置打开方式
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return ;
	}

	// 3.读取文件
	// 方式1
	//char buf[1024] = { 0 };
	//while (ifs>>buf)
	//{
	//	cout << buf << endl;
	//}

	// 方式2
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	// 方式3
	//string str;
	//while (getline(ifs, str))
	//{
	//	cout << str << endl;
	//}

	// 方式4
	char ch;
	while ((ch = ifs.get()) != EOF)
	{
		cout << ch;
	}

	// 4.关闭文件
	ifs.close();
}

int main52()
{
	test_52();

	system("pause");
	return 0;
}