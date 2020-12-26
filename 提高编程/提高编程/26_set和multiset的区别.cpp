#include <iostream>
using namespace std;
#include <set>

void test_26_1() 
{
	set<int> s;

    pair<set<int>::iterator,bool> res =  s.insert(10);
	if (res.second)
	{
		cout << "插入成功，插入的值：" << *(res.first) << endl;
	}
	else {
		cout << "插入失败" << endl;
	}

	res = s.insert(10);
	if (res.second)
	{
		cout << "插入成功，插入的值：" << *(res.first) << endl;
	}
	else {
		cout << "插入失败" << endl;
	}
}

void test_26_2() 
{
	multiset<int> mset;
	mset.insert(10);
	mset.insert(10);

	for (multiset<int>::iterator it = mset.begin(); it != mset.end(); it++)
	{
		cout << *it << endl;
	}
}

int main26()
{
	//test_26_1();
	test_26_2();

	system("pause");
	return 0;
}