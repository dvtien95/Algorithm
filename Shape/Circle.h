#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle: public Shape
{
public:
	Circle(int newx, int newy, int newradius);
	int getRadius();
	void setRadius(int newradius);
	void draw() override;
	~Circle();

private:
	int radius;
};

#endif // CIRCLE_H
