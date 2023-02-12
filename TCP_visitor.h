#pragma once
#include "Visitor.h"

class TCP_visitor : public Visitor
{
public:
	virtual void visit(GeomCircle* geom);
	virtual void visit(GeomCompos* geom);
	virtual void visit(GeomPolygone* geom);
	virtual void visit(GeomLine* geom);
	void sendTcpReqest(const char * cmd,GeomSimple* geom);
};
