#pragma once
#include <string>
#include <sstream>
#include "Vector2d.h"
using namespace std;
class Point
{
private:
	int x = 0;
	int y = 0;
	Vector2d vectorTo(Point* other) {
		return Vector2d(other->x - x, other->y - y);
	}
public:
	Point(int xx, int yy) {
		x = xx;
		y = yy;
	};
	int getX() { return x; };
	int getY() { return y; };
	int setX(int newx) { x = newx; };
	int setY(int newy) { y = newy; };
	string toString() 
	{
		stringstream ss;
		ss << x <<" "<< y;
		return ss.str();
	};


	void moveBy(Vector2d & v) {
		x += v.x;
		y += v.y;
	}

	void rotateBy(Point *pivot,float radian) {
		Vector2d v = pivot->vectorTo(this).Rotate(radian);
		x = pivot->x + v.x;
		y = pivot->y + v.y;
	}

	void zoomBy(Point* pivot,float factor) {
		Vector2d v = pivot->vectorTo(this) * factor;
		x = pivot->x + v.x;
		y = pivot->y + v.y;
	}
};