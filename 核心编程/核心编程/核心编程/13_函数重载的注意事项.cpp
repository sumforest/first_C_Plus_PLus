#include <iostream>
using namespace std;

void func12_1(int& a)
{
	cout << "func12_1(int &a) ������" << endl;
}

void func12_2(const int& a)
{
	cout << "func12_2(const int& a) ������" << endl;
}

void func12_3(int a, int b = 10)
{
	cout << "func12_3(int a, int b = 10) ������" << endl;
}

void func12_3(int a)
{
	cout << "func12_3(int a) ������" << endl;
}


int main13()
{
	// ��const���ε��β���Ϊ�������ص������ǣ�const���޿�����Ϊ�������ص�����
	//int a = 10;
	//func12_1(a); //���� func12_1(int& a)
	//func12_2(10); //����  func12_2(const int& a)

	// �����غ�����Ĭ��ֵʱ��Ҫ�������������
	//func12_3(10);

	system("pause");
	return 0;
}