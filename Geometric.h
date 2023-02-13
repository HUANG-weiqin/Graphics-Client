#pragma once
#include "Point.h"
using namespace std;
class Visitor;
class Geometric
{
/* 所有图形的父类，是一个抽象类定义了所有图形都需要实现的接口，
子类是 简单图形 GeomSimple 和 混合图形 GeomCompos
*/
public:
	virtual ~Geometric() {};
	virtual void accept(Visitor* v) = 0;
	virtual void moveBy(Vector2d& v) = 0;
	virtual void rotateBy(Point* pivot, float radian) = 0;
	virtual void zoomBy(Point* pivot, float factor) = 0;
	virtual float surface() = 0;
};