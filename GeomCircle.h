#pragma once
#include <vector>
#include "Point.h"
#include "GeomSimple.h"
#include <string>
#include <sstream>
class Visitor;
class GeomCircle : public GeomSimple
{
public:
	GeomCircle(int x, int y, int r);
	virtual string toString();
	virtual void accept(Visitor* v);
	virtual float surface() { return 3.14 * radius * radius; }
private:
	Point* center;
	int radius;
};