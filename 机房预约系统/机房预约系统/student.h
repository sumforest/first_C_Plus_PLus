#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include <vector>
#include "computerRoom.h"
#include "globalFile.h"
#include <fstream>

class Student :public Identity
{
public:
	int id;

	Student();

	Student(int id,string name,string password);

	// ѧ������Ĳ����˵�
	void operatorMenu();

	// �ύ����ԤԼ
	void applyAppointment();

	// �鿴����ԤԼ
	void showAllAppointment();

	// �鿴�Լ�ԤԼ
	void showMyAppointment();

	// ȡ��ԤԼ
	void cancelAppointment();

	vector<ComputerRoom> vCom;
};
