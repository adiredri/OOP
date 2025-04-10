// Adir Edri 206991762

#include "Point.h"

Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
}
Point::Point(const Point& other)
{
	this->m_x = other.m_x;
	this->m_y = other.m_y;
}
Point::~Point()
{
	
}
int Point::getX() const
{
	return m_x;
}
int Point::getY() const
{
	return m_y;
}
void Point::setX(int x)
{
	m_x = x;
}
void Point::setY(int y)
{
	m_y = y;
}
void Point::setPoint(int x, int y)
{
	m_x = x;
	m_y = y;
}
void Point::setPoint(const Point& other)
{
	m_x = other.m_x;
	m_y = other.m_y;
}
bool Point::operator==(const Point& other) const 
{
	if (m_x == other.m_x && m_y == other.m_y) 
	{
		return true;
	}
	return false;
}
bool Point::operator!=(const Point& other) const 
{
	return !(*this == other);
}
Point Point::operator+(int num) const 
{
	Point newPoint = Point(this->m_x + num, this->m_y + num);
	return newPoint;
}
const Point& Point::operator+=(int num) 
{
	this->m_x += num;
	this->m_y += num;
	return *this;
}
Point::operator int() const
{
	return (m_x + m_y);
}
Point Point::operator+(const Point& other) const
{
	return Point(m_x + other.m_x, m_y + other.m_y);
}
Point Point::operator++(int)
{
	Point original(m_x, m_y);
	m_x += 1;
	m_y += 1;
	return original;
}
const Point& Point::operator++() 
{
	this->m_x += 1;
	this->m_y += 1;
	return *this;
}
Point operator*(int num, const Point& other)
{
	return Point(num * other.m_x, num * other.m_y);
}
