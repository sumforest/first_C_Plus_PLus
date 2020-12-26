#include "workerManager.h"

// 构造函数
WorkerManeger::WorkerManeger()
{
	// 1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		// 初始化指针
		this->workers = NULL;
		this->workerNum = 0;
		// 把文件不存在标记改为true
		this->isEmpty = true;
		// 关闭文件流
		ifs.close();
		return;
	}
	// 2.文件存在数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->workers = NULL;
		this->workerNum = 0;
		this->isEmpty = true;
		ifs.close();
		return;
	}

	// 3.文件不为空并且有数据
	int empleeNum = this->getEmpleeNums();
	//cout << "现有职工：" << empleeNum << endl;
	this->workerNum = empleeNum;
	this->isEmpty = false;
	
	// 初始化空间
	this->workers = new Worker*[this->workerNum];
	// 初始化数据
	this->init();

	//for (int i = 0; i < empleeNum; i++)
	//{
	//	cout << "id = " << this->workers[i]->m_id
	//		<< " name = " << this->workers[i]->m_name
	//		<< " depId = " << this->workers[i]->m_depId << endl;
	//}
}

// 析构函数
WorkerManeger::~WorkerManeger()
{
	if (this->workers != NULL)
	{
		for (int i = 0; i < this->workerNum; i++)
		{
			if (this->workers[i] != NULL)
			{
				delete this->workers[i];
				this->workers[i] = NULL;
			}
		}
		delete[] this->workers;
		this->workers = NULL;
	}
}

void WorkerManeger::showMenu() 
{
	cout << "********************************************************************" << endl;
	cout << "****************      欢迎使用职工管理系统！    ********************" << endl;
	cout << "*******************      0.推出管理程序      ***********************" << endl;
	cout << "*******************      1.增加职工信息      ***********************" << endl;
	cout << "*******************      2.显示职工信息      ***********************" << endl;
	cout << "*******************      3.删除职工信息      ***********************" << endl;
	cout << "*******************      4.修改职工信息      ***********************" << endl;
	cout << "*******************      5.查找职工信息      ***********************" << endl;
	cout << "*******************      6.按照编号排序      ***********************" << endl;
	cout << "*******************      7.清空所有文档      ***********************" << endl;
	cout << endl;
}

void  WorkerManeger::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManeger::addWorkers()
{
	// 创建一个指针数组（二级指针）
	Worker** newspace = NULL;
	cout << "请输入要添加的员工个数：" << endl;
	int inputNum = 0;
	cin >> inputNum;
	if (inputNum > 0)
	{
		// 初始化新指针数组
		newspace = new Worker*[this->workerNum + inputNum];
		// 当前员工个数不为空，把原来的员工存进新的指针数组里面
			if (this->workerNum != NULL)
			{
				for (int i = 0; i < this->workerNum; i++)
				{
					newspace[i] = this->workers[i];
				}
			}

			for (int i = 0; i < inputNum; i++)
			{
				int id;
				string name;
				int depId;

				cout << "请输入 " << i + 1 << "个员工的编号" << endl;
				cin >> id;

				cout << "请输入 " << i + 1 << "个员工的姓名" << endl;
				cin >> name;

				cout << "请输入 " << i + 1 << "个员工的部门编号" << endl;
				cout << "1-普通员工" << endl;
				cout << "2-部门经理" << endl;
				cout << "3-老板" << endl;
				cin >> depId;

				Worker* worker = NULL;

				switch (depId)
				{
				case 1:
					worker = new Employee(id, name, depId);
					break;
				case 2:
					worker = new Manager(id, name, depId);
					break;
				case 3:
					worker = new Boss(id, name, depId);
					break;
				default:
					break;
				}
				// 添加新职工到新的指针数组中
				newspace[workerNum + i] = worker;
				// 释放原来的指针数组内存
				delete[] this->workers;
				// 跟新耳机指针指向
				workers = newspace;
				// 更新职工总人数
				this->workerNum = this->workerNum + inputNum;
			}
		cout << "添加成功" << inputNum << "名员工" << endl;
		this->save();
		// 添加职工成功后把文件是否为空标记改成false
		this->isEmpty = false;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "您的输入有误！" << endl;
	}
}

void WorkerManeger::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->workerNum; i++)
	{
		ofs << this->workers[i]->m_id << " "
			<< this->workers[i]->m_name << " "
			<< this->workers[i]->m_depId << " " << endl;;
	}

	ofs.close();
}

int WorkerManeger::getEmpleeNums()
{
	int count = 0;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	// 存储数据的缓冲区
	int id;
	string name;
	int depId;
	
	// >>读取遇到空格返回，并且跳过空格
	while (ifs >> id && ifs >> name && ifs >> depId)
	{
		count++;
	}
	return count;
}

