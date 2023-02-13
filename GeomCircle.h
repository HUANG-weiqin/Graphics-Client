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
	GeomCircle(int x, int y, int r);
	virtual string toString();
	virtual void accept(Visitor* v);
	virtual float surface() { return 3.14 * radius * radius; }
private:
	Point* center;
	int radius;
};