#include <iostream>
using namespace std;

class Animal_45
{
public:
	// ���ຯ����virtual����,��ʱspeak������̬�󶨡�
	// ��̬��������
	// 1.���м̳й�ϵ
	// 2.������д����ĺ���

	//��̬��̬��ʹ��
	// �����ָ������ã�ִ���������
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};

class Cat_45 :public Animal_45
{
public:
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};

void doSpeak(Animal_45 &animal)
{
	// ����Animal_45�к����Ǿ�̬�󶨵ģ�����һ��һֱִ�и���ķ���
	animal.speak();
}

void test_45()
{
	Cat_45 cat;
	doSpeak(cat);
}

int main45()
{
	test_45();

	system("pause");
	return 0;
}