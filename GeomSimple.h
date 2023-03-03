#pragma once
#include <vector>
#include "Point.h"
#include "Geometric.h"
#include <string>

using namespace std;
class Visitor;
class GeomSimple: public Geometric
{
/* ��ͼ�Σ�����ͼ��GeomCompos��ԣ���ͼ�ξ���һ��������ͼ�Σ�����Բ�Σ������Σ�����Σ�������
* ���Ƕ��̳��ڸ��࣬move rotate �� zoom ��������ֱ�������� �������ж�����
*/
public:
	virtual ~GeomSimple() 
	{
		for (Point* p : points) {
			delete p;
		}
	};
	virtual string toString() {
		stringstream ss;
		ss << r << " " << g <<" "<< b;
		return ss.str();
	};
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

	virtual void addPoint(Point* p)
	{
		points.push_back(p);
	}

	virtual float surface() = 0;

	void setColor(int rr, int gg, int bb) {
		r = rr;
		g = gg;
		b = bb;
	}

protected:
	vector<Point *> points; //��ͼ�ε� ���㼯�ϣ�Բ�εĶ�����Բ�ģ������������˵�ȵ�
	int r = 0;
	int g = 0;
	int b = 0;
};