#include "Rectanglle.h"

Rectanglle::Rectanglle()
{
	a = 0;
	b = 0;
}

Rectanglle::Rectanglle(double a, double b)	// Конструктор с параметрами
{
	this->b = b;
	this->a = a;
}

Rectanglle::Rectanglle(const Rectanglle& object)	// Конструктор копирования
{
	this->a = object.a;
	this->b = object.b;
}

void Rectanglle::print()
{
	std::cout << "a = " << a << ", b = " << b << ", S = " << function_square() << std::endl;
}

double Rectanglle::function_square()
{
	return a * b;
}

Rectanglle& Rectanglle::operator=(const Rectanglle& object)
{
	this->a = object.a;
	this->b = object.b;
	return *this;
}