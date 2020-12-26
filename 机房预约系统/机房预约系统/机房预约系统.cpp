#include <iostream>
using namespace std;
#include "identity.h"
#include <fstream>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "admin.h"

void adminMenu(Identity* &identity)
{
	while (true)
	{
		// ���ù���Ա�����Ӳ˵�
		identity->operatorMenu();
		Admin* admin = (Admin*)identity;
		int select;
		cin >> select;
		switch (select)
		{
			// ����˺�
		case 1:
			cout << "����˺�" << endl;
			admin->addAccount();
			break;
			// �鿴�˺�
		case 2:
			cout << "�鿴�˺�" << endl;
			admin->showAllAccountInfo();
			break;
			// �鿴ԤԼ
		case 3:
			cout << "�鿴������Ϣ" << endl;
			admin->showAllComputerRoomInfo();
			break;
			// ���ԤԼ
		case 4:
			cout << "���ԤԼ" << endl;
			admin->clearAllAppointment();
			break;
			// ע����¼
		case 0:
			delete admin;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void studentMenu(Identity* &identity)
{
	while (true)
	{
		// ���ò����˵�
		identity->operatorMenu();

		// ����ת��
		Student* stu = (Student*)identity;

		int select;
		cin >> select;

		// ����ԤԼ
		if (select == 1)
		{
			stu->applyAppointment();
		}
		// �鿴����ԤԼ
		else if (select == 2)
		{
			stu->showMyAppointment();
		}
		// �鿴������ԤԼ
		else if (select == 3)
		{
			stu->showAllAppointment();
		}
		// ȡ��ԤԼ
		else if (select == 4)
		{
			stu->cancelAppointment();
		}
		// ע����¼
		else
		{
			delete stu;
			cout << "ע����¼�ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

void teacherMenu(Identity* &identity)
{
	while (true)
	{
		identity->operatorMenu();

		Teacher* tea = (Teacher*)identity;
		int select;
		cin >> select;

		// �鿴����ԤԼ
		if (select == 1)
		{
			tea->showAllAppointment();
		}
		// ���ԤԼ
		else if (select == 2)
		{
			tea->auditAppointment();
		}
		// ע����¼
		else
		{
			delete tea;
			cout << "��ע����¼" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
}


void login(string fileName, int type)
{
	Identity* person = NULL;

	// ��ȡ�ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		return;
	}

	int id = 0;
	string name;
	string password;

	// ѧ��
	if (type == 1)
	{
		cout << "��������ѧ�ţ�" << endl;
		cin >> id;
	}
	// ��ʦ
	else if (type == 2)
	{
		cout << "��������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> password;

	if (type == 1)
	{
		// ѧ����½��֤
		int fid;
		string fname;
		string fpassword;
		while (ifs >> fid && ifs >> fname && ifs >> fpassword)
		{
			if (fid == id && fname == name && fpassword == fpassword)
			{
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, password);
				// ����ѧ���Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		// ��ʦ��¼��֤
		int fid;
		string fname;
		string fpassword;
		while (ifs >> fid && ifs >> fname && ifs >> fpassword)
		{
			if (fid == id && fname == name && fpassword == fpassword)
			{
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, password);
				// �����ʦ�Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		// ����Ա��¼��֤
		string fname;
		string fpassword;
		while (ifs >> fname && ifs >> fpassword)
		{
			if (fname == name && fpassword == password)
			{
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				// �������Ա�Ӳ˵�
				person = new Admin(name,password);
				adminMenu(person);
				return;
			}
		}
	}
	cout << "�����������" << endl;
	system("pause");
	system("cls");
}

int main()
{
	int select = 0;
	while (true)
	{
		cout << "====================== ��ӭʹ��Sumforest��������ϵͳ=====================" << endl;
		cout << "\t\t ----------------------------------------\n";
		cout << "\t\t|                   1.ѧ��               |\n";
		cout << "\t\t|                   2.��ʦ               |\n";
		cout << "\t\t|                   3.����Ա             |\n";
		cout << "\t\t|                   0.�˳�ϵͳ           |\n";
		cout << "\t\t ----------------------------------------\n";
		cout << "�������������" << endl;

		cin >> select;
		switch (select)
		{
			// ѧ����¼��֤
		case 1:
			login(STUDENT_FILE, 1);
			break;
			// ��ʦ��¼
		case 2:
			login(TEACHER_FILE, 2);
			break;
			// ����Ա��¼��֤
		case 3:
			login(ADMIN_FILE, 3);
			break;
			// �˳�ϵͳ
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "�������ָ������" << endl;
			system("pause");
			system("cls");
			break;
		}

	}

	system("pause");
	return 0;
}