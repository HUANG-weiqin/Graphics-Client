#pragma once
#include "Point.h"
using namespace std;
class Visitor;
class Geometric
{
public:
	virtual ~Geometric() {};
	virtual void accept(Visitor* v) = 0;
	virtual void moveBy(Vector2d& v) = 0;
	virtual void rotateBy(Point* pivot, float radian) = 0;
	virtual void zoomBy(Point* pivot, float factor) = 0;
	virtual float surface() = 0;
};