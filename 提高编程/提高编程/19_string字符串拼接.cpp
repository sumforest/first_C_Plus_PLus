#include <iostream>
using namespace std;
#include <string>

int main19()
{
	string str1 = "ÎÒ";
	str1 += "°®Íæ";
	cout << "str1=" << str1 << endl;
	
	str1 += ':';
	cout << "str1=" << str1 << endl;
	 
	string str2 = "LOL DNF";
	str1 += str2;
	cout << "str1=" << str1 << endl;

	string str3 = "I ";
	str3.append("love");
	cout << "str3=" << str3 << endl;

	str3.append(str2, 3);
	cout << "str3=" << str3 << endl;

	str3.append(str1);
	cout << "str3=" << str3 << endl;

	str3.append(str1, 0, 2);
	cout << "str3=" << str3 << endl;

	system("pause");
	return 0;
}