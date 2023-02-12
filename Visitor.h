#pragma once
#include "GeomCompos.h"
#include "GeomCircle.h"
#include "GeomPolygone.h"
#include "GeomLine.h"
class Visitor
{
public:	
	virtual void visit(GeomCircle * geom) = 0;
	virtual void visit(GeomCompos * geom) = 0;
	virtual void visit(GeomPolygone * geom) = 0;
	virtual void visit(GeomLine* geom) = 0;

};
