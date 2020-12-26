#include "speechManager.h"

SpeechManager::SpeechManager()
{
	init();
	createSpeaker();
	loadRecord();
}

SpeechManager::~SpeechManager()
{

}

void SpeechManager::showMenu()
{
	cout << "***********************************************************************" << endl;
	cout << "********************          ��ӭ�μ��ݽ�����       ******************" << endl;
	cout << "********************           1.��ʼ�ݽ�����        ******************" << endl;
	cout << "********************           2.�鿴�����¼        ******************" << endl;
	cout << "********************           3.��ձ�����¼        ******************" << endl;
	cout << "********************           0.�˳���������        ******************" << endl;
	cout << "***********************************************************************" << endl;
}

void SpeechManager::exitSys()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::init()
{
	this->v1.clear();
	this->v2.clear();
	this->vectory.clear();
	// ��ʼ����������Ϊ1
	this->count = 1;
	this->record.clear();
}

void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker sp;
		sp.name = name;
		// ��ʼ��ÿ�ֵķ���Ϊ0
		for (int j = 0; j < 2; j++)
		{
			sp.socre[j] = 0;
		}

		// ����ѡ�ֵı��
		int num = i + 10001;
		v1.push_back(num);
		// ��ѡ�ִ浽map��
		m.insert(make_pair(num, sp));
	}
}

void SpeechManager::startSpeech()
{
	// ��һ�ֿ�ʼ��ǩ
	speechDraw();
	// ����
	speechContest();
	// ��ʾѡ�ֽ���
	showSocre();

	// �ڶ��ֳ�ǩ��ʼ
	this->count++;
	speechDraw();
	// ����
	speechContest();
	// ��ʾѡ�ֽ���
	showSocre();
	// �������ս��
	saveRecord();

	// ���³�ʼ������
	this->init();
	// ����12��ѡ��
	this->createSpeaker();
	// ���¼��ر�����¼
	this->loadRecord();

}

void SpeechManager::speechDraw()
{
	cout << "�� <<" << this->count << ">> �ֱ�����ʼ����ǩ�����" << endl;
	random_shuffle(v1.begin(), v1.end());
	if (this->count == 1)
	{
		cout << "------------------- ��һ�ֳ�ǩ��� -----------------" << endl;
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
	}
	else
	{
		cout << "------------------- �ڶ��ֳ�ǩ��� -----------------" << endl;
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
	}
	cout << endl;
	system("pause");
}

// ��ʼ����
void SpeechManager::speechContest()
{
	cout << "�ڡ�" << this->count << "���α�����ʼ" << endl;

	// ���б�����ѡ��
	vector<int> v_src;
	if (this->count == 1)
	{
		v_src = v1;
	}
	else
	{
		v_src = v2;
	}
	// ��¼�Ƿ�Ϊ6��һ��
	int num = 0;
	// key-- ������value-- ѡ�ֱ��
	multimap<double, int, greater<double>> tempMap;

	// ����ÿ��ѡ��
	for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++)
	{
		num++;

		// 10����ί��ѡ�ִ��
		deque<int> de;
		for (int i = 0; i < 10; i++)
		{
			// ����10�������
			double temp_socre = (rand() % 401 + 600) / 10.f;
			de.push_back(temp_socre);
		}
		// ��������
		sort(de.begin(), de.end(), greater<double>());
		// ȥ����߷�
		de.pop_front();
		// ȥ����ͷ�
		de.pop_back();
		// �����ܷ�
		double countScore = accumulate(de.begin(), de.end(), 0.0f);
		// ����ƽ����
		double avg = countScore / (double)de.size();
		// ���������ѡ��map��
		this->m[*it].socre[this->count - 1] = avg;
		// �����������ʱmultimap��
		tempMap.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��ɼ�������" << endl;
			for (multimap<double, int, greater<double>>::iterator it = tempMap.begin(); it != tempMap.end(); it++)
			{
				cout << "��ţ�" << (*it).second << "��������" << this->m[(*it).second].name << "��������" << it->first << endl;
			}
			cout << endl;
			// ��ȡǰ����ѡ�ֽ���
			int threeBefore = 0;
			for (multimap<double, int, greater<double>>::iterator it = tempMap.begin(); it != tempMap.end() && threeBefore < 3; it++, threeBefore++)
			{
				if (this->count == 1)
				{
					v2.push_back(it->second);
				}
				else
				{
					vectory.push_back(it->second);
				}
			}
			// ��մ�ŷ������ʱ����
			tempMap.clear();
		}
	}
	cout << endl;
	cout << "------------------ " << this->count << "��������------------------" << endl;
	system("pause");
}

void SpeechManager::showSocre()
{
	cout << "-------------" << this->count << "�ֽ�������----------------" << endl;

	vector<int> v;
	if (this->count == 1)
	{
		v = v2;
	}
	else
	{
		v = vectory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "��ţ�" << *it << "��������" << m[*it].name << "������" << m[*it].socre[this->count - 1] << endl;
	}
	system("pause");
	system("cls");
	showMenu();
}

void SpeechManager::saveRecord()
{
	ofstream ofs;
	// ��׷�ӵķ�ʽ���ļ�
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = vectory.begin(); it != vectory.end(); it++)
	{
		ofs << *it << "," << this->m[*it].socre[1] << ",";
	}
	// ����
	ofs << endl;
	ofs.close();
	this->fileIsEmpty = false;
	cout << "��������������" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::loadRecord()
{
	// ��������������
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	// ���Զ�ȡһ���ַ�
	char ch;
	ifs >> ch;
	// �����ȡ���ļ�β
	if (ifs.eof())
	{
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	// ����ļ���Ϊ�����֮ǰ��ȡ��һ���ַ���д����
	ifs.putback(ch);
	string data;
	int index = 0;
	// ��ȡһ�з���һ�ν��
	while (ifs >> data)
	{
		int start = 0;
		vector<string> v;
		while (true)
		{
			int pos = data.find(",",start);
			// û���ҵ�
			if (pos == -1)
			{
				// �˳�ѭ��
				break;
			}
			// �и��ַ���
			string subStr =  data.substr(start, pos - start);
			v.push_back(subStr);
			// ����start
			start = pos + 1;
		}
		// һ�н�������һ�α�����¼����ȡ��
		this->record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}

void  SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڻ��߱������" << endl;
	}
	else {
		for (int i = 0; i < this->record.size(); i++)
		{
			cout << "��" << i + 1 << "������ɼ���\t"
				<< "�ھ���" << this->record[i][0] << "��������" << this->record[i][1] << "\t"
				<< "�Ǿ���" << this->record[i][2] << "��������" << this->record[i][3] << "\t"
				<< "������" << this->record[i][4] << "��������" << this->record[i][5] << endl;
		}
	}
	
	system("pause");
	system("cls");
}

void SpeechManager::clearRecord()
{
	cout << "ȷ��Ҫ�����" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		// �ļ�����ɾ���ٴ���һ�����ļ�
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		this->init();
		this->createSpeaker();
		this->loadRecord();
		cout << "�ļ������" << endl;
	}

	system("pause");
	system("cls");
}