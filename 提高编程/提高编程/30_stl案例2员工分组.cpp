#include <iostream>
using namespace std;
#include <vector>
#include <map>	
#include <string>
#include <ctime>

#define CEHUA  0
#define MEISHU 1
#define YANFA 2

class Worker_30
{
public:
	Worker_30(string name,int salary)
	{
		this->name = name;
		this->salary = salary;
	}
	string name;
	int salary;
};

void createWorker(vector<Worker_30>& v)
{
	string seed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		string name = "员工";
		name += seed[i];
		int salary = rand() % 10000 + 10000;
		Worker_30 work(name, salary);
		v.push_back(work);
	}
}

void groudByDep(vector<Worker_30>& v, multimap<int, Worker_30>& m)
{
	for (vector<Worker_30>::iterator it = v.begin(); it != v.end(); it++)
	{
		int depNo = rand() % 3;
		m.insert(make_pair(depNo, *it));
	}
}

void showWorker(multimap<int, Worker_30>& m)
{
	cout << "策划部" << endl;
	// 获取起始指针
	multimap<int, Worker_30>::iterator pos = m.find(CEHUA);
	// 统计迭代器移动的次数
	int count = m.count(CEHUA);
	for (int index = 0; pos != m.end() && index < count ; pos++, index++)
	{
		cout << "姓名：" << pos->second.name << " 工资：" << pos->second.salary << endl;
	}

	cout << "--------------------------" << endl;
	cout << "美术部：" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	for (int index = 0; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.name << " 工资：" << pos->second.salary << endl;
	}

	cout << "-------------------------" << endl;
	cout << "研发部：" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	for (int index = 0; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.name << " 工资：" << pos->second.salary << endl;
	}
}

int main30()
{
	srand((unsigned int)time(NULL));

	vector<Worker_30> v;
	createWorker(v);

	/*for (vector<Worker_30>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << it->name << " 工资：" << it->salary << endl;
	}*/
	multimap<int, Worker_30> m;
	groudByDep(v,m);

	showWorker(m);

	system("pause");
	return 0;
}