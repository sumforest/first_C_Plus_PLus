#include <iostream>
using namespace std;

// ���������������������Ͳ�ͬ������������ͬ������˳��ͬ
void func()
{
	cout << "func() ������" << endl;
}

void func(int a)
{
	cout << "func(int a) ������" << endl;
}

void func(int a, double b)
{
	cout << "func(int a, double b) ������" << endl;
}

void func(double a, int b)
{
	cout << "func(double a, int b) ������" << endl;
}

// �����ķ���ֵ����Ϊ�������ص�����
//void func()
//{
//
//}

int main12()
{
	//func();
	//func(10);
	//func(10, 3.14);
	//func(3.14, 10);
	func();

	system("pause");
	return 0;
}