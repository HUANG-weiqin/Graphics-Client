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
	virtual void moveBy(Vector2d& v) 
	{
		for (Point* p : points) {
			p->moveBy(v);
		}
	}
	virtual void rotateBy(Point* pivot, float radian) 
	{
		for (Point* p : points) {
			p->rotateBy(pivot, radian);
		}
	}
	virtual void zoomBy(Point* pivot, float factor)
	{
		for (Point* p : points) {
			p->zoomBy(pivot,factor);
		}
	}
protected:
	vector<Point *> points;
};