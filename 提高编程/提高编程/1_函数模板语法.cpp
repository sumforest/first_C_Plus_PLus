#include <iostream>
using namespace std;

// ����ģ��
template<typename T>

void exchange(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main1()
{
	int a = 10;
	int b = 20;
	// 1.�Զ������Ƶ�
	//exchange(a, b);

	// 2.��ʾָ������
	exchange<int>(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	system("pause");
	return 0;
}