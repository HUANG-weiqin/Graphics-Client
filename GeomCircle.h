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
private:
	Point* center;
	int radius;
};