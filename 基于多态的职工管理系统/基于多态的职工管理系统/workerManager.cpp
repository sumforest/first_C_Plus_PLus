#include "workerManager.h"

// ���캯��
WorkerManeger::WorkerManeger()
{
	// 1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		// ��ʼ��ָ��
		this->workers = NULL;
		this->workerNum = 0;
		// ���ļ������ڱ�Ǹ�Ϊtrue
		this->isEmpty = true;
		// �ر��ļ���
		ifs.close();
		return;
	}
	// 2.�ļ���������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->workers = NULL;
		this->workerNum = 0;
		this->isEmpty = true;
		ifs.close();
		return;
	}

	// 3.�ļ���Ϊ�ղ���������
	int empleeNum = this->getEmpleeNums();
	//cout << "����ְ����" << empleeNum << endl;
	this->workerNum = empleeNum;
	this->isEmpty = false;
	
	// ��ʼ���ռ�
	this->workers = new Worker*[this->workerNum];
	// ��ʼ������
	this->init();

	//for (int i = 0; i < empleeNum; i++)
	//{
	//	cout << "id = " << this->workers[i]->m_id
	//		<< " name = " << this->workers[i]->m_name
	//		<< " depId = " << this->workers[i]->m_depId << endl;
	//}
}

// ��������
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
	cout << "****************      ��ӭʹ��ְ������ϵͳ��    ********************" << endl;
	cout << "*******************      0.�Ƴ��������      ***********************" << endl;
	cout << "*******************      1.����ְ����Ϣ      ***********************" << endl;
	cout << "*******************      2.��ʾְ����Ϣ      ***********************" << endl;
	cout << "*******************      3.ɾ��ְ����Ϣ      ***********************" << endl;
	cout << "*******************      4.�޸�ְ����Ϣ      ***********************" << endl;
	cout << "*******************      5.����ְ����Ϣ      ***********************" << endl;
	cout << "*******************      6.���ձ������      ***********************" << endl;
	cout << "*******************      7.��������ĵ�      ***********************" << endl;
	cout << endl;
}

void  WorkerManeger::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManeger::addWorkers()
{
	// ����һ��ָ�����飨����ָ�룩
	Worker** newspace = NULL;
	cout << "������Ҫ��ӵ�Ա��������" << endl;
	int inputNum = 0;
	cin >> inputNum;
	if (inputNum > 0)
	{
		// ��ʼ����ָ������
		newspace = new Worker*[this->workerNum + inputNum];
		// ��ǰԱ��������Ϊ�գ���ԭ����Ա������µ�ָ����������
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

				cout << "������ " << i + 1 << "��Ա���ı��" << endl;
				cin >> id;

				cout << "������ " << i + 1 << "��Ա��������" << endl;
				cin >> name;

				cout << "������ " << i + 1 << "��Ա���Ĳ��ű��" << endl;
				cout << "1-��ͨԱ��" << endl;
				cout << "2-���ž���" << endl;
				cout << "3-�ϰ�" << endl;
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
				// �����ְ�����µ�ָ��������
				newspace[workerNum + i] = worker;
				// �ͷ�ԭ����ָ�������ڴ�
				delete[] this->workers;
				// ���¶���ָ��ָ��
				workers = newspace;
				// ����ְ��������
				this->workerNum = this->workerNum + inputNum;
			}
		cout << "��ӳɹ�" << inputNum << "��Ա��" << endl;
		this->save();
		// ���ְ���ɹ�����ļ��Ƿ�Ϊ�ձ�Ǹĳ�false
		this->isEmpty = false;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "������������" << endl;
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
	// �洢���ݵĻ�����
	int id;
	string name;
	int depId;
	
	// >>��ȡ�����ո񷵻أ����������ո�
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
	// ��ȡһ������
	while (ifs >> id && ifs >> name && ifs >> depId)
	{
		// ʹ�����ݴ��������ְ����
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

		// ��ӵ�ָ����������
		this->workers[index] = worker;
		index++;
	}

	// �ر��ļ�������
	ifs.close();
}

void WorkerManeger::showWorkerInfo()
{
	if (this->isEmpty == true)
	{
		cout << "�ļ������ڻ����ļ�Ϊ�գ�" << endl;
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
		cout << "����Ϊ�գ�ɾ��ʧ��" << endl;
	}
	else
	{
		int id;
		cout << "������ְ����ţ�" << endl;
		cin >> id;
		int res = this->findIndex(id);
		if (res == -1)
		{
			cout << "ɾ��ʧ�ܣ����޴���" << endl;
		}
		else
		{
			// workerNum - 1��ɾ��Ԫ��Ϊ���һ��ʱ�����鲻�ƶ�
			for (int i = res; i < this->workerNum - 1; i++)
			{
				this->workers[i] = this->workers[i + 1];
			}
			this->workerNum--;
			// ˢ���ļ�����
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
		cout << "��ǰ�ļ�Ϊ�գ��޸�ʧ��" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸�Ա���ı�ţ�" << endl;
		int workerNo;
		cin >> workerNo;
		int res = this->findIndex(workerNo);
		if (res != -1)
		{
			cout << "���ҵ���Ա����Ϣ��" << endl;
			this->workers[res]->showInfo();

			int id = 0;
			string name = "";
			int depId = 0;

			cout << "�������µı�ţ�" << endl;
			cin >> id;
			cout << "�������µ�������" << endl;
			cin >> name;
			cout << "�������µĲ��ű�ţ�" << endl;
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
			// �����޸ĺ�Ķ���
			this->workers[res] = worker;
			this->save();
		}
		else
		{
			cout << "���޴��ˣ��޸�ʧ��!" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManeger::findWorker()
{
	if (this->isEmpty)
	{
		cout << "����ʧ�ܣ��ļ�Ϊ��" << endl;
	}
	else
	{
		cout << "��ѡ����ҷ�ʽ��" << endl;
		cout << "1.����Ų���" << endl;
		cout << "2.����������" << endl;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << "������Ҫ���ҵ�Ա����ţ�" << endl;
			int fId;
			cin >> fId;
			int res = this->findIndex(fId);
			if (res != -1)
			{
				this->workers[res]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "������Ҫ���ҵ�Ա����������" << endl;
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
				cout << "����ʧ�ܣ����޴���" << endl;
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
		cout << "����ʧ�ܣ��ļ�������" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ķ�ʽ" << endl;
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		int sortModel;
		cin >> sortModel;

		// ѡ������
		for (int i = 0; i < this->workerNum; i++)
		{
			// �ٶ���һ��������С����������ֵ
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
			// ���ҵ�����ٶ�ֵ�����Ľ���
			Worker *temp = this->workers[i];
			this->workers[i] = this->workers[initIndex];
			this->workers[initIndex] = temp;
		}
		cout << "�����Ľ����" << endl;
		this->save();
		this->showWorkerInfo();
	}
}

void WorkerManeger::clearData()
{
	cout << "��ȷ�������" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
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