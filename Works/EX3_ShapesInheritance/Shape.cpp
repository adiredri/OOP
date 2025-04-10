// Adir Edri 206991762

#include "Shape.h"

int Shape::s_totalNumOfShapes = 0;

Shape::Shape(const char* sn)
{
	m_shapeName = new char[strlen(sn) + 1];
	strcpy(m_shapeName, sn);
	s_totalNumOfShapes++;
	m_centerPoint = Point(0, 0);
}
Shape::Shape(const Shape& other)
{	
	m_shapeName = new char[strlen(other.m_shapeName) + 1];
	strcpy(m_shapeName, other.m_shapeName);
	m_centerPoint = Point(other.m_centerPoint);
	s_totalNumOfShapes = other.s_totalNumOfShapes;
}
Shape::~Shape()
{
	delete[] m_shapeName;
	s_totalNumOfShapes--;
}
void Shape::setName(const char* name)
{
	delete[] m_shapeName;
	m_shapeName = new char[strlen(name) + 1];
	strcpy(m_shapeName, name);
}
void Shape::setCenter(const Point& p)
{
	m_centerPoint = Point(p);
}
const char* Shape::getName() const
{
	return m_shapeName;
}
Point Shape::getCenter() const
{
	return m_centerPoint;
}
void Shape::setShape(const char* sn, const Point& other)
{
	delete[] m_shapeName;
	m_shapeName = new char[strlen(sn) + 1];
	strcpy(m_shapeName, sn);
	m_centerPoint = Point(other);
}
int Shape::numOfShapes()
{
	return s_totalNumOfShapes;
}
const Shape& Shape::operator=(const Shape& other)
{
	delete[] m_shapeName;
	m_shapeName = new char[strlen(other.m_shapeName) + 1];
	strcpy(m_shapeName, other.m_shapeName);
	s_totalNumOfShapes = other.s_totalNumOfShapes;
	m_centerPoint = Point(other.m_centerPoint);
	return *this;
}
