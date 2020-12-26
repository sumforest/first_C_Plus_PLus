#include <iostream>
using namespace std;
#include <vector>

void test_23()
{
	vector<int> v;
	v.reserve(10000);
	int count = 0;
	int* p = NULL;
	for (int i = 0; i < 10000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			count++;
		}
	}
	cout << "一共交换了：" << count << endl;
}

int main23()
{
	test_23();

	system("pause");
	return 0;
}