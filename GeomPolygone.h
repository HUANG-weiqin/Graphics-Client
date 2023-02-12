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
};