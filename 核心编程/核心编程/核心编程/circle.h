#pragma once
#include <iostream>
using namespace std;

#include "point.h"

class Circle
{
public:
	void setM_r(int r);
	int getM_r();

	void setCenter(Point point);
	Point getCenter();

private:
	int m_r;

	Point center;
};
