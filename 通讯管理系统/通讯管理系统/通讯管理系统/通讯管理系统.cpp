#include <iostream>
using namespace std;
#include <string>
// 通讯录最大容量
#define MAX 1000

// 打印菜单
void showMenu() {
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.推出联系人  *****" << endl;
	cout << "**************************" << endl;
}

// 联系人结构体
struct Person
{
	string name;
	// 1 男，2 女
	int sex;

	int age;

	string phone;

	string address;
};

// 通讯录结构体 
struct AddressBook
{
	int m_size;
	Person persons[MAX];
};

// 添加联系人
void addPerson(AddressBook *p)
{
	// 检查通讯录是否已满
	if (p->m_size == MAX)
	{
		cout << "通讯录已满，添加失败！" << endl;
	}
	else {
		// 添加联系人
		string name;
		cout << "请输入联系人姓名：" << endl;
		cin >> name;
		p->persons[p->m_size].name = name;
		
		int sex;
		cout << "请输入性别（1 - 男；2 - 女）：" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				p->persons[p->m_size].sex = sex;
				break;
			}
			cout << "您的输入有误，请重新输入" << endl;
		}

		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		p->persons[p->m_size].age = age;

		string phone;
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		p->persons[p->m_size].phone = phone;

		string address;
		cout << "请入住址：" << endl;
		cin >> address;
		p->persons[p->m_size].address = address;
		p->m_size++;
		cout << "添加成功" << endl;
	}
	// 按任意键继续
	system("pause");
	// 清屏
	system("cls");
}

void showPersons(AddressBook *abs)
{
	if (abs->m_size == 0)
	{
		cout << "通讯录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：" << abs->persons[i].name << "\t";
			cout << "性别：" << (abs->persons[i].sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->persons[i].age << "\t" ;
			cout << "联系电话：" << abs->persons[i].phone << "\t" ;
			cout << "住址：" << abs->persons[i].address << "\t" << endl;
		}
	}
	// 按任意键继续
	system("pause");
	// 清屏
	system("cls");
}

// 通过姓名搜索是否存在该人
int isExist(AddressBook *abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->persons[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(AddressBook *abs)
{
	string name;
	cout << "请输入要删除的姓名：" << endl;
	cin >> name;
	int result = isExist(abs, name);
	if (result == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		for (int i = result; i < abs->m_size - 1; i++)
		{
			abs->persons[i] = abs->persons[i + 1];
		}
		abs->m_size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(AddressBook *abs)
{
	string name;
	cout << "请输入联系人姓名：" << endl;
	cin >> name;

	int res = isExist(abs, name);
	if (res == -1)
	{
		cout << "查无此人！！" << endl;
	}
	else
	{
		cout << "姓名：" << abs->persons[res].name << "\t";
		cout << "性别：" << (abs->persons[res].sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->persons[res].age << "\t";
		cout << "联系电话：" << abs->persons[res].phone << "\t";
		cout << "住址：" << abs->persons[res].address << "\t" << endl;
	}
	
	system("pause");
	system("cls");
}

// 修改联系人信息
void modifyPerson(AddressBook *abs)
{
	cout << "请输联系人入姓名：" << endl;
	string name;
	cin >> name;

	int res = isExist(abs, name);
	if (res != -1)
	{
		// 添加联系人
		string name;
		cout << "请输入联系人姓名：" << endl;
		cin >> name;
		abs->persons[res].name = name;

		int sex;
		cout << "请输入性别（1 - 男；2 - 女）：" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->persons[res].sex = sex;
				break;
			}
			cout << "您的输入有误，请重新输入" << endl;
		}

		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->persons[res].age = age;

		string phone;
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		abs->persons[res].phone = phone;

		string address;
		cout << "请入住址：" << endl;
		cin >> address;
		abs->persons[res].address = address;
		cout << "修改" << endl;
	}
	else
	{
		cout << "查无此人，无法修改！" << endl;
	}

	system("pause");
	system("cls");
}

void cleanAddressBook(AddressBook *abs)
{
	abs->m_size = 0;
	cout << "通讯录清空成功" << endl;
	
	system("pause");
	system("cls");
}

int main()
{
	int select = 0;
	// 初始化通讯录
	AddressBook abs;
	abs.m_size = 0;

	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
			case 1://添加联系人
				addPerson(&abs);
				break;
			case 2://显示联系人
				showPersons(&abs);
					break;
			case 3://删除联系人
				deletePerson(&abs);
				break;
			case 4://查找联系人
				findPerson(&abs);
				break;
			case 5://修改联系人
				modifyPerson(&abs);
				break;
			case 6://清空联系人
				cleanAddressBook(&abs);
				break;
			case 0://推出联系人
				cout << "欢迎下次使用，再见！" << endl;
				system("pause");
				return 0;
				break;
			default:
				break;
		}
	}

	system("pause");
	return 0;
}