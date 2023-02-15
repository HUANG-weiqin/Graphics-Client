#include "GeomCircle.h"
#include "Visitor.h"
void GeomCircle::accept(Visitor* v) {
	v->visit(this);
}

GeomCircle::GeomCircle(int x, int y, int r) {
	this->center = new Point(x, y);
	points.push_back(this->center);
	radius = r;
};

string GeomCircle::toString() {
	stringstream ss;
	ss <<center->toString() << " " << radius << endl;
	return ss.str();
}
