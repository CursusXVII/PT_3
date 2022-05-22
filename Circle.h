#ifndef _CIRCLE_H_										
#define _CIRCLE_H_										
#include "Square.h"

class Circle : public Square
{
private:
	double r;

public:
	Circle();
	Circle(double r);
	Circle(const Circle& object);
	~Circle() {};

	void print() override;

	double function_square() override;						// Переопределённый метод volume()
	Circle& operator=(const Circle& object);
};
#endif // !_CIRCLE_H_