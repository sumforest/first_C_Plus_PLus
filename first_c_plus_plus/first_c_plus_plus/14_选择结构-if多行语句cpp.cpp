#include <iostream>
using namespace std;

int main14()
{
	// ���û������������������600����Ϊ����һ����ѧ�������һ����ѧ���������δ����һ����ѧ
	int score = 0;
	cout << "����������� " << endl;
	cin >> score;
	cout << "������ķ�����" << score << endl;

	if (score > 600)
	{
		cout << "��ϲ����һ����ѧ��" << endl;
	}
	else {
		cout << "���ź�����δ�ܿ���һ����ѧ" << endl;
	}

	system("pause");
	return 0;
}