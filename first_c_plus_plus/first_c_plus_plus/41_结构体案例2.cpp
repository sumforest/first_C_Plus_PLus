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
		cout << "Ãû×Ö£º" << arr[i].name << " ÄêÁä£º" << arr[i].age << " ÐÔ±ð£º" << arr[i].sex << endl;
	}
}


int main41()
{
	Hero heroes[] =
	{
		{"Áõ±¸",23,"ÄÐ"},
		{"¹ØÓð",22,"ÄÐ"},
		{"ÕÅ·É",20,"ÄÐ"},
		{"ÕÔÔÆ",21,"ÄÐ"},
		{"õõ²õ",19,"Å®"},
	};

	int len = sizeof(heroes) / sizeof(heroes[0]);
	bubbbleSort(heroes, len);
	printHero(heroes, len);

	system("pause");
	return 0;
}