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
	// 结构体创建方式1,在c++中结构体的创建stuct关键字可省略
	struct Student s1;
	s1.name = "张三";
	s1.age = 20;
	s1.score = 100;
	cout << "name = " << s1.name << " age = " << s1.age << " score = " << s1.score << endl;

	// 创建结构体方式2
	struct Student s2 = { "李四",22 ,99 };
	cout << "name = " << s2.name << " age = " << s2.age << " score = " << s2.score << endl;

	// 创建结构体方式3:声明结构体时顺便创建结构体变量
	s3.name = "王五";
	s3.age = 21;
	s3.score = 88;
	cout << "name = " << s3.name << " age = " << s3.age << " score = " << s3.score << endl;

	system("pause");
	return 0;
}