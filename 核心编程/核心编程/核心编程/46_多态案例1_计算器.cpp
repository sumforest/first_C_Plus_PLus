#include <iostream>
using namespace std;

// ��ͨʵ��
class Calculator
{
public:
	int getResult(string op)
	{
		if (op == "+")
		{
			return num1 + num2;
		}
		if (op == "-")
		{
			return num1 - num2;
		}
		if (op == "*")
		{
			return num1 * num2;
		}
		if (op == "/")
		{
			return num1 / num2;
		}
	};
	int num1;
	int num2;
};

void test_46_1()
{
	Calculator ca;
	ca.num1 = 10;
	ca.num2 = 10;
	cout << ca.num1 << " + " << ca.num2 <<" = "<< ca.getResult("+") << endl;
	cout << ca.num1 << " - " << ca.num2 << " = " << ca.getResult("-") << endl;
	cout << ca.num1 << " * " << ca.num2 << " = " << ca.getResult("*") << endl;
	cout << ca.num1 << " / " << ca.num2 << " = " << ca.getResult("/") << endl;
}

// ��̬ʵ�֣���������ߴ�ԭ��֮����ԭ�������޸Ĺرգ�������չ����
class AbstractCalculator
{
public:
	virtual int cal()
	{
		return 0;
	}

	int num1;
	int num2;
};

class AddCalculator:public AbstractCalculator
{
public:
	int cal()
	{
		return num1 + num2;
	}
};

class SubCalculator :public AbstractCalculator
{
public:
	int cal()
	{
		return num1 - num2;
	}
};

class MulCalCulator :public AbstractCalculator
{
public:
	int cal()
	{
		return num1 * num2;
	}
};

class DivCalCulator:public AbstractCalculator
{
public:
	int cal()
	{
		return num1 / num2;
	}
};

void test_46_2() 
{
	// ��̬�÷�������ָ������ã�ִ���������
	AbstractCalculator* p = new AddCalculator;
	p->num1 = 10;
	p->num2 = 10;
	cout << p->num1 << " + " << p->num2 << " = " << p->cal() << endl;

	p = new SubCalculator;
	p->num1 = 10;
	p->num2 = 10;
	cout << p->num1 << " - " << p->num2 << " = " << p->cal() << endl;

	p = new MulCalCulator;
	p->num1 = 10;
	p->num2 = 10;
	cout << p->num1 << " * " << p->num2 << " = " << p->cal() << endl;

	p = new DivCalCulator;
	p->num1 = 10;
	p->num2 = 10;
	cout << p->num1 << " / " << p->num2 << " = " << p->cal() << endl;
}

int main46()
{
	//test_46_1();
	test_46_2();

	system("pause");
	return 0;
}