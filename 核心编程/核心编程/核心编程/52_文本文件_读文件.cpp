#include <iostream>
using namespace std;
#include <fstream>
#include <string>

void test_52() 
{
	// 1.����������
	ifstream ifs;

	// 2.���ô򿪷�ʽ
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return ;
	}

	// 3.��ȡ�ļ�
	// ��ʽ1
	//char buf[1024] = { 0 };
	//while (ifs>>buf)
	//{
	//	cout << buf << endl;
	//}

	// ��ʽ2
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	// ��ʽ3
	//string str;
	//while (getline(ifs, str))
	//{
	//	cout << str << endl;
	//}

	// ��ʽ4
	char ch;
	while ((ch = ifs.get()) != EOF)
	{
		cout << ch;
	}

	// 4.�ر��ļ�
	ifs.close();
}

int main52()
{
	test_52();

	system("pause");
	return 0;
}