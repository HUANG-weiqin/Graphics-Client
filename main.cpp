#include <winsock2.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include "Erreur.h"
#include "Client.h"
#include "TCP_visitor.h"
#include <vector>
#include "Menu.h"
using namespace std;

int main()
{
	try
	{
		GeomCompos g;
		TCP_visitor tcpv;
		Menu m(&g, &tcpv);
		m.run();
	}
	catch (Erreur erreur)
	{
		cerr << erreur << endl;
	}



	return 0;

}