void WorkerManeger::init()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int depId;

	int index = 0;
	// 读取一行数据
	while (ifs >> id && ifs >> name && ifs >> depId)
	{
		// 使用数据创建具体的职工类
		Worker* worker = NULL;
		if (depId == 1)
		{
			worker = new Employee(id, name, depId);
		}
		else if (depId == 2)
		{
			worker = new Manager(id, name, depId);
		}
		else
		{
			worker = new Boss(id, name, depId);
		}

		// 添加到指针数据里面
		this->workers[index] = worker;
		index++;
	}

	// 关闭文件输入流
	ifs.close();
}

void WorkerManeger::showWorkerInfo()
{
	if (this->isEmpty == true)
	{
		cout << "文件不存在或者文件为空！" << endl;
		return;
	}
	for (int i = 0; i < this->workerNum; i++)
	{
		this->workers[i]->showInfo();
	}

	system("pause");
	system("cls");
}

int WorkerManeger::findIndex(int id)
{
	int index = -1;
	for (int i = 0; i < this->workerNum; i++)
	{
		if (this->workers[i]->m_id == id)
		{
			return i;
		}
	}
	return index;
}

void WorkerManeger::delWorker()
{
	if (this->isEmpty)
	{
		cout << "数据为空，删除失败" << endl;
	}
	else
	{
		int id;
		cout << "请输入职工编号：" << endl;
		cin >> id;
		int res = this->findIndex(id);
		if (res == -1)
		{
			cout << "删除失败，查无此人" << endl;
		}
		else
		{
			// workerNum - 1当删除元素为最后一个时，数组不移动
			for (int i = res; i < this->workerNum - 1; i++)
			{
				this->workers[i] = this->workers[i + 1];
			}
			this->workerNum--;
			// 刷新文件数据
			this->save();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManeger::modifyWorker()
{
	if (this->isEmpty)
	{
		cout << "当前文件为空，修改失败" << endl;
	}
	else
	{
		cout << "请输入您要修改员工的编号：" << endl;
		int workerNo;
		cin >> workerNo;
		int res = this->findIndex(workerNo);
		if (res != -1)
		{
			cout << "查找到的员工信息：" << endl;
			this->workers[res]->showInfo();

			int id = 0;
			string name = "";
			int depId = 0;

			cout << "请输入新的编号：" << endl;
			cin >> id;
			cout << "请输入新的姓名：" << endl;
			cin >> name;
			cout << "请输入新的部门编号：" << endl;
			cin >> depId;

			Worker *worker = NULL;
			switch (depId)
			{
			case 1:
				worker = new Employee(id, name, depId);
				break;
			case 2:
				worker = new Manager(id, name, depId);
				break;
			case 3:
				worker = new Boss(id, name, depId);
				break;
			default:
				break;
			}
			// 保存修改后的对象
			this->workers[res] = worker;
			this->save();
		}
		else
		{
			cout << "查无此人，修改失败!" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManeger::findWorker()
{
	if (this->isEmpty)
	{
		cout << "查找失败，文件为空" << endl;
	}
	else
	{
		cout << "请选择查找方式：" << endl;
		cout << "1.按编号查找" << endl;
		cout << "2.按姓名查找" << endl;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << "请输入要查找的员工编号：" << endl;
			int fId;
			cin >> fId;
			int res = this->findIndex(fId);
			if (res != -1)
			{
				this->workers[res]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "请输入要查找的员工的姓名：" << endl;
			string fname;
			cin >> fname;
			
			bool isFinded = false;
			for (int i = 0; i < this->workerNum; i++)
			{
				if (fname == this->workers[i]->m_name)
				{
					this->workers[i]->showInfo();
					isFinded = true;
				}
			}
			if (!isFinded)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

void WorkerManeger::sort()
{
	if (this->isEmpty)
	{
		cout << "排序失败，文件不存在" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序的方式" << endl;
		cout << "1.升序" << endl;
		cout << "2.降序" << endl;
		int sortModel;
		cin >> sortModel;

		// 选择排序
		for (int i = 0; i < this->workerNum; i++)
		{
			// 假定第一个就是最小或者是最大的值
			int initIndex = i;
			for (int k = i + 1; k < this->workerNum;k++)
			{
				if (sortModel == 1)
				{
					if (this->workers[initIndex]->m_id > this->workers[k]->m_id)
					{
						initIndex = k;
					}
				}
				else
				{
					if (this->workers[initIndex]->m_id < this->workers[k]->m_id)
					{
						initIndex = k;
					}
				}
			}
			// 把找到的与假定值不符的交换
			Worker *temp = this->workers[i];
			this->workers[i] = this->workers[initIndex];
			this->workers[initIndex] = temp;
		}
		cout << "排序后的结果：" << endl;
		this->save();
		this->showWorkerInfo();
	}
}

void WorkerManeger::clearData()
{
	cout << "您确定清空吗？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int confirm;
	cin >> confirm;

	if (confirm == 1)
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();

		if (this->workers != NULL)
		{
			for (int i = 0; i < this->workerNum; i++)
			{
				if (this->workers[i] != NULL)
				{
					delete this->workers[i];
					this->workers[i] = NULL;
				}
			}
			delete[] this->workers;
			this->workers = NULL;
			this->workerNum = 0;
			this->isEmpty = true;
		}
	}
	system("pause");
	system("cls");
}