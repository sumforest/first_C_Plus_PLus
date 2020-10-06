#include <iostream>
using namespace std;
int main4() 
{
	// short(2) int(4) long(4/8) long long(8)；其中Linux中32位long大小为4个字节，64位中long大小位8个字节
	// short < int <= long < long long
	short num1 = 10;
	int num2 = 10;
	long num3 = 10;
	long long num4 = 10;

	cout << "short所占字节大小：" << sizeof(num1) << endl;
	cout << "int所占字节大小：" << sizeof(num2) << endl;
	cout << "long所占字节大小：" << sizeof(num3) << endl;
	cout << "long long所占字节大小：" << sizeof(num4) << endl;

	system("pause");

	return 0;
}