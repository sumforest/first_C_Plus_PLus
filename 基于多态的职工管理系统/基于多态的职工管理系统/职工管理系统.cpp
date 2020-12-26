#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main()
{ 
	//Worker *worker = NULL;
	//worker = new Employee(1, "����", 1);
	//worker->showInfo();

	//worker = new Manager(2, "����", 2);
	//worker->showInfo();

	//worker = new Boss(3, "����", 3);
	//worker->showInfo();

	WorkerManeger wm;
 
	int choice;
	while (true)
	{
		// ��ʾ�˵�
		wm.showMenu();
		cout << "����������ѡ��" << endl;

		cin >> choice;
		switch (choice)
		{
		case 0: // �Ƴ�ϵͳ
			wm.exitSystem();
			break;
		case 1: // ����ְ��
			wm.addWorkers();
			break;
		case 2: // ��ʾְ��
			wm.showWorkerInfo();
			break;
		case 3: // ɾ��ְ��
			wm.delWorker();
			break;
		case 4: // �޸�ְ��
			wm.modifyWorker();
			break;
		case 5: // ����ְ��
			wm.findWorker();
			break;
		case 6: // ����ְ��
			wm.sort();
			break;
		case 7: // ����ĵ�
			wm.clearData();
			break;
		default:
			// ����
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}