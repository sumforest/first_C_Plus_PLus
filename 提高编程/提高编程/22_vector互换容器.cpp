#include <iostream>
using namespace std;
#include <vector>

void printVector_22(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test_22()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector_22(v1);

	vector<int> v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector_22(v2);

	v1.swap(v2);
	printVector_22(v1);
	printVector_22(v2);
}

// 利用swap()收缩内存
void test_22_2()
{
	vector<int> v1;
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);
	}
	cout << "v1 容量 = " << v1.capacity() << endl;
	cout << "v1 大小 = " << v1.size() << endl;

	// 重置v1的大小为3
	v1.resize(3);
	cout << "v1 容量 = " << v1.capacity() << endl;
	cout << "v1 大小 = " << v1.size() << endl;
	// 创建一个匿名vector函数并使用v1来初始化，并且和v1做交换
	vector<int>(v1).swap(v1);
	cout << "v1 容量 = " << v1.capacity() << endl;
	cout << "v1 大小 = " << v1.size() << endl;
}

int main22()
{
	//test_22();
	test_22_2();

	system("pause");
	return 0;
}