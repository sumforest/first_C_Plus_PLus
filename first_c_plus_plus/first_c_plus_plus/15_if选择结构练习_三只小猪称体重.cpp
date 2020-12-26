#include <iostream>
using namespace std;
int main15()
{
	// 输入三只小猪的体重使用if-else语句找出体重最中的
	int a = 0;
	int b = 0;
	int c = 0;
	cout << "请输入小猪A的体重：" << endl;
	cin >> a;
	cout << "请输入小猪B的体重：" << endl;
	cin >> b;
	cout << "请输入小猪C的体重：" << endl;
	cin >> c;
	cout <<  endl;

	cout << "小猪A的体重：" << a<< endl;
	cout << "小猪B的体重：" << b<<endl;
	cout << "小猪C的体重：" << c << endl;
	cout << endl;

	if (a > b)
	{
		if (a > c)
		{
			cout << "小猪A最重" << endl;
		}
		else
		{
			cout << "小猪C最重" << endl;
		}
	}
	else
	{
		if (b > c)
		{
			cout << "小猪B最重" << endl;
		}
		else
		{
			cout << "小猪C重" << endl;
		}
	}

	system("pause");
	return 0;
}