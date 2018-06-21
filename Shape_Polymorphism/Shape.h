#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
	int getX();
	int getY();
	void setX(int newx);
	void setY(int newY);
	void moveTo(int newx, int newy);
	void rMoveTo(int deltax, int deltay);
	virtual void draw() = 0;

private:
	int x;	// x-coordinate of center point
	int y;	// y-coordinate of center point
};
#endif // SHAPE_H
