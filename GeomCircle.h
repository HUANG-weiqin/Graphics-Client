#pragma once
#include <vector>
#include "Point.h"
#include "GeomSimple.h"
#include <string>
#include <sstream>
class Visitor;
class GeomCircle : public GeomSimple
{
/* 简单图形 中的 圆形，包含一个圆心，和半径radius
*/
public:
	GeomCircle(float x, float y, float r);
	virtual string toString();
	virtual void accept(Visitor* v);
	virtual float surface() { return 3.14 * radius * radius; }
	virtual void zoomBy(Point* pivot, float factor)
	{
		GeomSimple::zoomBy(pivot, factor);
		radius *= factor;
	}
private:
	Point* center;
	float radius;
};