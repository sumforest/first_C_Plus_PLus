#include <iostream>
using namespace std;

int main12() {
	// ���������
	int a = 10;
	// ǰ��++
	++a;
	cout << a << endl;

	//����++
	int b = 10;
	b++;
	cout << b << endl;

	// ǰ��++���Ƚ��е����������ټ�����ʽ
	int a1 = 10;
	int b1 = ++a1 * 10;
	cout << "a1 = " << a1 << endl; // 11
	cout << "b1 = " << b1 << endl; // 110

	// ����++���ȼ�����ʽ���ٽ��е�������
	int a2 = 10;
	int b2 = a2++ * 10;
	cout << "a2 = " << a2 << endl; // 11
	cout << "b2 = " << b2 << endl; // 100 

	system("pause");
	return 0;
}