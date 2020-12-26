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

	// k-条数，v-每条预约记录的详细信息
	map<int, map<string, string>> m_map;

	int size = 0;
};

