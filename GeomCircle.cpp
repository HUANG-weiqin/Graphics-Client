#include "GeomCircle.h"
#include "Visitor.h"
void GeomCircle::accept(Visitor* v) {
	v->visit(this);
}

GeomCircle::GeomCircle(float x, float y, float r) {
	this->center = new Point(x, y);
	points.push_back(this->center);
	radius = r;
};

string GeomCircle::toString() {
	stringstream ss;
	ss <<center->toString() << " " << radius << " "<< GeomSimple::toString() <<endl;
	return ss.str();
}
