#include <iostream>
using namespace std;
#include <string>

struct Hero
{
	string name;

	int age;

	string sex;
};

void bubbbleSort(Hero arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j].age > arr[j + 1].age)
			{
				Hero temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void printHero(Hero arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "���֣�" << arr[i].name << " ���䣺" << arr[i].age << " �Ա�" << arr[i].sex << endl;
	}
}


int main41()
{
	Hero heroes[] =
	{
		{"����",23,"��"},
		{"����",22,"��"},
		{"�ŷ�",20,"��"},
		{"����",21,"��"},
		{"����",19,"Ů"},
	};

	int len = sizeof(heroes) / sizeof(heroes[0]);
	bubbbleSort(heroes, len);
	printHero(heroes, len);

	system("pause");
	return 0;
}