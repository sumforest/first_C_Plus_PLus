#include <iostream>
using namespace std;

int main13()
{
	// 让用户输入分数，分数大于600分视为考上一本大学
	int score = 0;
	cout << "请输入分数: " << endl;
	// 获取键盘输入的分数
	cin >> score;
	cout <<"您输入的分数：" <<   score << endl;
	if (score > 600)
	{
		cout << "恭喜您考上了一本大学！" << endl;
	}
	system("pause");
	return 0;
}