#include <iostream>
using namespace std;

// ȫ�ֱ���
int g_a = 10;
int g_b = 10;

// const���ε�ȫ�ֱ���
const int c_g_a = 10;
const int c_g_b = 10;


int main1()
{
	// �ֲ�����
	int l_a = 10;
	int l_b = 20;
	cout << "�ֲ�����l_a�ĵ�ַ��" << (int)&l_a << endl;
	cout << "�ֲ�����l_b�ĵ�ַ��" << (int)&l_b << endl;

	cout << "ȫ�ֱ���g_a�ڴ��ַ��" << (int)&g_a << endl;
	cout << "ȫ�ֱ���g_b�ڴ��ַ��" << (int)&g_b << endl;

	// ��̬����
	static int s_a = 10;
	static int s_b = 10;
	cout << "��̬����s_a�ڴ��ַ��" << (int)&s_a << endl;
	cout << "��̬����s_b�ڴ��ַ��" << (int)&s_b << endl;

	// �������ַ���
	cout << "�ַ����ڴ��ַ��" << (int)&"HelloWorld" << endl;
	// ������const���εľֲ�����
	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "const���εľֲ�����c_l_a�ڴ��ַ��" << (int)&c_l_a << endl;
	cout << "const���εľֲ�����c_l_b�ڴ��ַ��" << (int)&c_l_b << endl;
	// ������ const���ε�ȫ�ֱ���
	cout << "const���ε�ȫ�ֱ���c_g_a��" << (int)&c_g_a << endl;
	cout << "const���ε�ȫ�ֱ���c_g_b��" << (int)&c_g_b << endl;

	system("pause");
	return 0;
}