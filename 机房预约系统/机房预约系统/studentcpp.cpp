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

	// 初始化机房信息
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
	cout << "欢迎使用管理员登录：" << this->name << endl;
	cout << "\t\t ----------------------------------------\n";
	cout << "\t\t|                   1.申请预约           |\n";
	cout << "\t\t|                   2.查看自身预约       |\n";
	cout << "\t\t|                   3.查看所有人预约     |\n";
	cout << "\t\t|                   4.取消预约           |\n";
	cout << "\t\t|                   0.注销登录           |\n";
	cout << "\t\t ----------------------------------------\n";
	cout << "请输入你的选择：" << endl;
}

void Student::applyAppointment()
{
	cout << "机房只在周一至周五开放！" << endl;
	cout << "请选择你的输入时间" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;

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
			cout << "您的输入有误，请重新输入!" << endl;
		}
	}

	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "您的输入有误，请重新输入!" << endl;
	}

	cout << "请选择机房" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].comId << "号机房，最大容量：" << vCom[i].maxNum << endl;
	}
	while (true)
	{
		cin >> computerRoomNo;
		if (computerRoomNo >= 1 && computerRoomNo <= 3)
		{
			break;
		}
		cout << "您的输入有误，请重新输入!" << endl;
	}

	ofstream ofs(APPOINTMENT_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->id << " ";
	ofs << "name:" << this->name << " ";
	ofs << "computerRoomNo:" << computerRoomNo << " ";
	ofs << "state:" << 1 << endl << " ";
	ofs.close();
	cout << "预约申请成功" << endl;
	system("pause");
	system("cls");
}

void Student::showAllAppointment()
{
	AppointmentFile app;
	if (app.size == 0)
	{
		cout << "预约记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < app.size; i++)
		{
			cout << i + 1 << "、";
			cout << "预约时间：周" << app.m_map[i]["date"] << " ";
			cout << (app.m_map[i]["interval"] == "1" ? "上午" : "下午") << " ";
			cout << "学号：" << app.m_map[i]["stuId"] << " ";
			cout << "姓名：" << app.m_map[i]["name"] << " ";
			cout << "机房号：" << app.m_map[i]["computerRoomNo"] << " ";
			string state = "状态：";
			if (app.m_map[i]["state"] == "1")
			{
				state += "待审核";
			}
			else if (app.m_map[i]["state"] == "2")
			{
				state += "已审核";
			}
			else if (app.m_map[i]["state"] == "-1")
			{
				state += "预约失败";
			}
			else if (app.m_map[i]["state"] == "0")
			{
				state += "取消的预约";
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
		cout << "预约记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < app.size; i++)
		{
			if (atoi(app.m_map[i]["stuId"].c_str()) == this->id)
			{
				cout << "预约时间：周" << app.m_map[i]["date"] << " ";
				cout << (app.m_map[i]["interval"] == "1" ? "上午" : "下午") << " ";
				cout << "机房号：" << app.m_map[i]["computerRoomNo"] << " ";
				string state = "状态：";
				if (app.m_map[i]["state"] == "1")
				{
					state += "待审核";
				}
				else if (app.m_map[i]["state"] == "2")
				{
					state += "已审核";
				}
				else if (app.m_map[i]["state"] == "-1")
				{
					state += "预约失败";
				}
				else if (app.m_map[i]["state"] == "0")
				{
					state += "取消的预约";
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

	cout << "只支持修改状态为：待审核 / 已审核 的预约	" << endl;

	if (app.size == 0)
	{
		cout << "预约记录为空" << endl;
	}
	else
	{
		int index = 1;
		vector<int> v;

		for (int i = 0; i < app.size; i++)
		{
			// 本人记录
			if (this->id == atoi(app.m_map[i]["stuId"].c_str()))
			{
				// 状态是待审核/已审核
				if (app.m_map[i]["state"] == "1" || app.m_map[i]["state"] == "1")
				{
					// 保存本人记录再m_map中的key值
					v.push_back(i);
					cout << index << "、";
					index++;
					cout << "预约时间： 周" << app.m_map[i]["date"] << " ";
					cout << (app.m_map[i]["interval"] == "1" ? "上午" : "下午") << " ";
					cout << "机房号：" << app.m_map[i]["computerRoomNo"] << " ";
					string state = "状态：";
					if (app.m_map[i]["state"] == "1")
					{
						state += "待审核";
					}
					else if (app.m_map[i]["state"] == "2")
					{
						state += "已审核";
					}
					cout << state << endl;
				}
			}
		}

		cout << "请选择要删除的预约，0返回" << endl;
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
					cout << "预约已取消" << endl;
					break;
				}
			}
			cout << "您的输入有误，请重新输入";
		}
	}

	system("pause");
	system("cls");
}