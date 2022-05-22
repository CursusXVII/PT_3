#ifndef _TRAPEZOID_H_										
#define _TRAPEZOID_H_										
#include "Square.h"

class Trapezoid : public Square
{
private:
	double a, b, h;

public:
	Trapezoid();
	Trapezoid(double a, double b, double h);
	Trapezoid(const Trapezoid& object);
	~Trapezoid() {};

	void print() override;

	double function_square() override;						// Переопределённый метод volume()
	Trapezoid& operator=(const Trapezoid& object);
};
#endif