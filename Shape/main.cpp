#include "Circle.h"
#include "Rectangle.h"
#include <iostream>

using namespace std;

int main(void)
{
	Rectangle c(3,4,5,6);
	
	Shape *pp = &c;	// Make a pointer point to c
	cout << pp->getX() << endl;
	cout << pp->getY() << endl;
	
	c.draw();
}