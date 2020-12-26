#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include "appointmentFile.h"
#include <vector>

class Teacher:public Identity
{
public:
	int empId;

	Teacher();

	Teacher(int empId, string name, string password);

	void operatorMenu();

	void showAllAppointment();

	void auditAppointment();
};
