#include <iostream>
using namespace std;

int main21()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "������ռ�ֽڴ�С��" << sizeof(arr) << endl;
	cout << "�����һ��Ԫ�صĴ�С��" << sizeof(arr[0]) << endl;
	cout << "����ĳ��ȣ�" << sizeof(arr) / sizeof(arr[0]) << endl;

	cout << endl;
	// ��ʮ�����Ƶ��ڴ��ַת����ʮ����
	cout << "�����׵�ַ��" <<(int) arr << endl;
	cout << "�����һ��Ԫ�ص�ַ��" << (int)&arr[0] << endl;
	cout << "����ڶ���Ԫ�ص�ַ��" << (int)&arr[1] << endl;

	// ���������ǳ������ܽ��и�ֵ����
	system("pause");
	return 0;
}
