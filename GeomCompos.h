#pragma once
#include "Geometric.h"
#include <vector>

using namespace std;
class Visitor;
class GeomCompos : public Geometric
{
public:
	virtual ~GeomCompos();
	virtual void accept(Visitor* v);
	virtual void add(Geometric* g);
	virtual void moveBy(Vector2d& v);
	virtual void rotateBy(Point* pivot, float radian);
	virtual void zoomBy(Point* pivot, float factor);
private:
	vector<Geometric * > geoms;
};
