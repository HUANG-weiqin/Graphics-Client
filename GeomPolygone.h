#pragma once
#include <vector>
#include "Point.h"
#include "GeomSimple.h"
#include <string>
#include <sstream>
class Visitor;
class GeomPolygone : public GeomSimple
{
public:
	GeomPolygone(vector<int> &v);
	virtual string toString();
	virtual void accept(Visitor* v);
	virtual float surface() { 
		// S = 1/2 * [(x1y2-x2y1)+(x2y3-x3y2)+(x3y1-x1y3)]
		if (points.size() < 3)
			return 0;
		float res = 0;
		Point* first = points[0];
		float x1 = first->getX();
		float y1 = first->getY();
		for (int i = 2; i < points.size(); ++i) {
			float x2 = points[i]->getX();
			float y2 = points[i]->getY();
			float x3 = points[i-1]->getX();
			float y3 = points[i-1]->getY();
			res += x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3;
		}
		return res/2; 
	}
};