#include "Circle.h"

Circle::Circle()
{
	r = 0;
}

Circle::Circle(double r)	// Конструктор с параметрами
{
	this->r= r;
}

Circle::Circle(const Circle& object)	// Конструктор копирования
{
	this->r = object.r;

}

void Circle::print()
{
	std::cout << "r = " << r << ", S = " << function_square() << std::endl;
}

double Circle::function_square()
{
	return 3.1415 * r * r;
}

Circle& Circle::operator=(const Circle& object)
{
	this->r = object.r;

	return *this;
}
