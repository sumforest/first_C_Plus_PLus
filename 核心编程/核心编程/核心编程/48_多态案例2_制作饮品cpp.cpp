#include <iostream>
using namespace std;

class AstractDrink
{
public:
	// ��ˮ
	virtual void boil() = 0;
	// ����
	virtual void brew() = 0;
	// ���뱭��
	virtual void pour() = 0;
	// ����
	virtual void charge() = 0;

	void makeDirnk()
	{
		boil();
		brew();
		pour();
		charge();
	}
};

class Coffee :public AstractDrink
{
public:
	virtual void boil()
	{
		cout << "��ж���ɽȪ" << endl;
	}

	virtual void brew()
	{
		cout << "����ж���ɽȪ�������ݿ���" << endl;
	}

	virtual void pour()
	{
		cout << "�ѳ��ݺõĿ��ȵ��뱭��" << endl;
	}

	virtual void charge()
	{
		cout << "����ţ��" << endl;
	}
};

void doDrinking(AstractDrink* abs)
{
	abs->makeDirnk();
	// �ͷ��ڴ�
	delete abs;
}

void test_48()
{
	doDrinking(new Coffee);
}

int main48()
{
	test_48();

	system("pause");
	return 0;
}