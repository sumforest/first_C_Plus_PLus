#pragma once
#include <iostream>
using namespace std;
#include <string>

// Ա���ĳ�����
class Worker
{
public:
	virtual void showInfo() = 0;

	virtual string getDepName() = 0;
	
	int m_id;

	string m_name;
	
	int  m_depId;
};
