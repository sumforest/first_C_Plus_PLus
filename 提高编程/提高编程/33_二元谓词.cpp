#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class MyCompartor_33
{
public:
	bool operator()(int val1, int val2)
	{
		return val1 > val2;
	}
};

void test_33()
{
	vector<int> v;
	v.push_back(30);
	v.push_back(10);
	v.push_back(40);
	v.push_back(50);
	v.push_back(20);

	sort(v.begin(), v.end());
	
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	sort(v.begin(), v.end(), MyCompartor_33());
	
	cout << "-----------------------------------" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main33()
{
	test_33();
	system("pause");
	return 0;
}