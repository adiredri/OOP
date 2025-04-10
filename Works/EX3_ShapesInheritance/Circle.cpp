// Adir Edri 206991762

#include "Circle.h"

Circle::Circle(double r, const char* sn) : Shape(sn)
{
	m_radius = r;
}
Circle::Circle(const Circle& other)
{
	this->m_radius = other.m_radius;
	this->m_centerPoint = Point(other.m_centerPoint);
}
Circle::~Circle()
{
	
}
double Circle::getRadius() const 
{
	return m_radius;
}
void Circle::setRadius(double r)
{
	m_radius = r;
}
int Circle::calcArea() const
{
	return (PI * m_radius * m_radius);
}
int Circle::calcPerimeter() const
{
	return (PI * 2 * m_radius);
}
Circle operator+(int r, const Circle& other)
{
	Circle newCircle = Circle(other);
	newCircle.m_radius += r;
	return newCircle;
}
const Circle& Circle::operator=(const Circle& other)
{
	this->m_radius = other.getRadius();
	this->setCenter(other.getCenter());
	this->setName(other.getName());
	return *this;
}
const Circle& Circle::operator=(const char* name)
{
	setName(name);
	return *this;
}