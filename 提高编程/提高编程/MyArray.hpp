#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	MyArray(int capacity)
	{
		//cout << "�вι��챻����" << endl;
		this->capacity = capacity;
		this->size = 0;
		this->pAddress = new T[capacity];
	}

	// �������캯����Ҫ����������ظ��ͷ�ͬһ���ڴ��������ɵĴ���
	MyArray(const MyArray &myArray)
	{
		//cout << "�������챻����" << endl;
		this->capacity = myArray.capacity;
		this->size = myArray.size;
		this->pAddress = new T[this->capacity];
		// Ϊ�´��������鸳ֵ
		for (int i = 0; i < size; i++)
		{
			this->pAddress[i] = myArray.pAddress[i];
		}
	}
	
	// ��д=�Ų���������a=bʱ����ǳ�������¶����ڴ��ظ��ͷ�
	MyArray& operator= (const MyArray& myArray)
	{
		//cout << "��д������������" << endl;
		// ���������
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->capacity = 0;
			this->size = 0;
		}

		// ���
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
		//cout << "��������������" << endl;
		if (this->pAddress != NULL)
		{
			delete[] pAddress;
			this->pAddress = NULL;
			this->capacity = 0;
			this->size = 0;
		}
	}

	// β�巨
	void push(T t)
	{
		if (this->size > this->capacity)
		{
			return;
		}
		this->pAddress[this->size] = t;
		this->size++;
	}

	// ��д[]��ʹ�����ͨ��MyArray[]ֱ�ӷ������������
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	// βɾ��
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