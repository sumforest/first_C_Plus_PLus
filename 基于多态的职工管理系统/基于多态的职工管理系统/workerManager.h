#pragma once // ֻ����һ��ͷ�ļ�����ֹͷ�ļ��ظ�����
#include <iostream> // ��������������ļ�
using namespace std; //ʹ�ñ�׼�����ռ�
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

	// ְ��������
	int workerNum;

	// ְ���ڴ��ַ����
	Worker** workers;

	// �Ƿ�����ļ�
	bool  isEmpty;

	void addWorkers();

	void save();

	// ���ļ��л�ȡְ���ĸ���
	int getEmpleeNums();

	// ��ʼ������
	void init();

	void showWorkerInfo();

	// ͨ��id����ְ���������е��±꣬���ڷ����±꣬���򷵻�-1;
	int findIndex(int id);

	void delWorker();

	void modifyWorker();

	void findWorker();

	void sort();

	void clearData();
};
