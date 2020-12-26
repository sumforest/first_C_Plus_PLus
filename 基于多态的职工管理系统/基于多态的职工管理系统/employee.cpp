#include "employee.h"

Employee::Employee(int id, string name, int depId)
{
	m_id = id;
	m_name = name;
	m_depId = depId;
}

void Employee::showInfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t职工岗位：" << this->getDepName()
		<< "\t岗位职责：" << "完成经理交给的任务" << endl;
}

string Employee::getDepName()
{
	return  string("员工");
}