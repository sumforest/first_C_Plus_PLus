#include <iostream>
using namespace std;
#include "speechManager.h"
#include <string>
#include <ctime>

int main()
{
	// ���������
	srand((unsigned int)time(NULL));

	SpeechManager sm;

	/*for (map<int, Speaker>::iterator it = sm.m.begin(); it != sm.m.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << it->first << "��ѡ��������" << it->second.name << "��������" << it->second.socre[0] << endl;
	}*/

	int choice;
	while (true)
	{
		sm.showMenu();
		cout << "����������ѡ��" << endl;

		cin >> choice;

		switch (choice)
		{
		// ��ʼ����	
		case 1:
			sm.startSpeech();
			break;
		// �鿴�����¼
		case 2:
			sm.showRecord();
			break;
		// ��������¼
		case 3:
			sm.clearRecord();
			break;
		// �˳�ϵͳ
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