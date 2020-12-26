#include <iostream>
using namespace std;
#include <string>
#include <ctime>

struct Student
{
	string name;
	int score;
};

struct Teacher
{
	string teacher_name;
	Student students[5];
};

void allocateTeacher(struct Teacher arr[], int len)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < len;i++)
	{
		arr[i].teacher_name = "Teacher_";
		arr[i].teacher_name += nameSeed[i];
		for (int j = 0; j < 5; j++)
		{
			arr[i].students[j].name = "Student_";
			arr[i].students[j].name += nameSeed[j];
			// 随机分数 40 - 100
			int randomNum = rand() % 61 + 40;
			arr[i].students[j].score = randomNum;
		}
	}
}
void print(Teacher arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i].teacher_name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t学生姓名：" << arr[i].students[j].name << " 学生分数：" << arr[i].students[j].score << endl;
		}
	}
}

int main40()
{
	// 随机数种子
	srand((unsigned int)time(NULL));
	struct Teacher arr[3];
	arr[0].teacher_name = "1234fasdf";
	int len = sizeof(arr) / sizeof(arr[0]);
	allocateTeacher(arr, len);
	print(arr, len);

	system("pause");
	return 0;
}