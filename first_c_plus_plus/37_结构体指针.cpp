#include <iostream>
using namespace std;
#include <string>

struct Student
{
	string name;

	int age;

	int score;
};

int main37()
{
	Student s1 = { "ÕÅÈı",22,100 };

	Student *p = &s1;

	cout << "name = " << p->name << " age = " << p->age << " score = " << p->score << endl;

	system("pause");
	return 0;
}