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
	//worker = new Employee(1, "张三", 1);
	//worker->showInfo();

	//worker = new Manager(2, "李四", 2);
	//worker->showInfo();

	//worker = new Boss(3, "大佬", 3);
	//worker->showInfo();

	WorkerManeger wm;
 
	int choice;
	while (true)
	{
		// 显示菜单
		wm.showMenu();
		cout << "请输入您的选择：" << endl;

		cin >> choice;
		switch (choice)
		{
		case 0: // 推出系统
			wm.exitSystem();
			break;
		case 1: // 增加职工
			wm.addWorkers();
			break;
		case 2: // 显示职工
			wm.showWorkerInfo();
			break;
		case 3: // 删除职工
			wm.delWorker();
			break;
		case 4: // 修改职工
			wm.modifyWorker();
			break;
		case 5: // 查找职工
			wm.findWorker();
			break;
		case 6: // 排序职工
			wm.sort();
			break;
		case 7: // 清空文档
			wm.clearData();
			break;
		default:
			// 清屏
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}