#include <iostream>
using namespace std;

int main11() {
	
	// 取模运算，实质就是求余数
	int a1 = 10;
	int b1 = 3;
	cout <<"10 % 3 = "<< 10 % 3 << endl;
	// ①当一个整数除以另一个整数，另一个数大于这个整数，那么余数是它本身
	int a2 = 10;
	int b2 = 20;
	cout << "10 % 20 = " << 10 % 20 << endl;

	// ②两个小数是不可以做取模运算的 
	/*double a3 = 3.14;
	double b3 = 2.2;
	cout << "3.14 & 2.2 = " << a3 % b3 << endl;*/

	// ③一个小数和一个整数也不可以做取模运算，因为余数是两个整数整除产生的
	//double a4 = 3.14;
	//int b4 = 2;
	//cout << "3.14 & 2 = " << a4 % b4 << endl;

	// ④被模数不能为零，因为除数不能为0
	/*int a5 = 10;
	int b5 = 0;
	cout << "10 % 0 =" << a5 % b5 << endl;*/

	int a6 = - 10;
	int b6 = -3;
	cout << "10 % -3 = " << a6 % b6 << endl;

	system("pause");
	return 0;
}