#include <iostream>
using namespace std;
#include <string>
// ͨѶ¼�������
#define MAX 1000

// ��ӡ�˵�
void showMenu() {
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�Ƴ���ϵ��  *****" << endl;
	cout << "**************************" << endl;
}

// ��ϵ�˽ṹ��
struct Person
{
	string name;
	// 1 �У�2 Ů
	int sex;

	int age;

	string phone;

	string address;
};

// ͨѶ¼�ṹ�� 
struct AddressBook
{
	int m_size;
	Person persons[MAX];
};

// �����ϵ��
void addPerson(AddressBook *p)
{
	// ���ͨѶ¼�Ƿ�����
	if (p->m_size == MAX)
	{
		cout << "ͨѶ¼���������ʧ�ܣ�" << endl;
	}
	else {
		// �����ϵ��
		string name;
		cout << "��������ϵ��������" << endl;
		cin >> name;
		p->persons[p->m_size].name = name;
		
		int sex;
		cout << "�������Ա�1 - �У�2 - Ů����" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				p->persons[p->m_size].sex = sex;
				break;
			}
			cout << "����������������������" << endl;
		}

		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		p->persons[p->m_size].age = age;

		string phone;
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		p->persons[p->m_size].phone = phone;

		string address;
		cout << "����סַ��" << endl;
		cin >> address;
		p->persons[p->m_size].address = address;
		p->m_size++;
		cout << "��ӳɹ�" << endl;
	}
	// �����������
	system("pause");
	// ����
	system("cls");
}

void showPersons(AddressBook *abs)
{
	if (abs->m_size == 0)
	{
		cout << "ͨѶ¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������" << abs->persons[i].name << "\t";
			cout << "�Ա�" << (abs->persons[i].sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->persons[i].age << "\t" ;
			cout << "��ϵ�绰��" << abs->persons[i].phone << "\t" ;
			cout << "סַ��" << abs->persons[i].address << "\t" << endl;
		}
	}
	// �����������
	system("pause");
	// ����
	system("cls");
}

// ͨ�����������Ƿ���ڸ���
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
	cout << "������Ҫɾ����������" << endl;
	cin >> name;
	int result = isExist(abs, name);
	if (result == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		for (int i = result; i < abs->m_size - 1; i++)
		{
			abs->persons[i] = abs->persons[i + 1];
		}
		abs->m_size--;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(AddressBook *abs)
{
	string name;
	cout << "��������ϵ��������" << endl;
	cin >> name;

	int res = isExist(abs, name);
	if (res == -1)
	{
		cout << "���޴��ˣ���" << endl;
	}
	else
	{
		cout << "������" << abs->persons[res].name << "\t";
		cout << "�Ա�" << (abs->persons[res].sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->persons[res].age << "\t";
		cout << "��ϵ�绰��" << abs->persons[res].phone << "\t";
		cout << "סַ��" << abs->persons[res].address << "\t" << endl;
	}
	
	system("pause");
	system("cls");
}

// �޸���ϵ����Ϣ
void modifyPerson(AddressBook *abs)
{
	cout << "������ϵ����������" << endl;
	string name;
	cin >> name;

	int res = isExist(abs, name);
	if (res != -1)
	{
		// �����ϵ��
		string name;
		cout << "��������ϵ��������" << endl;
		cin >> name;
		abs->persons[res].name = name;

		int sex;
		cout << "�������Ա�1 - �У�2 - Ů����" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->persons[res].sex = sex;
				break;
			}
			cout << "����������������������" << endl;
		}

		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->persons[res].age = age;

		string phone;
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		abs->persons[res].phone = phone;

		string address;
		cout << "����סַ��" << endl;
		cin >> address;
		abs->persons[res].address = address;
		cout << "�޸�" << endl;
	}
	else
	{
		cout << "���޴��ˣ��޷��޸ģ�" << endl;
	}

	system("pause");
	system("cls");
}

void cleanAddressBook(AddressBook *abs)
{
	abs->m_size = 0;
	cout << "ͨѶ¼��ճɹ�" << endl;
	
	system("pause");
	system("cls");
}

int main()
{
	int select = 0;
	// ��ʼ��ͨѶ¼
	AddressBook abs;
	abs.m_size = 0;

	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
			case 1://�����ϵ��
				addPerson(&abs);
				break;
			case 2://��ʾ��ϵ��
				showPersons(&abs);
					break;
			case 3://ɾ����ϵ��
				deletePerson(&abs);
				break;
			case 4://������ϵ��
				findPerson(&abs);
				break;
			case 5://�޸���ϵ��
				modifyPerson(&abs);
				break;
			case 6://�����ϵ��
				cleanAddressBook(&abs);
				break;
			case 0://�Ƴ���ϵ��
				cout << "��ӭ�´�ʹ�ã��ټ���" << endl;
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