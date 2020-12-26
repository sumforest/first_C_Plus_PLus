#include <iostream>
using namespace std;
#include "MyArray.hpp"

void test_13()
{
	MyArray<int> myArray1(5);
	MyArray<int> myArray2(myArray1);

	MyArray<int> myArray3(10);
	myArray1 = myArray3;
}

void print(MyArray<int>& arr)
{
		for (int i = 0; i <arr.getSize(); i++)
		{
			cout << arr[i] << endl;
		}
}

void test_13_2()
{
	MyArray<int> arr1(5);
	for (int i = 0; i < arr1.getCapacity(); i++)
	{
		arr1.push(i);
	}
	cout << "capacity: "<<arr1.getCapacity() << endl;
	cout << "size: " << arr1.getSize() << endl;
	MyArray<int> arr2(arr1);
	print(arr1);
	arr2.pop();
	cout << "执行尾删法之后：" << endl;
	print(arr2);
	cout << "capacity: " << arr2.getCapacity() << endl;
	cout << "size: " << arr2.getSize() << endl;
}

int main13()
{
	//test_13();
	test_13_2();

	system("pause");
	return 0;
}