#include <iostream>
using namespace std;

int main7() {
	// ת���ַ������ã����ڱ�ʾASCII�޷���ʾ���ַ�
	// 1.�� \n�� ����ת���ַ�
	cout << "hello world\n";

	// 2. ��б�ܡ� \\�� ת���ַ�
	cout << "\\\n";

	// 3. ˮƽ�Ʊ�� ��\t��ռ��8���ַ�
	cout << "aaaa\thello world" << endl;
	cout << "aaaaaaa\thello world" << endl;
	cout << "aaaa\thello world" << endl;
	
	system("pause");

	return 0;
}