#include "Right_Triangle.h"

Right_Triangle::Right_Triangle()
{
	a = 0;
	b = 0;
}

Right_Triangle::Right_Triangle(double a, double b)	// Конструктор с параметрами
{
	this->b = b;
	this->a = a;
}

Right_Triangle::Right_Triangle(const Right_Triangle& object)	// Конструктор копирования
{
	this->a = object.a;
	this->b = object.b;
}

void Right_Triangle::print()
{
	std::cout << "a = " << a << ", b = " << b << ", S = " << function_square() << std::endl;
}

double Right_Triangle::function_square()
{
	return (a * b) / 2;
}

Right_Triangle& Right_Triangle::operator=(const Right_Triangle& object)
{
	this->a = object.a;
	this->b = object.b;
	return *this;
}