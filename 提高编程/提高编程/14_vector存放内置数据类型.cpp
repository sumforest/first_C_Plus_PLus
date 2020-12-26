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

	// ����vector�е�Ԫ��
	// ��ȡ��β������
	vector<int>::iterator itBegin = v.begin();//��ʼ��������ִ�е�һ��Ԫ��
	vector<int>::iterator itEnd = v.end();//������������ִ�����һ��Ԫ�صĺ�һ��λ��

	// 1.��������һ
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	// 2.����������
	/*for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}*/

	// 3.����������
	for_each(v.begin(), v.end(), print);
}

int main14()
{
	test_14();

	system("pause");
	return 0;
}