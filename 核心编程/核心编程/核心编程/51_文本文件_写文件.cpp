#include <iostream>
using namespace std;
#include <fstream>

void test_51()
{
	// 1.����д�ļ�����
	ofstream ofs;
	// 2.�����ļ�λ�ã�������ʽ
	ofs.open("test.txt", ios::out);
	// 3.д������
	ofs << "����������" << endl;
	ofs << "���䣺22" << endl;
	ofs << "�Ա���" << endl;

	// 4. �ر��ļ�
	ofs.close();
}

int main51()
{
	test_51();

	system("pause");
	return 0;
}