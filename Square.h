#ifndef _SQUARE_H_		
#define _SQUARE_H_

#include <iostream>
#include <cmath>

class Square
{
protected:
	double x;

public:
	Square() { 
		x = 0; 
	};
	virtual ~Square() {};

	virtual void print() = 0;			

	virtual double function_square() = 0;	
};
#endif // !_SQUARE_H_