#include <iostream>
using namespace std;

class Person_36
{
public:
	Person_36(int a)
	{
		age = new int(a);
	}

	// 析构函数释放内存
	~Person_36()
	{
		if (age != NULL)
		{
			delete age;
			age = NULL;
		}
	}

	Person_36& operator=(Person_36 &p)
	{
		// 赋值之前判断当前的age是否已经分配内存，若分配了内存先释放
		if (age != NULL)
		{
			delete age;
			age = NULL;
		}

		// 深拷贝
		age = new int(*p.age);
		return *this;
	}
	
	int *age;
};

void test_36()
{
	Person_36 p1(18);
	Person_36 p2(20);

	p1 = p2;

	cout << "p1的年龄 = " << *p1.age << endl;
	cout << "p2的年龄 = " << *p2.age << endl;
}

int main36()
{
	test_36();

	system("pause");
	return 0;
}