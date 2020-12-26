#include "circle.h"

void Circle::setCenter(Point p)
{	
	center = p;
}

Point Circle::getCenter()
{
	return center;
}

void Circle::setM_r(int r)
{
	m_r = r;
}

int Circle::getM_r()
{
	return m_r;
}
