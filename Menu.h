#pragma once
#include "GeomCompos.h"
#include "Visitor.h"
class Menu
{

private:
	GeomCompos* G;
	Visitor* V;
	void createCircle();
	void createPolygone();
	void createLine();
	void move();
	void rotate();
	void zoom();
	void updat();
public:
	void run();
	Menu(GeomCompos* G, Visitor* V);

	
};
