// Adir Edri 206991762

#include "allShapes.h"
#include "Circle.h"
#include "Quad.h"
#include "Square.h"

allShapes::allShapes()
{
	m_arr = nullptr;
	m_size = 0;
}
allShapes::allShapes(const allShapes& other)
{
	this->m_size = other.m_size;
	this->m_arr = new Shape * [other.m_size];
	for (int i = 0; i < other.m_size; i++)
	{
		if (dynamic_cast<Quad*>(other.m_arr[i])) {
			this->m_arr[i] = new Quad(*dynamic_cast<Quad*>(other.m_arr[i]));
		}
		else if (dynamic_cast<Square*>(other.m_arr[i])) {
			this->m_arr[i] = new Square(*dynamic_cast<Square*>(other.m_arr[i]));
		}
		else if (dynamic_cast<Circle*>(other.m_arr[i])) {
			this->m_arr[i] = new Circle(*dynamic_cast<Circle*>(other.m_arr[i]));
		}
	}
}

allShapes::~allShapes()
{
	delete[] m_arr;
}
int allShapes::getSize() const
{
	return m_size;
}
void allShapes::addShape(Shape* newShape)
{
	Shape** newArr = new Shape * [m_size + 1];

	for (int i = 0; i < this->m_size; i++) {
		newArr[i] = this->m_arr[i];
	}

	if (dynamic_cast<Quad*>(newShape)) {
		Quad* shape2 = dynamic_cast<Quad*>(newShape);
		newArr[m_size] = shape2;
	}
	if (dynamic_cast<Square*>(newShape)) {
		Square* shape2 = dynamic_cast<Square*>(newShape);
		newArr[m_size] = shape2;
	}
	if (dynamic_cast<Circle*>(newShape)) {
		Circle* shape2 = dynamic_cast<Circle*>(newShape);
		newArr[m_size] = shape2;
	}

	delete[] this->m_arr;
	this->m_arr = newArr;
	this->m_size++;
}
void allShapes::removeShape(int index)
{
	delete m_arr[index];
	for (int i = index; i < m_size - 1; i++)
	{
		m_arr[i] = m_arr[i + 1];
	}
	m_size--;
}
int allShapes::totalArea() const
{
	int total = 0;
	for (int i = 0; i < m_size; i++)
	{
		if (typeid(*m_arr[i]) == typeid(Square)) {
			Square* shape1 = static_cast<Square*>(m_arr[i]);
			total += shape1->calcArea();
		}

		if (typeid(*m_arr[i]) == typeid(Quad)) {
			Quad* shape1 = static_cast<Quad*>(m_arr[i]);
			total += shape1->calcArea();
		}
		if (typeid(*m_arr[i]) == typeid(Circle)) {
			Circle* shape2 = static_cast<Circle*>(m_arr[i]);
			total += shape2->calcArea();
		}
	}
	return total;
}
int allShapes::totalPerimeter() const {
	int total = 0;
	for (int i = 0; i < m_size; i++)
	{
		if (typeid(*m_arr[i]) == typeid(Square)) {
			Square* shape1 = static_cast<Square*>(m_arr[i]);
			total += shape1->calcPerimeter();
		}

		if (typeid(*m_arr[i]) == typeid(Quad)) {
			Quad* shape1 = static_cast<Quad*>(m_arr[i]);
			total += shape1->calcPerimeter();
		}
		if (typeid(*m_arr[i]) == typeid(Circle)) {
			Circle* shape2 = static_cast<Circle*>(m_arr[i]);
			total += shape2->calcPerimeter();
		}
	}
	return total;
}
int allShapes::totalCircleArea() const
{
	int total = 0;
	for (int i = 0; i < m_size; i++)
	{
		if (dynamic_cast<Circle*>(m_arr[i]))
		{
			Circle* shape2 = dynamic_cast<Circle*>(m_arr[i]);
			total += shape2->calcArea();
		}
	}
	return total;
}
int allShapes::totalSquarePerimeter() const
{
	int total = 0;
	for (int i = 0; i < m_size; i++)
	{
		if (dynamic_cast<Square*>(m_arr[i]))
		{
			Square* shape1 = dynamic_cast<Square*>(m_arr[i]);
			total += shape1->calcPerimeter();
		}
	}
	return total;
}
const allShapes& allShapes::operator+=(Shape* newS)
{
	addShape(newS);
	return *this;
}
Shape* allShapes::operator[](int ind) const
{
	if (ind < 0 || ind >= m_size)
	{
		return nullptr;
	}
	return m_arr[ind];
}
allShapes allShapes::operator+(const allShapes& other) const
{
	allShapes result;
	for (int i = 0; i < m_size; i++)
	{
		result.addShape(m_arr[i]);
	}
	for (int i = 0; i < other.m_size; i++)
	{
		result.addShape(other.m_arr[i]);
	}
	return result;
}
allShapes::operator int() const
{
	return m_size;
}
