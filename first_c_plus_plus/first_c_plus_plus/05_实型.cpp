#include <iostream>
using namespace std;

int main5(){
	// c++����Ч��Ĭ����ʾ6��Ч���֣�float����ʱ���ʼֵ�������f��ô��Ĭ��Ϊdouble���ͻ�ת����float������ɸ�ֵ
	float f1 = 3.1415926f;

	double d1 = 3.1415927;

	cout << "f1 = " << f1 << endl;
	cout << "d1 = " << d1 << endl;

	cout << "float������ռ�ֽڴ�С: " << sizeof(float) << endl;
	cout << "double������ռ�ֽڴ�С: " << sizeof(double) << endl;

	system("pause");

	return 0;
}