#include <iostream>
using namespace std;

const double PI = 3.14;

class Circle
{
public:int m_r;

	double calculateZC()
	{
		return 2 * PI*m_r;
	};
};


int main14()
{
	Circle cir;
	cir.m_r = 10;
	cout << "Ô²µÄÖÜ³¤£º" << cir.calculateZC() << endl;

	system("pause");
	return 0;
}