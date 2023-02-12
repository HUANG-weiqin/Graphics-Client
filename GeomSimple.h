#pragma once
#include <vector>
#include "Point.h"
#include "Geometric.h"
#include <string>

using namespace std;
class Visitor;
class GeomSimple: public Geometric
{
public:
	virtual ~GeomSimple() 
	{
		for (Point* p : points) {
			delete p;
		}
	};
	virtual string toString() = 0;
	virtual void accept(Visitor* v) = 0;
protected:
	vector<Point *> points;
};