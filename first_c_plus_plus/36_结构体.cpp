#include <iostream>
using namespace std;
#include <string>

struct Student
{
	string name;

	int age;

	int score;
}s3;

int main36()
{
	// �ṹ�崴����ʽ1,��c++�нṹ��Ĵ���stuct�ؼ��ֿ�ʡ��
	struct Student s1;
	s1.name = "����";
	s1.age = 20;
	s1.score = 100;
	cout << "name = " << s1.name << " age = " << s1.age << " score = " << s1.score << endl;

	// �����ṹ�巽ʽ2
	struct Student s2 = { "����",22 ,99 };
	cout << "name = " << s2.name << " age = " << s2.age << " score = " << s2.score << endl;

	// �����ṹ�巽ʽ3:�����ṹ��ʱ˳�㴴���ṹ�����
	s3.name = "����";
	s3.age = 21;
	s3.score = 88;
	cout << "name = " << s3.name << " age = " << s3.age << " score = " << s3.score << endl;

	system("pause");
	return 0;
}