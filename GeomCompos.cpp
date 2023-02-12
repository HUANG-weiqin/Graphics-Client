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