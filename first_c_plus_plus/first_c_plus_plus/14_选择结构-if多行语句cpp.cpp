#include <iostream>
using namespace std;

int main14()
{
	// 让用户输入分数，分数大于600分视为考上一本大学输出考上一本大学；否则输出未考上一本大学
	int score = 0;
	cout << "请输入分数： " << endl;
	cin >> score;
	cout << "您输入的分数：" << score << endl;

	if (score > 600)
	{
		cout << "恭喜考入一本大学！" << endl;
	}
	else {
		cout << "很遗憾，您未能考入一本大学" << endl;
	}

	system("pause");
	return 0;
}