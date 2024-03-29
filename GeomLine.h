#pragma once
#include <vector>
#include "Point.h"
#include "GeomSimple.h"
#include <string>
#include <sstream>
class Visitor;
class GeomLine : public GeomSimple
{
/* 简单图形 中的 线段，由两个端点组成，面积为0
*/
public:
	GeomLine(float x1, float y1, float x2, float y2);
	virtual string toString();
	virtual void accept(Visitor* v);
	virtual float surface() { return 0; }
private:
	Point* p1;
	Point* p2;
};