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
	cout << "********************          欢迎参加演讲比赛       ******************" << endl;
	cout << "********************           1.开始演讲比赛        ******************" << endl;
	cout << "********************           2.查看往届记录        ******************" << endl;
	cout << "********************           3.清空比赛记录        ******************" << endl;
	cout << "********************           0.退出比赛程序        ******************" << endl;
	cout << "***********************************************************************" << endl;
}

void SpeechManager::exitSys()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::init()
{
	this->v1.clear();
	this->v2.clear();
	this->vectory.clear();
	// 初始化比赛轮数为1
	this->count = 1;
	this->record.clear();
}

void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		Speaker sp;
		sp.name = name;
		// 初始化每轮的分数为0
		for (int j = 0; j < 2; j++)
		{
			sp.socre[j] = 0;
		}

		// 创建选手的编号
		int num = i + 10001;
		v1.push_back(num);
		// 把选手存到map中
		m.insert(make_pair(num, sp));
	}
}

void SpeechManager::startSpeech()
{
	// 第一轮开始抽签
	speechDraw();
	// 比赛
	speechContest();
	// 显示选手晋级
	showSocre();

	// 第二轮抽签开始
	this->count++;
	speechDraw();
	// 比赛
	speechContest();
	// 显示选手晋级
	showSocre();
	// 保存最终结果
	saveRecord();

	// 重新初始化数组
	this->init();
	// 创建12个选手
	this->createSpeaker();
	// 重新加载比赛记录
	this->loadRecord();

}

void SpeechManager::speechDraw()
{
	cout << "第 <<" << this->count << ">> 轮比赛开始，抽签结果：" << endl;
	random_shuffle(v1.begin(), v1.end());
	if (this->count == 1)
	{
		cout << "------------------- 第一轮抽签结果 -----------------" << endl;
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
	}
	else
	{
		cout << "------------------- 第二轮抽签结果 -----------------" << endl;
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
	}
	cout << endl;
	system("pause");
}

// 开始比赛
void SpeechManager::speechContest()
{
	cout << "第《" << this->count << "》次比赛开始" << endl;

	// 进行比赛的选手
	vector<int> v_src;
	if (this->count == 1)
	{
		v_src = v1;
	}
	else
	{
		v_src = v2;
	}
	// 记录是否为6人一组
	int num = 0;
	// key-- 分数；value-- 选手编号
	multimap<double, int, greater<double>> tempMap;

	// 遍历每个选手
	for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++)
	{
		num++;

		// 10个评委给选手打分
		deque<int> de;
		for (int i = 0; i < 10; i++)
		{
			// 生成10个随机数
			double temp_socre = (rand() % 401 + 600) / 10.f;
			de.push_back(temp_socre);
		}
		// 降序排序
		sort(de.begin(), de.end(), greater<double>());
		// 去掉最高分
		de.pop_front();
		// 去掉最低分
		de.pop_back();
		// 计算总分
		double countScore = accumulate(de.begin(), de.end(), 0.0f);
		// 计算平均分
		double avg = countScore / (double)de.size();
		// 保存分数到选手map中
		this->m[*it].socre[this->count - 1] = avg;
		// 保存分数到临时multimap中
		tempMap.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组成绩排名：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = tempMap.begin(); it != tempMap.end(); it++)
			{
				cout << "编号：" << (*it).second << "；姓名：" << this->m[(*it).second].name << "；分数：" << it->first << endl;
			}
			cout << endl;
			// 获取前三名选手晋级
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
			// 清空存放分组的临时容器
			tempMap.clear();
		}
	}
	cout << endl;
	cout << "------------------ " << this->count << "比赛结束------------------" << endl;
	system("pause");
}

void SpeechManager::showSocre()
{
	cout << "-------------" << this->count << "轮晋级名单----------------" << endl;

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
		cout << "编号：" << *it << "；姓名：" << m[*it].name << "；分数" << m[*it].socre[this->count - 1] << endl;
	}
	system("pause");
	system("cls");
	showMenu();
}

void SpeechManager::saveRecord()
{
	ofstream ofs;
	// 以追加的方式打开文件
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = vectory.begin(); it != vectory.end(); it++)
	{
		ofs << *it << "," << this->m[*it].socre[1] << ",";
	}
	// 换行
	ofs << endl;
	ofs.close();
	this->fileIsEmpty = false;
	cout << "比赛结果保存完毕" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::loadRecord()
{
	// 创建输入流对象
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	// 尝试读取一个字符
	char ch;
	ifs >> ch;
	// 如果读取到文件尾
	if (ifs.eof())
	{
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	// 如果文件不为空则把之前读取的一个字符给写回来
	ifs.putback(ch);
	string data;
	int index = 0;
	// 读取一行返回一次结果
	while (ifs >> data)
	{
		int start = 0;
		vector<string> v;
		while (true)
		{
			int pos = data.find(",",start);
			// 没有找到
			if (pos == -1)
			{
				// 退出循环
				break;
			}
			// 切割字符串
			string subStr =  data.substr(start, pos - start);
			v.push_back(subStr);
			// 更新start
			start = pos + 1;
		}
		// 一行结束代表一次比赛记录被读取了
		this->record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}

void  SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件不存在或者被清空了" << endl;
	}
	else {
		for (int i = 0; i < this->record.size(); i++)
		{
			cout << "第" << i + 1 << "届比赛成绩：\t"
				<< "冠军：" << this->record[i][0] << "，分数：" << this->record[i][1] << "\t"
				<< "亚军：" << this->record[i][2] << "，分数：" << this->record[i][3] << "\t"
				<< "季军：" << this->record[i][4] << "，分数：" << this->record[i][5] << endl;
		}
	}
	
	system("pause");
	system("cls");
}

void SpeechManager::clearRecord()
{
	cout << "确认要清空吗？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		// 文件存在删除再创建一个空文件
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		this->init();
		this->createSpeaker();
		this->loadRecord();
		cout << "文件已清空" << endl;
	}

	system("pause");
	system("cls");
}