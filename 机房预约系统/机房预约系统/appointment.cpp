#include "appointmentFile.h"

AppointmentFile::AppointmentFile()
{
	// 把存在文件中的预约记录读取到m_map中
	ifstream ifs(APPOINTMENT_FILE, ios::in);

	// 星期
	string date;
	// 上下午
	string interval;
	// 学生id
	string stuId;
	// 学生姓名
	string name;
	// 机房号
	string computerRoomNo;
	// 状态
	string state;

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> name && ifs >> computerRoomNo && ifs >> state)
	{
		map<string, string> map;

		int pos = date.find(":");
		if (pos != -1)
		{
			string k = date.substr(0, pos);
			string v = date.substr(pos + 1, date.size() - pos - 1);
			map.insert(make_pair(k, v));
		}

		pos = interval.find(":");
		if (pos != -1)
		{
			string k = interval.substr(0, pos);
			string v = interval.substr(pos + 1, interval.size() - pos - 1);
			map.insert(make_pair(k, v));
		}

		pos = stuId.find(":");
		if (pos != -1)
		{
			string k = stuId.substr(0, pos);
			string v = stuId.substr(pos + 1, stuId.size() - pos - 1);
			map.insert(make_pair(k, v));
		}

		pos = name.find(":");
		if (pos != -1)
		{
			string k = name.substr(0, pos);
			string v = name.substr(pos + 1, name.size() - pos - 1);
			map.insert(make_pair(k, v));
		}

		pos = computerRoomNo.find(":");
		if (pos != -1)
		{
			string k = computerRoomNo.substr(0, pos);
			string v = computerRoomNo.substr(pos + 1, computerRoomNo.size() - pos - 1);
			map.insert(make_pair(k, v));
		}

		pos = state.find(":");
		if (pos != -1)
		{
			string k = state.substr(0, pos);
			string v = state.substr(pos + 1, state.size() - pos - 1);
			map.insert(make_pair(k, v));
		}

		this->m_map.insert(make_pair(this->size, map));
		this->size++;
	}

	// 关闭流
	ifs.close();

	/*for (map<int, map<string, string>>::iterator it = m_map.begin(); it != m_map.end(); it++)
	{
		cout << "条数：" << it->first << endl;
		for (map<string, string>::iterator mIt = it->second.begin(); mIt != it->second.end(); mIt++)
		{
			cout << " " << mIt->first << ":" << mIt->second << "；";
		}
		cout << endl;
	}*/
}

void AppointmentFile::update()
{
	if (this->size == 0)
	{
		cout << "当前记录为空，更新失败" << endl;
		return;
	}
	ofstream ofs(APPOINTMENT_FILE, ios::trunc);

	for (int i = 0; i < this->size; i++)
	{
		ofs << "date:" << this->m_map[i]["date"] << " ";
		ofs << "interval:" << this->m_map[i]["interval"] << " ";
		ofs << "stuId:" << this->m_map[i]["stuId"] << " ";
		ofs << "name:" << this->m_map[i]["name"] << " ";
		ofs << "computerRoomNo:" << this->m_map[i]["computerRoomNo"] << " ";
		ofs << "state:" << this->m_map[i]["state"] << endl;
	}
}