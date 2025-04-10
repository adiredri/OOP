// Adir Edri 206991762

#include "Quad.h"

Quad::Quad(double up, double down, double right, double left, const char* sn) :
	m_up(up), m_down(down), m_right(right), m_left(left), Shape(sn)
{
	m_centerPoint = Point(0, 0);
}
Quad::Quad(const Quad& other)
{
	this->m_down = other.m_down;
	this->m_left = other.m_left;
	this->m_right = other.m_right;
	this->m_up = other.m_up;
}
Quad::~Quad()
{

}
int Quad::calcArea() const
{
	return (m_up * m_right);
}
int Quad::calcPerimeter() const
{
	return (m_up + m_right + m_down + m_left);
}


