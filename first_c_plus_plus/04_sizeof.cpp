#include <iostream>
using namespace std;
int main4() 
{
	// short(2) int(4) long(4/8) long long(8)������Linux��32λlong��СΪ4���ֽڣ�64λ��long��Сλ8���ֽ�
	// short < int <= long < long long
	short num1 = 10;
	int num2 = 10;
	long num3 = 10;
	long long num4 = 10;

	cout << "short��ռ�ֽڴ�С��" << sizeof(num1) << endl;
	cout << "int��ռ�ֽڴ�С��" << sizeof(num2) << endl;
	cout << "long��ռ�ֽڴ�С��" << sizeof(num3) << endl;
	cout << "long long��ռ�ֽڴ�С��" << sizeof(num4) << endl;

	system("pause");

	return 0;
}