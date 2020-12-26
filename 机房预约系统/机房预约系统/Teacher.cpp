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
	cout << "欢迎使用教师登录：" << this->name << endl;
	cout << "\t\t ----------------------------------------\n";
	cout << "\t\t|                   1.查看所有人预约     |\n";
	cout << "\t\t|                   2.审核预约           |\n";
	cout << "\t\t|                   0.注销登录           |\n";
	cout << "\t\t ----------------------------------------\n";
	cout << "请输入你的选择：" << endl;

}

void Teacher::showAllAppointment()
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

void Teacher::auditAppointment()
{
	AppointmentFile app;
	if (app.size == 0)
	{
		cout << "数据为空！" << endl;
	}
	else
	{
		cout << "只有状态为待审核的预约才可以审核" << endl;
		cout << "待审核的预约如下：" << endl;

		int index = 0;
		vector<int> v;

		for (int i = 0; i < app.size; i++)
		{
			if (app.m_map[i]["state"] == "1")
			{
				index++;
				v.push_back(i);

				cout << index << "、";
				cout << "预约日期：周" << app.m_map[i]["date"] << " ";
				cout << (app.m_map[i]["interval"] == "1" ? "上午" : "下午") << " ";
				cout << "学号：" << app.m_map[i]["stuId	"] << " ";
				cout << "姓名：" << app.m_map[i]["name"] << " ";
				cout << "机房号：" << app.m_map[i]["computerRoomNo"] << " ";
				cout << "状态：待审核" << endl;
			}
		}

		cout << "选择要审核的预约，0返回：" << endl;
		int select;
		int ret;

		while (true)
		{
			cin >> select;

			if (select>=0 && select <= app.size)
			{
				if (select == 0)
				{
					cout << "已返回" << endl;
					break;
				}
				cout << "1.通过审核" << endl;
				cout << "2.不通过审核" << endl;
				cin >> ret;
				if (ret == 1)
				{
					app.m_map[v[select - 1]]["state"] = "2";
				}
				else 
				{
					app.m_map[v[select - 1]]["state"] = "-1";
				}
				cout << "审核完成" << endl;
				app.update();
				break;
			}
			cout << "您的输入有误，请重新输入" << endl;
		}
	}
	system("pause");
	system("cls");
}