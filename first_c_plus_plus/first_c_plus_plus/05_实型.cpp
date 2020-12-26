#include <iostream>
using namespace std;

int main5(){
	// c++里面效数默认显示6有效数字，float声明时其初始值如果不加f那么会默认为double类型会转换成float类型完成赋值
	float f1 = 3.1415926f;

	double d1 = 3.1415927;

	cout << "f1 = " << f1 << endl;
	cout << "d1 = " << d1 << endl;

	cout << "float类型所占字节大小: " << sizeof(float) << endl;
	cout << "double类型所占字节大小: " << sizeof(double) << endl;

	system("pause");

	return 0;
}