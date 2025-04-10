// Adir Edri 206991762

#include "Square.h"

Square::Square(double up, double down, double right, double left, const char* sn) :
	Quad(up, down, right, left, sn)
{
	
}
Square::~Square()
{
	
}
void Square::shiftX(int x)
{
	double newX = m_centerPoint.getX() + x;
	m_centerPoint.setX(newX);
}
void Square::shiftY(int y)
{
	double newY = m_centerPoint.getX() + y;
	m_centerPoint.setX(newY);
}