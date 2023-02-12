#pragma once
#include "Geometric.h"
#include <vector>

using namespace std;
class Visitor;
class GeomCompos : public Geometric
{
public:
	virtual ~GeomCompos();
	virtual void accept(Visitor* v);
	virtual void add(Geometric* g);
private:
	vector<Geometric * > geoms;
};
