#include <iostream>
using namespace std;
#include <string>

struct Student
{
	string name;
	int age;
	int score;
};

struct TeacherB
{
	int id;
	string name;
	int age;
	Student student;
};
int main38()
{
	// 嵌套结构体
	TeacherB t;
	t.id = 1000;
	t.age = 40;
	t.name = "老王";
	t.student.name = "小王";
	t.student.age = 18;
	t.student.score = 100;

	cout << "老师id = " << t.id << " 老师姓名：" << t.name << " 老师年龄：" << t.age << " 学生姓名："
		<< t.student.name << " 学生年龄：" << t.student.age << " 学生成绩：" << t.student.score << endl;

	system("pause");
	return 0;
}