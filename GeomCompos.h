#pragma once
#include "Geometric.h"
#include <vector>

using namespace std;
class Visitor;
class GeomCompos : public Geometric
{
/* 混合图形 与 简单图形相对，它是由多个简单图形或者 混合图形组合成的图形集合，就把他当作一个集合就好了
* 当 move rotate 和zoom 被应用在他身上的时候，其实就是应用在所有在它内部的图形上，面积就是所有图形面积之和
*/
public:
	virtual ~GeomCompos();
	virtual void accept(Visitor* v);
	virtual void add(Geometric* g);
	virtual void moveBy(Vector2d& v);
	virtual void rotateBy(Point* pivot, float radian);
	virtual void zoomBy(Point* pivot, float factor);
	virtual float surface();
	virtual string toString();
private:
	vector<Geometric * > geoms;
};
