#include <iostream>
using namespace std;

class BasePage
{
public:
	void head()
	{
		cout << "ҳ���ͷ��" << endl;
	}

	void footer()
	{
		cout << "ҳ��ĵײ�" << endl;
	}

	void  menu()
	{
		cout << "ҳ������˵���" << endl;
	}
};

class Java :public BasePage
{
public:
	void content()
	{
		cout << "Java ҳ������" << endl;
	}
};

class Python :public BasePage
{
public:
	void content()
	{
		cout << "python ҳ������" << endl;
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