#include <iostream>
using namespace std;
#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <algorithm>

class Person_24
{
public:
	Person_24(string name, int score)
	{
		this->name = name;
		this->score = score;
	}
	int score;
	string name;
};

void createPersons(vector<Person_24>& v)
{
	string seed = "ABCDE";

	for (int i = 0; i < 5; i++)
	{
		string name = "学生";
		name += seed[i];
		Person_24 p(name, 0);
		v.push_back(p);
	}
}

void setScores(vector<Person_24>& v)
{
	for (vector<Person_24>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int> scores;

		for (int i = 0; i < 10; i++)
		{
			// 分数范围60-100
			int socre = rand() % 41 + 60;
			scores.push_back(socre);
		}
		// 排序
		sort(scores.begin(), scores.end());
		// 去掉一个最高分和一个最低分
		scores.pop_back();
		scores.pop_front();
		// 计算总分
		int count = 0;
		for (int i = 0; i < scores.size(); i++)
		{
			count += scores[i];
		}
		// 计算平均分
		int avg = count / scores.size();
		// 设置每个学生的分数
		(*it).score = avg;
	}
}

void showSocres(const vector<Person_24> v)
{
	for (vector<Person_24>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "学生：" << (*it).name << "；成绩：" << (*it).score << endl;
	}
}

int main24()
{
	// 随机数种子
	srand((unsigned int)time(NULL));
	// 创建5个学生
	vector<Person_24> v;
	createPersons(v);

	// 给10个评委学生打分
	setScores(v);

	// 输出学生的成绩
	showSocres(v);

	system("pause");
	return 0;
}