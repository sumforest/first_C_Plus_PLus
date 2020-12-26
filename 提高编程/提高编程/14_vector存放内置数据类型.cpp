#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void print(int val)
{
	cout << val << endl;
}

void test_14()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	// 遍历vector中的元素
	// 获取首尾迭代器
	vector<int>::iterator itBegin = v.begin();//起始迭代器，执行第一个元素
	vector<int>::iterator itEnd = v.end();//结束迭代器，执行最后一个元素的后一个位置

	// 1.遍历方法一
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	// 2.遍历方法二
	/*for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}*/

	// 3.遍历方法三
	for_each(v.begin(), v.end(), print);
}

int main14()
{
	test_14();

	system("pause");
	return 0;
}