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

	// 学生界面的操作菜单
	void operatorMenu();

	// 提交申请预约
	void applyAppointment();

	// 查看所有预约
	void showAllAppointment();

	// 查看自己预约
	void showMyAppointment();

	// 取消预约
	void cancelAppointment();

	vector<ComputerRoom> vCom;
};
