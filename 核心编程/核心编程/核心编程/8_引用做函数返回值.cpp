#include <iostream>
using namespace std;

// ���ؾֲ�����������
int& returnLocalVar()
{
	int a = 10;
	return a;
}

// ���ÿ�����Ϊ��ֵ
int& returnStaticVar()
{
	static int  a = 10;
	return a;
}


int main8()
{
	//int& ref = returnLocalVar();
	//cout << "a = " << ref << endl;
	//cout << "a = " << ref << endl;

	int& ref2 = returnStaticVar();
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	// �����������ÿ�����ֵ
	returnStaticVar() = 1000;
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	system("pause");
	return 0;
}