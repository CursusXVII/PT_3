#ifndef _RIGHT_TRIANGLE_H_										
#define _RIGHT_TRIANGLE_H_										
#include "Square.h"

class Right_Triangle : public Square
{
private:
	double a, b;

public:
	Right_Triangle();
	Right_Triangle(double a, double b);
	Right_Triangle(const Right_Triangle& object);
	~Right_Triangle() {};

	void print() override;

	double function_square() override;						// Переопределённый метод volume()
	Right_Triangle& operator=(const Right_Triangle& object);
};
#endif // !_RIGHT_TRIANGLE_H_