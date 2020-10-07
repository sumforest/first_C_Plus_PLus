#include <iostream>
using namespace std;

int main7() {
	// 转义字符的作用：用于表示ASCII无法表示的字符
	// 1.“ \n” 换行转义字符
	cout << "hello world\n";

	// 2. 反斜杠“ \\” 转义字符
	cout << "\\\n";

	// 3. 水平制表符 “\t”占用8个字符
	cout << "aaaa\thello world" << endl;
	cout << "aaaaaaa\thello world" << endl;
	cout << "aaaa\thello world" << endl;
	
	system("pause");

	return 0;
}