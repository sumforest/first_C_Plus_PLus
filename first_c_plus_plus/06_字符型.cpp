#include <iostream>
using namespace std;

int main() {
	//	字符型的声明	
	char ch = 'a';
	cout << ch << endl;
	
	// 字符型大小
	cout << "字符型所占字节大小：" << sizeof(char) << endl;

	// 字符型转Ascii码
	cout << (int)ch << endl;

	system("pause");

	return 0;
}