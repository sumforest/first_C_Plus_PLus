#include  <iostream>
using namespace std;

class Animal 
{
public:
	int m_age;
};

// virtual��̳У�ʹ����̳к������Ӵ���һ����ͬ�ı���
class Sheep :virtual public Animal
{

};

class Tuo :virtual public Animal
{

};

class SheepTuo:public Sheep,public Tuo
{

};

void test_44()
{
	SheepTuo st;
	//���⣺1. ���μ̳д��ڶ�����
	//st.m_age;
	st.Sheep::m_age = 18;
	st.Tuo::m_age = 28;
	
	// ���⣺ ���μ̳������������������ͬ�ı������˷���Դ���Ҿ�������
	// ����취�� ʹ����̳�
	cout << "���յ����� = " << st.m_age << endl;
}

int main44()
{
	test_44();

	system("pause");
	return 0;
}