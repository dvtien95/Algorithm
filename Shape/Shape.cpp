#include "Shape.h"
#include <iostream>

using namespace std;

//accessor
int Shape::getX()
{
	return x;
}

int Shape::getY()
{
	return y;
}

// setor
void Shape::setX(int newx)
{
	x = newx;
}

void Shape::setY(int newy)
{
	y = newy;
}

// move the shape position
void Shape::moveTo(int newx, int newy)
{
	setX(newx);
	setY(newy);
}

void Shape::rMoveTo(int deltax, int deltay)
{
	moveTo(getX() + deltax, getY() + deltay);
}