#include <iostream>
using namespace std;
#include <string>

void test_20_1()
{
	string str1 = "abcdefgde";
	
	// find�������Ҳ�
	//int res = str1.find("de");
	// ���������
	int res = str1.rfind("de");
	if (res == -1)
	{
		cout << "�����ҵ��ַ���������" << endl;
		return;
	}
	cout << "Ŀ���ַ������±꣺" << res << endl;
}

void test_20_2()
{
	string str1 = "abcdef";
	// ���±�Ϊ1�ַ���ʼ��3���ַ��滻�ɡ�1111��
	str1.replace(1, 3, "1111");
	cout << "replace����ַ�����" << str1 << endl;
}

int main20()
{
	//test_20_1();
	test_20_2();

	system("pause");
	return 0;
}