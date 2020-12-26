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
		// 调用管理员界面子菜单
		identity->operatorMenu();
		Admin* admin = (Admin*)identity;
		int select;
		cin >> select;
		switch (select)
		{
			// 添加账号
		case 1:
			cout << "添加账号" << endl;
			admin->addAccount();
			break;
			// 查看账号
		case 2:
			cout << "查看账号" << endl;
			admin->showAllAccountInfo();
			break;
			// 查看预约
		case 3:
			cout << "查看机房信息" << endl;
			admin->showAllComputerRoomInfo();
			break;
			// 清空预约
		case 4:
			cout << "清空预约" << endl;
			admin->clearAllAppointment();
			break;
			// 注销登录
		case 0:
			delete admin;
			cout << "注销成功" << endl;
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
		// 调用操作菜单
		identity->operatorMenu();

		// 向下转型
		Student* stu = (Student*)identity;

		int select;
		cin >> select;

		// 申请预约
		if (select == 1)
		{
			stu->applyAppointment();
		}
		// 查看自身预约
		else if (select == 2)
		{
			stu->showMyAppointment();
		}
		// 查看所有人预约
		else if (select == 3)
		{
			stu->showAllAppointment();
		}
		// 取消预约
		else if (select == 4)
		{
			stu->cancelAppointment();
		}
		// 注销登录
		else
		{
			delete stu;
			cout << "注销登录成功" << endl;
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

		// 查看所有预约
		if (select == 1)
		{
			tea->showAllAppointment();
		}
		// 审核预约
		else if (select == 2)
		{
			tea->auditAppointment();
		}
		// 注销登录
		else
		{
			delete tea;
			cout << "已注销登录" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
}


void login(string fileName, int type)
{
	Identity* person = NULL;

	// 读取文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		return;
	}

	int id = 0;
	string name;
	string password;

	// 学生
	if (type == 1)
	{
		cout << "请你输入学号：" << endl;
		cin >> id;
	}
	// 老师
	else if (type == 2)
	{
		cout << "请您输入职工号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> password;

	if (type == 1)
	{
		// 学生登陆验证
		int fid;
		string fname;
		string fpassword;
		while (ifs >> fid && ifs >> fname && ifs >> fpassword)
		{
			if (fid == id && fname == name && fpassword == fpassword)
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, password);
				// 进入学生子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		// 教师登录验证
		int fid;
		string fname;
		string fpassword;
		while (ifs >> fid && ifs >> fname && ifs >> fpassword)
		{
			if (fid == id && fname == name && fpassword == fpassword)
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, password);
				// 进入教师子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		// 管理员登录验证
		string fname;
		string fpassword;
		while (ifs >> fname && ifs >> fpassword)
		{
			if (fname == name && fpassword == password)
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				// 进入管理员子菜单
				person = new Admin(name,password);
				adminMenu(person);
				return;
			}
		}
	}
	cout << "你的输入有误" << endl;
	system("pause");
	system("cls");
}

int main()
{
	int select = 0;
	while (true)
	{
		cout << "====================== 欢迎使用Sumforest机房管理系统=====================" << endl;
		cout << "\t\t ----------------------------------------\n";
		cout << "\t\t|                   1.学生               |\n";
		cout << "\t\t|                   2.老师               |\n";
		cout << "\t\t|                   3.管理员             |\n";
		cout << "\t\t|                   0.退出系统           |\n";
		cout << "\t\t ----------------------------------------\n";
		cout << "请输入您的身份" << endl;

		cin >> select;
		switch (select)
		{
			// 学生登录验证
		case 1:
			login(STUDENT_FILE, 1);
			break;
			// 教师登录
		case 2:
			login(TEACHER_FILE, 2);
			break;
			// 管理员登录认证
		case 3:
			login(ADMIN_FILE, 3);
			break;
			// 退出系统
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "您输入的指令有误" << endl;
			system("pause");
			system("cls");
			break;
		}

	}

	system("pause");
	return 0;
}