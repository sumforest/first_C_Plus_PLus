#include <iostream>
using namespace std;

int main9() {
	
	bool flag = true;
	cout << flag << endl;

	flag = false;
	cout << flag << endl;
	// 布尔类型的本质：1代表真true；0代表假false

	cout << "布尔类型所占用的字节大小：" << sizeof(bool) << endl;

	system("pause");
	return 0;
}