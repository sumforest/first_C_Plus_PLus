#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	MyArray(int capacity)
	{
		//cout << "有参构造被调用" << endl;
		this->capacity = capacity;
		this->size = 0;
		this->pAddress = new T[capacity];
	}

	// 拷贝构造函数需要深拷贝来避免重复释放同一块内存区域而造成的错误
	MyArray(const MyArray &myArray)
	{
		//cout << "拷贝构造被调用" << endl;
		this->capacity = myArray.capacity;
		this->size = myArray.size;
		this->pAddress = new T[this->capacity];
		// 为新创建的数组赋值
		for (int i = 0; i < size; i++)
		{
			this->pAddress[i] = myArray.pAddress[i];
		}
	}
	
	// 重写=号操作符避免a=b时产生浅拷贝导致堆区内存重复释放
	MyArray& operator= (const MyArray& myArray)
	{
		//cout << "重写操作符被调用" << endl;
		// 存在先清空
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->capacity = 0;
			this->size = 0;
		}

		// 深拷贝
		this->capacity = myArray.capacity;
		this->size = myArray.size;
		this->pAddress = new T[this->capacity];
		for (int i = 0; i < size; i++)
		{
			this->pAddress[i] = myArray.pAddress[i];
		}
		return *this;
	}

	~MyArray()
	{
		//cout << "析构函数被调用" << endl;
		if (this->pAddress != NULL)
		{
			delete[] pAddress;
			this->pAddress = NULL;
			this->capacity = 0;
			this->size = 0;
		}
	}

	// 尾插法
	void push(T t)
	{
		if (this->size > this->capacity)
		{
			return;
		}
		this->pAddress[this->size] = t;
		this->size++;
	}

	// 重写[]号使其可以通过MyArray[]直接访问里面的数组
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	// 尾删法
	T pop()
	{
		if (this->size == 0)
		{
			return NULL;
		}
		T t =  this->pAddress[size - 1];
		this->size--;
		return t;
	}

	int getCapacity()
	{
		return this->capacity;
	}

	int getSize()
	{
		return this->size;
	}

private:
	T* pAddress;
	int capacity;
	int size;
};