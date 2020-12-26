#include <iostream>
using namespace std;
#include "point.h"
#include "circle.h"

void getPosition(Circle c, Point point)
{
	int distance = (point.getM_x() - c.getCenter().getM_x())*(point.getM_x() - c.getCenter().getM_x()) + (point.gettM_y() 
		- c.getCenter().gettM_y())*(point.gettM_y() - c.getCenter().gettM_y());
	if (c.getM_r()*c.getM_r() == distance)
	{
		cout << "点在圆上" << endl;
	}
	else if (distance > c.getM_r()*c.getM_r())
	{
		cout << "在圆外" << endl;
	}
	else {
		cout << "在圆内" << endl;
	}
}

int main17()
{
	Point center;
	center.setM_x(10) ;
	center.setM_y(0) ;
	Circle c;
	c.setM_r(10);
	c.setCenter(center) ;

	Point p;
	p.setM_x (20);
	p.setM_y(0);

	getPosition(c, p);

	system("pause");
	return 0;
}
