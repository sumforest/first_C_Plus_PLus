#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

class MyTransForm
{
public:
	int operator()(int val)
	{
		return val + 1000;
	}
};

class Print_38
{
public:
	void operator()(int val)
	{
		cout << val << endl;
	}
};

void test_38()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(),MyTransForm());
	for_each(v2.begin(), v2.end(), Print_38());
}

int main38()
{
	test_38();

	system("pause");
	return 0;
}