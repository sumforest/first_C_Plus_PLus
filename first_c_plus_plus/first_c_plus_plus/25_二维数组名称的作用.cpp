#include <iostream>
using namespace std;

int main25()
{
	int arr[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	// �鿴��ռ�Ŀռ�
	cout << "��ά����Ĵ�С��" << sizeof(arr) << endl;
	cout << "��ά�����һ�еĴ�С��" << sizeof(arr[0]) << endl;
	cout << "��ά�����һ��Ԫ�صĴ�С��" << sizeof(arr[0][1]) << endl;
	cout << "��ά����������" << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "��ά����������" << sizeof(arr[0]) / sizeof(arr[0][1]) << endl;
	cout << "---" << endl;

	// �鿴��ַ
	cout << "��ά�����׵�ַ��" << (int)arr << endl;
	cout << "��ά�����һ���׵�ַ��" << (int)arr[0] << endl;
	cout << "��ά����ڶ����׵�ַ��" << (int)arr[1] << endl;
	cout << "��ά�����һ��Ԫ���׵�ַ��" << (int)&arr[0][0] << endl;

	system("pause");
	return 0;
}