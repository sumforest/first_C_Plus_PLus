#include <iostream>
using namespace std;
#include <vector>

void printVector_21(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test_21()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	
	printVector_21(v1);

	// ×ó±ÕÓÒ¿ª
	vector<int> v2(v1.begin(), v1.end());
	printVector_21(v2);

	vector<int> v3(10, 100);
	printVector_21(v3);

	vector<int> v4(v3);
	printVector_21(v4);
}

int main21()
{
	test_21();

	system("pause");
	return 0;
}