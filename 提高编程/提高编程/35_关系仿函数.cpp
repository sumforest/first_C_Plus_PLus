#include <iostream>
using namespace std;
#include <vector>
#include <functional>
#include <algorithm>

void test_35()
{
	vector<int> v;
	v.push_back(30);
	v.push_back(10);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	sort(v.begin(), v.end(), greater<int>());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main35()
{
	test_35();

	system("pause");
	return 0;
}