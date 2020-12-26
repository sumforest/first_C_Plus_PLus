#include "manager.h"

Manager::Manager(int id, string name, int depId)
{
	m_id = id;
	m_name = name;
	m_depId = depId;
}

void Manager::showInfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t职工岗位：" << this->getDepName()
		<< "\t岗位职责：" << "完成老板交给的任务并且分配任务给员工" << endl;
}

string Manager::getDepName()
{
	return string("经理");
}