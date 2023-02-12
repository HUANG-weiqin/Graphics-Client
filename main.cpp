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

int main()
{
	try
	{
		GeomCircle *c1 = new GeomCircle(120, 120, 50);
		GeomCircle *c2 = new GeomCircle(220, 120, 50);
		GeomLine* c3 = new GeomLine(120, 120, 220,120);

		vector<int> v({ 50,50,  100,100,  50,100,  100,50});
		GeomPolygone* c4 = new GeomPolygone(v);

		GeomCompos gc;
		gc.add(c1);
		gc.add(c2);
		gc.add(c3);
		gc.add(c4);

		TCP_visitor tcpv;
		gc.accept(&tcpv);
		
		Client::GetInstance()->DisConnect();
		
	}
	catch (Erreur erreur)
	{
		cerr << erreur << endl;
	}



	return 0;

}