#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle: public Shape
{
public:
	Rectangle(int newx, int newy, int newwidth, int newheight);
	int getWidth();
	int getHeight();
	void setWidth(int newwidth);
	void setHeight(int newheight);
	void draw() override;
	~Rectangle();

private:
	int width;
	int height;
};

#endif // RECTANGLE_H
