#include "student.h"
#include "appointmentFile.h"

Student::Student()
{

}

Student::Student(int id, string name, string password)
{
	this->id = id;
	this->name = name;
	this->password = password;

	// ��ʼ��������Ϣ
	ifstream ifs(COMPUTER_ROOM_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.comId && ifs >> com.maxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

void Student::operatorMenu()
{
	cout << "��ӭʹ�ù���Ա��¼��" << this->name << endl;
	cout << "\t\t ----------------------------------------\n";
	cout << "\t\t|                   1.����ԤԼ           |\n";
	cout << "\t\t|                   2.�鿴����ԤԼ       |\n";
	cout << "\t\t|                   3.�鿴������ԤԼ     |\n";
	cout << "\t\t|                   4.ȡ��ԤԼ           |\n";
	cout << "\t\t|                   0.ע����¼           |\n";
	cout << "\t\t ----------------------------------------\n";
	cout << "���������ѡ��" << endl;
}

void Student::applyAppointment()
{
	cout << "����ֻ����һ�����忪�ţ�" << endl;
	cout << "��ѡ���������ʱ��" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;

	int date;
	int interval;
	int computerRoomNo;
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		else
		{
			cout << "����������������������!" << endl;
		}
	}

	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "����������������������!" << endl;
	}

	cout << "��ѡ�����" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].comId << "�Ż��������������" << vCom[i].maxNum << endl;
	}
	while (true)
	{
		cin >> computerRoomNo;
		if (computerRoomNo >= 1 && computerRoomNo <= 3)
		{
			break;
		}
		cout << "����������������������!" << endl;
	}

	ofstream ofs(APPOINTMENT_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->id << " ";
	ofs << "name:" << this->name << " ";
	ofs << "computerRoomNo:" << computerRoomNo << " ";
	ofs << "state:" << 1 << endl << " ";
	ofs.close();
	cout << "ԤԼ����ɹ�" << endl;
	system("pause");
	system("cls");
}

void Student::showAllAppointment()
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

void Student::showMyAppointment()
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
			if (atoi(app.m_map[i]["stuId"].c_str()) == this->id)
			{
				cout << "ԤԼʱ�䣺��" << app.m_map[i]["date"] << " ";
				cout << (app.m_map[i]["interval"] == "1" ? "����" : "����") << " ";
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
	}
	system("pause");
	system("cls");
}

void Student::cancelAppointment()
{
	AppointmentFile app;

	cout << "ֻ֧���޸�״̬Ϊ������� / ����� ��ԤԼ	" << endl;

	if (app.size == 0)
	{
		cout << "ԤԼ��¼Ϊ��" << endl;
	}
	else
	{
		int index = 1;
		vector<int> v;

		for (int i = 0; i < app.size; i++)
		{
			// ���˼�¼
			if (this->id == atoi(app.m_map[i]["stuId"].c_str()))
			{
				// ״̬�Ǵ����/�����
				if (app.m_map[i]["state"] == "1" || app.m_map[i]["state"] == "1")
				{
					// ���汾�˼�¼��m_map�е�keyֵ
					v.push_back(i);
					cout << index << "��";
					index++;
					cout << "ԤԼʱ�䣺 ��" << app.m_map[i]["date"] << " ";
					cout << (app.m_map[i]["interval"] == "1" ? "����" : "����") << " ";
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
					cout << state << endl;
				}
			}
		}

		cout << "��ѡ��Ҫɾ����ԤԼ��0����" << endl;
		int select;

		while (true)
		{
			cin >> select;

			if (select>=0 && select <= v.size())
			{
				if (select == 0)
				{
					break;
				}
				else
				{
					app.m_map[v[select - 1]]["state"] = "0";
					app.update();
					cout << "ԤԼ��ȡ��" << endl;
					break;
				}
			}
			cout << "����������������������";
		}
	}

	system("pause");
	system("cls");
}