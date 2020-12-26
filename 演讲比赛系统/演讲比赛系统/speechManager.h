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

	// 存放第一轮参加比赛的12个选手编号
	vector<int> v1;

	// 存放第二轮参赛的选手编号
	vector<int> v2;

	// 存放胜利的选手编号
	vector<int> vectory;

	// 存放选手编号和选手对象
	map<int, Speaker> m;
	
	// 记录比赛的轮数
	int count;

	void init();

	void createSpeaker();

	// 开始比赛
	void startSpeech();

	// 抽签
	void speechDraw();

	// 进行比赛
	void speechContest();

	void showSocre();
	
	// 保存比赛记录
	void saveRecord();

	// 读取文件记录
	void loadRecord();

	// 文件是否为空
	bool fileIsEmpty = false;

	// 记录往届成绩，k-届数；v-前三名成绩
	map<int, vector<string>> record;

	// 展示比赛记录
   void	showRecord();

   void clearRecord();
};
