#include "GeomPolygone.h"
#include "Visitor.h"
void GeomPolygone::accept(Visitor* v) {
	v->visit(this);
}

GeomPolygone::GeomPolygone(vector<int>& pts) {
	for (int i = 0; i < pts.size(); i += 2) {
		int x = pts[i];
		int y = pts[i + 1];
		points.push_back(new Point(x, y));
	}
};

string GeomPolygone::toString() {
	stringstream ss;
	for (Point* pt : points) {
		ss <<pt->toString()<<" ";
	}
	return ss.str();
}