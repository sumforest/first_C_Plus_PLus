#include <iostream>
using namespace std;
#include <ctime>

int main17()
{
	// ���������ӣ����õ�ǰϵͳʱ���������������ֹÿ�������������һ��
	srand((unsigned int)time(NULL));
	// ���� 1 - 100�����
	int randNumb = rand() % 100 + 1;
	
	int input = 0;
	while (1)
	{
		cout << "���������֣�" << endl;
		cin >> input;
		cout << endl;
		if (input > randNumb)
		{
			cout << "���²�����ִ���" << endl;
		}
		else if (input < randNumb)
		{
			cout << "���²������С��" << endl;
		}
		else
		{
			cout << "��ϲ�����¶��ˣ�" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}