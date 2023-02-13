#include "GeomCompos.h"
#include "Visitor.h"
GeomCompos::~GeomCompos() {
	for (Geometric* g : geoms) {
		delete g;
	}
};
void GeomCompos::accept(Visitor* v) {

	for (Geometric * g : geoms) {
		g->accept(v);
	}
}

void GeomCompos::add(Geometric * g) {
	geoms.push_back(g);
}

void GeomCompos::moveBy(Vector2d& v) {
	for (Geometric* g : geoms) {
		g->moveBy(v);
	}
}
void GeomCompos::rotateBy(Point* pivot, float radian) {
	for (Geometric* g : geoms) {
		g->rotateBy(pivot, radian);
	}
}
void GeomCompos::zoomBy(Point* pivot, float factor) {
	for (Geometric* g : geoms) {
		g->zoomBy(pivot, factor);
	}
}

float GeomCompos::surface() {
	float res = 0;
	for (Geometric* g : geoms) {
		res += g->surface();
	}
	return res;
}