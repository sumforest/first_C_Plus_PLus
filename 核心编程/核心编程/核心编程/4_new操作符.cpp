#include <iostream>
using namespace std;

// new创建整型并分配到堆区中，并释放
int*  newTest1()
{
	return 	new int(10);
}

void printInt()
{
	int* p = newTest1();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	
	// 使用Delete
	delete p;
	//cout << *p << endl;
}

void  newTest2()
{
	// 在堆区分配一个容量为十的整型数组
	int * arr = new int [10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	
	// 释放堆区上的数组
	delete[]  arr;

}

int main4()
{
	//printInt();

	newTest2();

	system("pause");
	return 0;
}