#include <iostream>
using namespace std;

// new�������Ͳ����䵽�����У����ͷ�
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
	
	// ʹ��Delete
	delete p;
	//cout << *p << endl;
}

void  newTest2()
{
	// �ڶ�������һ������Ϊʮ����������
	int * arr = new int [10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	
	// �ͷŶ����ϵ�����
	delete[]  arr;

}

int main4()
{
	//printInt();

	newTest2();

	system("pause");
	return 0;
}