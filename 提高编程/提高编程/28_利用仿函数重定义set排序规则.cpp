#include <iostream>
using namespace std;
#include <set>	

class MyComparator
{
public:
	bool operator()(int a,int b)
	{
		return a > b;
	}
};

void test_28()
{
	set<int> s;
	s.insert(30);
	s.insert(50);
	s.insert(10);
	s.insert(40);
	s.insert(20);

	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	set<int, MyComparator> bigSet;
	bigSet.insert(10);
	bigSet.insert(20);
	bigSet.insert(30);
	bigSet.insert(40);
	bigSet.insert(50);
	for (set<int, MyComparator>::iterator it = bigSet.begin(); it != bigSet.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main28()
{
	test_28();

	system("pause");
	return 0;
}