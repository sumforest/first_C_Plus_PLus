#include "employee.h"

Employee::Employee(int id, string name, int depId)
{
	m_id = id;
	m_name = name;
	m_depId = depId;
}

void Employee::showInfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\tְ����λ��" << this->getDepName()
		<< "\t��λְ��" << "��ɾ�����������" << endl;
}

string Employee::getDepName()
{
	return  string("Ա��");
}