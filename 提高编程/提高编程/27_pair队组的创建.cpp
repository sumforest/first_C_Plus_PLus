#include <iostream>
using namespace std;
#include <string>

void test_27()
{
	pair<string, int> p("Tom", 21);
	cout << p.first << " " << p.second << endl;

	pair<string, int> p2 = make_pair("Jenny", 23);
	cout << p2.first << " " << p2.second << endl;
}

int main27()
{
	test_27();

	system("pause");
	return 0;
}