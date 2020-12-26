#include <iostream>
using namespace std;
#include "speechManager.h"
#include <string>
#include <ctime>

int main()
{
	// 随机数种子
	srand((unsigned int)time(NULL));

	SpeechManager sm;

	/*for (map<int, Speaker>::iterator it = sm.m.begin(); it != sm.m.end(); it++)
	{
		cout << "选手编号：" << it->first << "；选手姓名：" << it->second.name << "；分数：" << it->second.socre[0] << endl;
	}*/

	int choice;
	while (true)
	{
		sm.showMenu();
		cout << "请输入您的选择：" << endl;

		cin >> choice;

		switch (choice)
		{
		// 开始比赛	
		case 1:
			sm.startSpeech();
			break;
		// 查看往届记录
		case 2:
			sm.showRecord();
			break;
		// 清空往届记录
		case 3:
			sm.clearRecord();
			break;
		// 退出系统
		case 0:
			sm.exitSys();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}