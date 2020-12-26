#include "teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int empId, string name, string password)
{
	this->empId = empId;
	this->name = name;
	this->password = password;
}

void Teacher::operatorMenu()
{
	cout << "��ӭʹ�ý�ʦ��¼��" << this->name << endl;
	cout << "\t\t ----------------------------------------\n";
	cout << "\t\t|                   1.�鿴������ԤԼ     |\n";
	cout << "\t\t|                   2.���ԤԼ           |\n";
	cout << "\t\t|                   0.ע����¼           |\n";
	cout << "\t\t ----------------------------------------\n";
	cout << "���������ѡ��" << endl;

}

void Teacher::showAllAppointment()
{
	AppointmentFile app;
	if (app.size == 0)
	{
		cout << "ԤԼ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < app.size; i++)
		{
			cout << i + 1 << "��";
			cout << "ԤԼʱ�䣺��" << app.m_map[i]["date"] << " ";
			cout << (app.m_map[i]["interval"] == "1" ? "����" : "����") << " ";
			cout << "ѧ�ţ�" << app.m_map[i]["stuId"] << " ";
			cout << "������" << app.m_map[i]["name"] << " ";
			cout << "�����ţ�" << app.m_map[i]["computerRoomNo"] << " ";
			string state = "״̬��";
			if (app.m_map[i]["state"] == "1")
			{
				state += "�����";
			}
			else if (app.m_map[i]["state"] == "2")
			{
				state += "�����";
			}
			else if (app.m_map[i]["state"] == "-1")
			{
				state += "ԤԼʧ��";
			}
			else if (app.m_map[i]["state"] == "0")
			{
				state += "ȡ����ԤԼ";
			}
			cout << state << endl;
		}
	}
	system("pause");
	system("cls");
}

void Teacher::auditAppointment()
{
	AppointmentFile app;
	if (app.size == 0)
	{
		cout << "����Ϊ�գ�" << endl;
	}
	else
	{
		cout << "ֻ��״̬Ϊ����˵�ԤԼ�ſ������" << endl;
		cout << "����˵�ԤԼ���£�" << endl;

		int index = 0;
		vector<int> v;

		for (int i = 0; i < app.size; i++)
		{
			if (app.m_map[i]["state"] == "1")
			{
				index++;
				v.push_back(i);

				cout << index << "��";
				cout << "ԤԼ���ڣ���" << app.m_map[i]["date"] << " ";
				cout << (app.m_map[i]["interval"] == "1" ? "����" : "����") << " ";
				cout << "ѧ�ţ�" << app.m_map[i]["stuId	"] << " ";
				cout << "������" << app.m_map[i]["name"] << " ";
				cout << "�����ţ�" << app.m_map[i]["computerRoomNo"] << " ";
				cout << "״̬�������" << endl;
			}
		}

		cout << "ѡ��Ҫ��˵�ԤԼ��0���أ�" << endl;
		int select;
		int ret;

		while (true)
		{
			cin >> select;

			if (select>=0 && select <= app.size)
			{
				if (select == 0)
				{
					cout << "�ѷ���" << endl;
					break;
				}
				cout << "1.ͨ�����" << endl;
				cout << "2.��ͨ�����" << endl;
				cin >> ret;
				if (ret == 1)
				{
					app.m_map[v[select - 1]]["state"] = "2";
				}
				else 
				{
					app.m_map[v[select - 1]]["state"] = "-1";
				}
				cout << "������" << endl;
				app.update();
				break;
			}
			cout << "����������������������" << endl;
		}
	}
	system("pause");
	system("cls");
}