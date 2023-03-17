#include "GeomPolygone.h"
#include "Visitor.h"
void GeomPolygone::accept(Visitor* v) {
	v->visit(this);
}

GeomPolygone::GeomPolygone(vector<float>& pts) {
	for (int i = 0; i < pts.size(); i += 2) {
		float x = pts[i];
		float y = pts[i + 1];
		points.push_back(new Point(x, y));
	}
};

string GeomPolygone::toString() {
	stringstream ss;
	for (Point* pt : points) {
		ss <<pt->toString()<<" ";
	}
	ss << GeomSimple::toString()<<endl;
	return ss.str();
}
