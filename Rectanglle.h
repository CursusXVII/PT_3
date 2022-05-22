#ifndef _RECTANGLLE_H_										
#define _RECTANGLLE_H_										
#include "Square.h"

class Rectanglle : public Square
{
private:
	double a, b;

public:
	Rectanglle();
	Rectanglle(double a, double b);
	Rectanglle(const Rectanglle& object);
	~Rectanglle() {};

	void print() override;

	double function_square() override;						// Переопределённый метод volume()
	Rectanglle& operator=(const Rectanglle& object);
};
#endif // !_RECTANGLLE_H_