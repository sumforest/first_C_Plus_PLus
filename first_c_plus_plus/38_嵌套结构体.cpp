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
	// Ƕ�׽ṹ��
	TeacherB t;
	t.id = 1000;
	t.age = 40;
	t.name = "����";
	t.student.name = "С��";
	t.student.age = 18;
	t.student.score = 100;

	cout << "��ʦid = " << t.id << " ��ʦ������" << t.name << " ��ʦ���䣺" << t.age << " ѧ��������"
		<< t.student.name << " ѧ�����䣺" << t.student.age << " ѧ���ɼ���" << t.student.score << endl;

	system("pause");
	return 0;
}