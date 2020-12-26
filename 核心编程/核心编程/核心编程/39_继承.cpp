#include <iostream>
using namespace std;

class BasePage
{
public:
	void head()
	{
		cout << "页面的头部" << endl;
	}

	void footer()
	{
		cout << "页面的底部" << endl;
	}

	void  menu()
	{
		cout << "页面的左侧菜单栏" << endl;
	}
};

class Java :public BasePage
{
public:
	void content()
	{
		cout << "Java 页面内容" << endl;
	}
};

class Python :public BasePage
{
public:
	void content()
	{
		cout << "python 页面内容" << endl;
	}
};

void test_39()
{
	Java java;
	java.head();
	java.footer();
	java.menu();
	java.content();

	cout << "--------------------python-----------------" << endl;
	Python python;
	python.head();
	python.footer();
	python.menu();
	python.content();
}

int main39()
{
	test_39();

	system("pause");
	return 0;
}