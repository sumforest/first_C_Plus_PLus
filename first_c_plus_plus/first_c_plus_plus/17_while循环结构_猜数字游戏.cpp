#include <iostream>
using namespace std;
#include <ctime>

int main17()
{
	// 添加随机种子，利用当前系统时间生成随机数，防止每次生成随机数都一样
	srand((unsigned int)time(NULL));
	// 生成 1 - 100随机数
	int randNumb = rand() % 100 + 1;
	
	int input = 0;
	while (1)
	{
		cout << "请输入数字：" << endl;
		cin >> input;
		cout << endl;
		if (input > randNumb)
		{
			cout << "您猜测的数字大了" << endl;
		}
		else if (input < randNumb)
		{
			cout << "您猜测的数字小了" << endl;
		}
		else
		{
			cout << "恭喜您，猜对了！" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}