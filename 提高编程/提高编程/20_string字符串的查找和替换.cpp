#include <iostream>
using namespace std;
#include <string>

void test_20_1()
{
	string str1 = "abcdefgde";
	
	// find从左往右查
	//int res = str1.find("de");
	// 从右往左查
	int res = str1.rfind("de");
	if (res == -1)
	{
		cout << "所查找的字符串不存在" << endl;
		return;
	}
	cout << "目标字符串的下标：" << res << endl;
}

void test_20_2()
{
	string str1 = "abcdef";
	// 从下标为1字符开始的3个字符替换成“1111”
	str1.replace(1, 3, "1111");
	cout << "replace后的字符串：" << str1 << endl;
}

int main20()
{
	//test_20_1();
	test_20_2();

	system("pause");
	return 0;
}