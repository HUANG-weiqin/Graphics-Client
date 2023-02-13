#pragma once
#include <vector>
#include "Point.h"
#include "Geometric.h"
#include <string>

using namespace std;
class Visitor;
class GeomSimple: public Geometric
{
/* 简单图形，与混合图形GeomCompos相对，简单图形就是一个真正的图形，比如圆形，三角形，多边形，线条等
* 他们都继承于该类，move rotate 和 zoom 操作都是直接作用于 它的所有顶点上
*/
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

	virtual float surface() = 0;

protected:
	vector<Point *> points; //简单图形的 顶点集合，圆形的顶点是圆心，线条是两个端点等等
};