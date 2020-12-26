#include "boss.h"

Boss::Boss(int id, string name, int depId)
{
	m_id = id;
	m_name = name;
	m_depId = depId;
}

void Boss::showInfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t职工岗位：" << this->getDepName()
		<< "\t岗位职责：" << "分配任务给经理" << endl;
}

string Boss::getDepName()
{
	return string("老板");
}