#include "manager.h"

Manager::Manager(int id, string name, int depId)
{
	m_id = id;
	m_name = name;
	m_depId = depId;
}

void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\tְ����λ��" << this->getDepName()
		<< "\t��λְ��" << "����ϰ彻���������ҷ��������Ա��" << endl;
}

string Manager::getDepName()
{
	return string("����");
}