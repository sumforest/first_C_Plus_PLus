#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"

class Admin :public Identity
{
public:
	void init();

	vector<Student> vStu;

	vector<Teacher> vTea;

	vector<ComputerRoom> vCom;

	Admin();

	Admin(string name, string password);

	void operatorMenu();

	void addAccount();

	void showAllAccountInfo();

	void showAllComputerRoomInfo();

	void clearAllAppointment();

	// ºÏ≤Èid «∑Ò÷ÿ∏¥
	bool checkRepeat(int id, int type);
};
