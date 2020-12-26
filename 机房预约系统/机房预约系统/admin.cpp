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

	// 初始化机房信息
	ifstream ifs(COMPUTER_ROOM_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.comId && ifs >> com.maxNum)
	{
		vCom.push_back(com);
	}
	cout << "机房个数：" << vCom.size() << endl;
}

void Admin::operatorMenu()
{
	cout << "欢迎使用管理员登录：" << this->name<< endl;
	cout << "\t\t ----------------------------------------\n";
	cout << "\t\t|                   1.添加账号           |\n";
	cout << "\t\t|                   2.查看账号           |\n";
	cout << "\t\t|                   3.查看机房信息       |\n";
	cout << "\t\t|                   4.清空预约           |\n";
	cout << "\t\t|                   0.注销登录           |\n";
	cout << "\t\t ----------------------------------------\n";
	cout << "请输入你的选择：" << endl;
}

void Admin::addAccount()
{
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;
	int select;
	int id;
	string fileName;
	string tips;
	cin >> select;
	if (select == 1)
	{
		cout << "请输入学生id：" << endl;
		fileName = STUDENT_FILE;
		tips = "你输入的学生id重复";
	}
	else
	{
		cout << "请输入职工号：" << endl;
		fileName = TEACHER_FILE;
		tips = "你输入的教师职工重复";
	}
	// 检测id是否重复
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
	cout << "请输入用户名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> password;
	
	ofstream ofs;
	ofs.open(fileName, ios::in|ios::app);
	ofs << id << " " << name << " " << password << endl;

	cout << "用户名添加完毕" << endl;
	system("pause");
	system("cls");
	ofs.close();
	// 重新初始化检查是否重复容器
	this->init();
}

void showStudentInfo(Student& stu)
{
	cout <<"学生id："<< stu.id << "\t" <<" 学生用户名："<< stu.name << "\t" <<" 密码："<< stu.password << endl;
}

void showTeaInfo(Teacher& tea)
{
	cout << "教师id：" << tea.empId << "\t" << " 教师用户名：" << tea.name << "\t" << " 密码：" << tea.password << endl;
}

void Admin::showAllAccountInfo()
{
	cout << "1.查看所有学生信息" << endl;
	cout << "2.查看所有老师信息" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		cout << "所有学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), showStudentInfo);
	}
	else
	{
		cout << "所有教师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), showTeaInfo);
	}
	system("pause");
	system("cls");
}

void Admin::showAllComputerRoomInfo()
{
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号：" << it->comId << "\t 机房最大容量：" << it->maxNum << endl;
	}
	system("pause");
	system("cls");
}

void Admin::clearAllAppointment()
{
	ofstream ofs(APPOINTMENT_FILE, ios::trunc);
	ofs.close();
	cout << "清空预约成功" << endl;
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
	cout << "学生数量：" << vStu.size() << endl;
	ifs.close();

	 ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.empId && ifs >> t.name && ifs>>t.password)
	{
		vTea.push_back(t);
	}
	cout << "教师数量：" << vTea.size() << endl;
	ifs.close();
}

bool Admin::checkRepeat(int id, int type)
{
	// 检查学生id是否重复
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