#include <iostream>
using namespace std;
#include <string>	

struct Student
{
	string name;
	int age;
	int score;
};

void printStudent(Student student)
{
	student.age = 100;
	cout << "name = " << student.name << " age = " << student.age << " score = " << student.score << endl;
}

void printStudentByAddress(Student *p)
{
	p->age = 200;
	cout << "name = " << p->name << " age = " << p->age << " score = " << p->score << endl;
}

int main39()
{
	Student s = { "����",24,100 };

	Student students[3];
	students[0].name = "abc";
	cout << "test = " << students[0].name << endl;
	//printStudent(s);
	//cout << "name = " << s.name << " age = " << s.age << " score = " << s.score << endl;

	// ����ֵ���ݣ��βη����ñ���Ӱ��ʵ�Σ���ַ�����෴
	printStudentByAddress(&s);
	cout << "name = " << s.name << " age = " << s.age << " score = " << s.score << endl;

	system("pause");
	return 0;
}