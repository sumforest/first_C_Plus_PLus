#include <iostream>
using namespace std;	
#include <vector>

void test_16()
{
	vector<vector<int>> bigV;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	// 给小容器赋值
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}

	// 给大容器添加小容器
	bigV.push_back(v1);
	bigV.push_back(v2);
	bigV.push_back(v3);
	bigV.push_back(v4);

	// 遍历
	for (vector<vector<int>>::iterator it = bigV.begin(); it != bigV.end() ; it++)
	{
		for (vector<int>::iterator sV = (*it).begin(); sV != (*it).end(); sV++)
		{
			cout << *sV << " ";
		}
		cout << endl;
	}
}

int main16()
{
	test_16();

	system("pause");
	return 0;
}