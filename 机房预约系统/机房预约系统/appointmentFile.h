#pragma once
#include <iostream>
using namespace std;
#include <map>
#include <string>
#include "globalFile.h"
#include <fstream>

class AppointmentFile
{
public:
	AppointmentFile();

	void update();

	// k-������v-ÿ��ԤԼ��¼����ϸ��Ϣ
	map<int, map<string, string>> m_map;

	int size = 0;
};

