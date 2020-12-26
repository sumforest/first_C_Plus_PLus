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
		string name = "ѧ��";
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
			// ������Χ60-100
			int socre = rand() % 41 + 60;
			scores.push_back(socre);
		}
		// ����
		sort(scores.begin(), scores.end());
		// ȥ��һ����߷ֺ�һ����ͷ�
		scores.pop_back();
		scores.pop_front();
		// �����ܷ�
		int count = 0;
		for (int i = 0; i < scores.size(); i++)
		{
			count += scores[i];
		}
		// ����ƽ����
		int avg = count / scores.size();
		// ����ÿ��ѧ���ķ���
		(*it).score = avg;
	}
}

void showSocres(const vector<Person_24> v)
{
	for (vector<Person_24>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѧ����" << (*it).name << "���ɼ���" << (*it).score << endl;
	}
}

int main24()
{
	// ���������
	srand((unsigned int)time(NULL));
	// ����5��ѧ��
	vector<Person_24> v;
	createPersons(v);

	// ��10����ίѧ�����
	setScores(v);

	// ���ѧ���ĳɼ�
	showSocres(v);

	system("pause");
	return 0;
}