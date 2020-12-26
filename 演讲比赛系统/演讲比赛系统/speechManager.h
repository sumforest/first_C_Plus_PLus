#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "speaker.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <string>
#include <fstream>

class SpeechManager
{
public:
	SpeechManager();

	~SpeechManager();

	void showMenu();

	void exitSys();

	// ��ŵ�һ�ֲμӱ�����12��ѡ�ֱ��
	vector<int> v1;

	// ��ŵڶ��ֲ�����ѡ�ֱ��
	vector<int> v2;

	// ���ʤ����ѡ�ֱ��
	vector<int> vectory;

	// ���ѡ�ֱ�ź�ѡ�ֶ���
	map<int, Speaker> m;
	
	// ��¼����������
	int count;

	void init();

	void createSpeaker();

	// ��ʼ����
	void startSpeech();

	// ��ǩ
	void speechDraw();

	// ���б���
	void speechContest();

	void showSocre();
	
	// ���������¼
	void saveRecord();

	// ��ȡ�ļ���¼
	void loadRecord();

	// �ļ��Ƿ�Ϊ��
	bool fileIsEmpty = false;

	// ��¼����ɼ���k-������v-ǰ�����ɼ�
	map<int, vector<string>> record;

	// չʾ������¼
   void	showRecord();

   void clearRecord();
};
