#include "boss.h"

Boss::Boss(int id, string name, int depId)
{
	m_id = id;
	m_name = name;
	m_depId = depId;
}

void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\tְ����λ��" << this->getDepName()
		<< "\t��λְ��" << "�������������" << endl;
}

string Boss::getDepName()
{
	return string("�ϰ�");
}