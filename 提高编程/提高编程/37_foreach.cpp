#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void print1(int val)
{
	cout << val << endl;
}

class Print_2
{
public:
	void operator()(int val)
	{
		cout << val << endl;
	}
};

void test_37()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	// 普通回调函数
	for_each(v.begin(), v.end(), print1);
	cout << "------------------------------" << endl;
	// 仿函数
	for_each(v.begin(), v.end(),Print_2());
}

int main37()
{
	test_37();

	system("pause");
	return 0;
}