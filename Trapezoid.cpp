#include "Trapezoid.h"

Trapezoid::Trapezoid()
{
	a = 0;
	b = 0;
	h = 0;
}

Trapezoid::Trapezoid(double a, double b, double h)	// Конструктор с параметрами
{
	this->h = h;
	this->b = b;
	this->a = a;
}

Trapezoid::Trapezoid(const Trapezoid& object)	// Конструктор копирования
{
	this->a = object.a;
	this->b = object.b;
	this->h = object.h;
}

void Trapezoid::print()
{
	std::cout << "a = " << a << ", b = " << b << ", h = " << h << ", S = " << function_square() << std::endl;
}

double Trapezoid::function_square()
{
	return h/2 * (a + b);
}

Trapezoid& Trapezoid::operator=(const Trapezoid& object)
{
	this->a = object.a;
	this->b = object.b;
	this->h = object.h;
	return *this;
}