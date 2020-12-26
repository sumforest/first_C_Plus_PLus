#include <iostream>
using namespace std;
#include <string>

void test_17()
{
	string str;
	const char* str2 = "helloworld";
	string str3(str2);
	cout << "str3£º" << str3 << endl;
	
	string str4(str3);
	cout << "str4£º" << str4 << endl;

	string str5(5, 'a');
	cout << "str5£º" << str5 << endl;
}

int main17()
{
	test_17();

	system("pause");
	return 0;
}