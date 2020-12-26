#include "admin.h"
#include "globalFile.h"
#include <fstream>
#include <algorithm>

Admin::Admin()
{

}

Admin::Admin(string name, string password)
{
	this->name = name;
	this->password = password;
	init();

	// ��ʼ��������Ϣ
	ifstream ifs(COMPUTER_ROOM_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.comId && ifs >> com.maxNum)
	{
		vCom.push_back(com);
	}
	cout << "����������" << vCom.size() << endl;
}

void Admin::operatorMenu()
{
	cout << "��ӭʹ�ù���Ա��¼��" << this->name<< endl;
	cout << "\t\t ----------------------------------------\n";
	cout << "\t\t|                   1.����˺�           |\n";
	cout << "\t\t|                   2.�鿴�˺�           |\n";
	cout << "\t\t|                   3.�鿴������Ϣ       |\n";
	cout << "\t\t|                   4.���ԤԼ           |\n";
	cout << "\t\t|                   0.ע����¼           |\n";
	cout << "\t\t ----------------------------------------\n";
	cout << "���������ѡ��" << endl;
}

void Admin::addAccount()
{
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;
	int select;
	int id;
	string fileName;
	string tips;
	cin >> select;
	if (select == 1)
	{
		cout << "������ѧ��id��" << endl;
		fileName = STUDENT_FILE;
		tips = "�������ѧ��id�ظ�";
	}
	else
	{
		cout << "������ְ���ţ�" << endl;
		fileName = TEACHER_FILE;
		tips = "������Ľ�ʦְ���ظ�";
	}
	// ���id�Ƿ��ظ�
	while (true)
	{
		cin >> id;
		bool res = this->checkRepeat(id, select);
		if (res)
		{
			cout << tips << endl;
		}
		else 
		{
			break;
		}
	}

	string name;
	string password;
	cout << "�������û���" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> password;
	
	ofstream ofs;
	ofs.open(fileName, ios::in|ios::app);
	ofs << id << " " << name << " " << password << endl;

	cout << "�û���������" << endl;
	system("pause");
	system("cls");
	ofs.close();
	// ���³�ʼ������Ƿ��ظ�����
	this->init();
}

void showStudentInfo(Student& stu)
{
	cout <<"ѧ��id��"<< stu.id << "\t" <<" ѧ���û�����"<< stu.name << "\t" <<" ���룺"<< stu.password << endl;
}

void showTeaInfo(Teacher& tea)
{
	cout << "��ʦid��" << tea.empId << "\t" << " ��ʦ�û�����" << tea.name << "\t" << " ���룺" << tea.password << endl;
}

void Admin::showAllAccountInfo()
{
	cout << "1.�鿴����ѧ����Ϣ" << endl;
	cout << "2.�鿴������ʦ��Ϣ" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), showStudentInfo);
	}
	else
	{
		cout << "���н�ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), showTeaInfo);
	}
	system("pause");
	system("cls");
}

void Admin::showAllComputerRoomInfo()
{
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ�" << it->comId << "\t �������������" << it->maxNum << endl;
	}
	system("pause");
	system("cls");
}

void Admin::clearAllAppointment()
{
	ofstream ofs(APPOINTMENT_FILE, ios::trunc);
	ofs.close();
	cout << "���ԤԼ�ɹ�" << endl;
	system("pause");
	system("cls");
}

void Admin::init()
{
	vStu.clear();
	vTea.clear();

	ifstream ifs(STUDENT_FILE, ios::in);
	Student s;
	while (ifs >> s.id &&  ifs >> s.name && ifs >> s.password)
	{
		vStu.push_back(s);
	}
	cout << "ѧ��������" << vStu.size() << endl;
	ifs.close();

	 ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.empId && ifs >> t.name && ifs>>t.password)
	{
		vTea.push_back(t);
	}
	cout << "��ʦ������" << vTea.size() << endl;
	ifs.close();
}

bool Admin::checkRepeat(int id, int type)
{
	// ���ѧ��id�Ƿ��ظ�
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (it->id == id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (it->empId == id)
			{
				return true;
			}
		}
	}
}