#include <winsock2.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include "Erreur.h"
#include "Client.h"
#include "TCP_visitor.h"
#include <vector>
using namespace std;

void printSurface(Geometric & g) {
	cout << "the surface of this Geometric is : " << g.surface() << endl;
}

int main()
{
	try
	{
		GeomCircle *c1 = new GeomCircle(120, 120, 50);
		GeomCircle *c2 = new GeomCircle(220, 120, 50);
		GeomLine* c3 = new GeomLine(120, 120, 220,120);

		vector<int> v({ 50,50,  50,100,  100,100,  100,50, 75,0});
		GeomPolygone* c4 = new GeomPolygone(v);
		

		Point pivot(120, 120);
		

		GeomCompos gc;
		gc.add(c1);
		gc.add(c2);
		gc.add(c3);
		gc.add(c4);
		//gc.rotateBy(&pivot, 0.5);
		//Vector2d move(50, 100);
		//gc.moveBy(move);

		TCP_visitor tcpv;
		gc.accept(&tcpv);
		Client::GetInstance()->SaveGraphics();
		Client::GetInstance()->DisConnect();
		printSurface(gc);
	}
	catch (Erreur erreur)
	{
		cerr << erreur << endl;
	}



	return 0;

}