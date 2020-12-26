#pragma once // 只包含一次头文件，防止头文件重复包含
#include <iostream> // 包含输入输出流文件
using namespace std; //使用标准命名空间
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
#define FILENAME "empFile.txt"

class WorkerManeger
{
public:
	WorkerManeger();

	~WorkerManeger();

	void showMenu();

	void exitSystem();

	// 职工总数量
	int workerNum;

	// 职工内存地址数据
	Worker** workers;

	// 是否存在文件
	bool  isEmpty;

	void addWorkers();

	void save();

	// 从文件中获取职工的个数
	int getEmpleeNums();

	// 初始化数据
	void init();

	void showWorkerInfo();

	// 通过id查找职工在数组中的下标，存在返回下标，否则返回-1;
	int findIndex(int id);

	void delWorker();

	void modifyWorker();

	void findWorker();

	void sort();

	void clearData();
};
